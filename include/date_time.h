/* 
 * File:   date_time.h
 * Author: sbidny
 *
 * Created on April 5, 2011, 6:03 PM
 */

#ifndef DATE_TIME_H
#define	DATE_TIME_H

int systemTimeToTm(
        const SYSTEMTIME *systemTime,
        struct tm *tm)
{
    if (systemTime == NULL || tm == NULL)
        return -1;

    tm->tm_year = systemTime->wYear - 1900;
    tm->tm_mon = systemTime->wMonth - 1;
    tm->tm_mday = systemTime->wDay;
    tm->tm_hour = systemTime->wHour;
    tm->tm_min = systemTime->wMinute;
    tm->tm_sec = systemTime->wSecond;
    tm->tm_wday = systemTime->wDayOfWeek;

    return 0;
}

int tmToSystemTime(
        const struct tm *tm,
        unsigned short ms,
        SYSTEMTIME *systemTime)
{
    if (tm == NULL || systemTime == NULL)
        return -1;

    systemTime->wYear = tm->tm_year + 1900;
    systemTime->wMonth = tm->tm_mon + 1;
    systemTime->wDay = tm->tm_mday;
    systemTime->wHour = tm->tm_hour;
    systemTime->wMinute = tm->tm_min;
    systemTime->wSecond = tm->tm_sec;
    systemTime->wMilliseconds = ms;
    systemTime->wDayOfWeek = tm->tm_wday;

    return 0;
}

int unixTimeToLocalSystemTime(
        time_t time,
        unsigned short ms,
        SYSTEMTIME *systemTime)
{
    struct tm tm;

    if (systemTime == NULL)
        return -1;

    localtime_r(&time, &tm);

    return tmToSystemTime(&tm, ms, systemTime);
}

int unixTimeToUtcSystemTime(
        time_t time,
        unsigned short ms,
        SYSTEMTIME *systemTime)
{
    struct tm tm;

    if (systemTime == NULL)
        return -1;

    gmtime_r(&time, &tm);

    return tmToSystemTime(&tm, ms, systemTime);
}

int unixTimeToFileTime(
        time_t unixTime,
        unsigned short ms,
        unsigned short us,
        unsigned short ns,
        FILETIME *fileTime)
{
    unsigned long long *tmpFT = (unsigned long long*) fileTime;

    /* January 1, 1970 - January 1, 1601 */
    *tmpFT = FILETIME_EPOCH_DELTA;
    *tmpFT += ((unsigned long long) unixTime * FILETIME_PER_SEC) +
            ((unsigned long long) ms * FILETIME_PER_MSEC) +
            ((unsigned long long) us * FILETIME_PER_USEC) +
            ((unsigned long long) ns / NSECS_PER_FILETIME);

    return 0;
}

int timeValToFileTime(const struct timeval *timeVal, FILETIME *fileTime)
{
    unsigned long long *tmpFT = (unsigned long long*) fileTime;

    /* January 1, 1970 - January 1, 1601 */
    *tmpFT = FILETIME_EPOCH_DELTA;
    *tmpFT += ((unsigned long long) timeVal->tv_sec * FILETIME_PER_SEC) +
            ((unsigned long long) timeVal->tv_usec * FILETIME_PER_USEC);

    return 0;
}

int fileTimeToTimeVal(const FILETIME *fileTime, struct timeval *timeVal)
{
    unsigned long long tmpFT = 0;

    if (fileTime == NULL || timeVal == NULL) return -1;

    tmpFT = *((unsigned long long*) fileTime);

    /* Converting file time to unix epoch */
    tmpFT -= FILETIME_EPOCH_DELTA;
    timeVal->tv_sec = (long) (tmpFT / FILETIME_PER_SEC);
    timeVal->tv_usec = (long) ((tmpFT % FILETIME_PER_SEC) / FILETIME_PER_USEC);

    return 0;
}

int fileTimeToTimeSpec(const FILETIME *fileTime, struct timespec *timeSpec)
{
    unsigned long long tmpFT = 0;

    if (fileTime == NULL || timeSpec == NULL) return -1;

    tmpFT = *((unsigned long long*) fileTime);

    /* Converting file time to unix epoch */
    tmpFT -= FILETIME_EPOCH_DELTA;
    timeSpec->tv_sec = (long) (tmpFT / FILETIME_PER_SEC);
    timeSpec->tv_nsec =
            (long) ((tmpFT % FILETIME_PER_SEC) * NSECS_PER_FILETIME);

    return 0;
}

time_t timegm(struct tm *tm)
{
    return (daysSince1970(tm) * SECS_PER_DAY + tm->tm_hour * SECS_PER_HOUR +
            tm->tm_min * SECS_PER_MIN + tm->tm_sec);
}

bool isLeapYear(unsigned int year)
{
    return (!(year % 4) && ((year % 100) || !(year % 400)));
}

unsigned char daysInMonth(unsigned char month)
{
    unsigned char daysMap[] =
            { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return daysMap[month];
}

time_t todaytime(time_t *t)
{
    time_t timep = 0;
    struct tm tm;

    today(&tm);
    timep = mktime(&tm);

    if (t) *t = timep;

    return timep;
}

struct tm *now(struct tm *tm)
{
    // Get the current time
    time_t t = gettime(NULL);
    localtime_r(&t, tm);

	// Return the local time
    return tm;
}

struct tm *today(struct tm *tm)
{
    /* Get the local time */
    now(tm);

    /* Set the time to midnight */
    return midnight(tm);
}

struct tm *midnight(struct tm *tm)
{
    /* Set the time to midnight */

    tm->tm_sec = 0;
    tm->tm_min = 0;
    tm->tm_hour = 0;

    return tm;
};

int timeofday(struct timeval *tv) { return gettimeofday(tv, NULL); }

time_t gettime(time_t *t)
{
    struct timeval timeVal;
    timeofday(&timeVal);
    if (t) *t = timeVal.tv_sec;
    return timeVal.tv_sec;
}

int64_t timevalDiff(struct timeval *first, struct timeval *second)
{
    if (first == NULL || second == NULL)
        return 0;

    return (first->tv_sec - second->tv_sec) * USECS_PER_SEC +
            first->tv_usec - second->tv_usec;
}

struct tm *gmnow(struct tm *tm)
{
    // Get the current time
    time_t t = gettime(NULL);
    gmtime_r(&t, tm);

    // Return the local time
    return tm;
}

struct tm *gmtoday(struct tm *tm)
{
    // Get the local time
    gmnow(tm);

    // Set the time to midnight
    tm->tm_sec = 0;
    tm->tm_min = 0;
    tm->tm_hour = 0;
    return tm;
}

size_t strfnow(char *str, size_t num, const char *format)
{
    struct tm tm;

    return strftime(str, num, format, now(&tm));
}

size_t strfgmnow(char *str, size_t num, const char *format)
{
    struct tm tm;

    return strftime(str, num, format, gmnow(&tm));
}

int getMilliseconds()
{
    SYSTEMTIME localTime;
    GetLocalTime(&localTime);
    return (localTime.wHour * MSECS_PER_HOUR + localTime.wMinute * MSECS_PER_MIN
            + localTime.wSecond * MSECS_PER_SEC + localTime.wMilliseconds);
}

// Converts Military Time str "HH:MM:SS", "HH:MM" to milliseconds since midnight
int ConvertTimeStrToMillisecs(const char* tzTime)
{
    char* szHH, *szMM, *szSS, *szStop;
    char szTime[50];
    int result;

    strncpy2(szTime, tzTime, sizeof(szTime));
    int hour = 0;
    int min = 0;
    int sec = 0;

    if (strlen(szTime) == 0)
    {
        return 0;
    }

    szHH = szTime;

    hour = strtol(szHH, &szStop, 10);

    if (szStop - szTime == 0 || (*szStop != ':' && *szStop != 0))
    {
        return 0;
    }


    if (*szStop == ':')
    {
        szMM = szStop + 1;
        min = strtol(szMM, &szStop, 10);
    }
    else
    {
        result = hour * 3600000L;
        return result;
    }

    if (szStop - szMM == 0 || (*szStop != ':' && *szStop != 0))
    {
        return 0;
    }

    if (*szStop == ':')
    {
        szSS = szStop + 1;
        sec = strtol(szSS, &szStop, 10);
    }
    else
    {
        result = hour * 3600000L + min * 60000L;
        return result;
    }

    if (szStop - szSS == 0 || (*szStop != 0))
    {
        return 0;
    }

    result = hour * 3600000L + min * 60000L + sec * 1000;
    return result;
}

time_t normalizeLocalTm(struct tm *tm)
{
    time_t time;

    if (!tm || (time = mktime(tm)) == (time_t) -1)
        return (time_t) -1;

    localtime_r(&time, tm);

    return time;
}

time_t normalizeUtcTm(struct tm *tm)
{
    time_t time;

    if (!tm || (time = timegm(tm)) == (time_t) -1)
        return (time_t) -1;

    gmtime_r(&time, tm);

    return time;
}

int DaysSince1970()
{
    struct tm currTime;

    now(&currTime);

    return daysSince1970(&currTime);
}

int daysSince1970(struct tm *tm)
{
    struct tm time = *tm;
    int rv = 0;
    int currDays = 0;
    int currYear = 0;
    int year = 1970;

    midnight(&time);
    normalizeLocalTm(&time);

    currDays = tm->tm_yday;
    currYear = TM_START_YEAR + tm->tm_year;

    // Calculate days since January 1, 1970

    for (year = 1970; year <= currYear - 1; year++)
    {
        if (isLeapYear(year)) rv += DAYS_PER_LEAP_YEAR;
        else rv += DAYS_PER_STD_YEAR;
    }

    return (rv += currDays);
}

int SecSinceMidnight()
{
    return getMilliseconds() / MSECS_PER_SEC;
}

float minsSinceMidnight()
{
    return (float) getMilliseconds() / (float) MSECS_PER_MIN;
}

float hoursSinceMidnight()
{
    return (float) getMilliseconds() / (float) MSECS_PER_HOUR;
}

#endif	/* DATE_TIME_H */

