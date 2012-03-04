/* 
 * File:   string.h
 * Author: sbidny
 *
 * Created on April 5, 2011, 5:59 PM
 */

#ifndef STRING_H
#define	STRING_H

#include <string.h>

size_t strlen2(const char *str) {
    if (str == NULL) {
        return 0;
    }

    return strlen(str);
}

char *strmove(char *dest, const char *src) {
#if defined(DEBUG_PLUS)
    assert(!(dest == NULL || src == NULL));
#endif

    if (dest == NULL || src == NULL) {
        return dest;
    }

    return cmemmove(dest, src, strlen2(src) + 1);
}

char *strnmove(char *dest, const char *src, size_t n) {
#if defined(DEBUG_PLUS)
    assert(!(strlen2(src) >= n || dest == NULL || src == NULL || n <= 0));
#endif

    if (dest == NULL || src == NULL || n <= 0) {
        return dest;
    }

    return cmemmove(dest, src, MIN(n, strlen2(src) + 1));
}

char *strnmove2(char *dest, const char *src, size_t n) {
#if defined(DEBUG_PLUS)
    assert(!(strlen2(src) >= n || dest == NULL || src == NULL || n <= 0));
#endif

    if (dest == NULL || src == NULL || n <= 0) {
        return dest;
    }

    // NULL terminate last char no matter what
    dest[n - 1] = '\0';

    return strnmove(dest, src, n - 1);
}

char *strleat(char *str, const char *eat) {
    char *ptr = NULL;

    if (str == NULL || strlen2(str) <= 0 || eat == NULL || strlen2(eat) <= 0) {
        return NULL;
    }

    for (ptr = str; strchr(eat, *ptr) != NULL; ptr++);

    return strmove(str, ptr);
}

char *strreat(char *str, const char *eat) {
    size_t len = strlen2(str);
    char *ptr = NULL;

    if (str == NULL || len <= 0 || eat == NULL || strlen2(eat) <= 0) {
        return NULL;
    }

    // Walk backwards until we hit non white space
    for (ptr = &(str[len]) - 1; strchr(eat, *ptr) != NULL; ptr--) {
        *ptr = '\0';
    }

    return str;
}

char *streat(char *str, const char *eat) {
    strleat(str, eat);

    return strreat(str, eat);
}

char *strltrim(char *str) {
    return strleat(str, " \t");
}

char *strrtrim(char *str) {
    return strreat(str, " \t");
}

char *strtrim(char *str) {
    return streat(str, " \t");
}

char *strrem(char *str, const char *rem) {
    char *ptr = NULL;

    if (str == NULL || strlen2(rem) <= 0 || strlen2(str) <= 0 || rem == NULL) {
        return NULL;
    }

    for (ptr = str; *ptr != '\0'; ptr++) {
        if (strchr(rem, *ptr) != NULL) {
            strmove(ptr, ptr + 1);
            ptr--;
        }
    }

    return str;
}

char *strdel(char *str, size_t pos, size_t num) {
    size_t len = strlen2(str);

    if (str == NULL || len <= 0 || pos >= len || pos < 0 || num <= 0) {
        return NULL;
    }

    if ((pos + num) > len) {
        num = len - pos;
    }

    strmove(str + pos, str + pos + num);

    return str;
}

char *substr(char *str, size_t pos, size_t num) {
    size_t len = strlen2(str);

    if (str == NULL || len <= 0 || pos >= len || pos < 0 || num <= 0) {
        return NULL;
    }

    if ((pos + num) > len) {
        num = len - pos;
    }

    strmove(str, str + pos);
    str[num] = '\0';

    return str;
}

char *strins(char *dest, const char *src, size_t pos) {
    size_t srcLen = strlen2(src);
    size_t destLen = strlen2(dest);

    if (dest == NULL || src == NULL || pos < 0 || srcLen <= 0
            || pos > destLen) {
        return NULL;
    }

    memmove(dest + pos + srcLen, dest + pos, strlen2(dest) - pos + 1);
    memcpy(dest + pos, src, srcLen);

    return dest;
}

char *strnins(char *dest, const char *src, size_t pos, size_t num) {
    // TODO: Implement

    return NULL;
}

char *strkeep(char *str, const char *keep) {
    char *ptr = NULL;

    if (str == NULL || strlen2(keep) <= 0 || strlen2(str) <= 0
            || keep == NULL) {
        return NULL;
    }

    for (ptr = str; *ptr != '\0'; ptr++) {
        if (strchr(keep, *ptr) == NULL) {
            strmove(ptr, ptr + 1);
            ptr--;
        }
    }

    return str;
}

char *strlcclip(char *str, const char *clip, bool keep) {
    char *ptr = NULL;

    if (str == NULL || clip == NULL || strlen2(str) <= 0
            || strlen2(clip) <= 0) {
        return NULL;
    }

    if ((ptr = strpbrk(str, clip)) == NULL) {
        return NULL;
    }

    return strmove(str, ptr + ((keep) ? 0 : 1));
}

char *strrcclip(char *str, const char *clip, bool keep) {
    size_t i = 0;
    char *ptr = NULL;

    if (str == NULL || clip == NULL || strlen2(str) <= 0
            || strlen2(clip) <= 0) {
        return NULL;
    }

    for (i = 0; i < strlen2(clip); i++) {
        ptr = MAX(ptr, strrchr(str, clip[i]));
    }

    if (ptr == NULL) {
        return NULL;
    }

    *(ptr + ((keep) ? 1 : 0)) = '\0';

    return str;
}

char *strcclip(char *str, const char *clip, bool keep) {
    strlcclip(str, clip, keep);

    return strrcclip(str, clip, keep);
}

char *strlsclip(char *str, const char *clip, bool keep) {
    char *ptr = NULL;

    if (str == NULL || clip == NULL || strlen2(str) <= 0
            || strlen2(clip) <= 0) {
        return NULL;
    }

    if ((ptr = strstr(str, clip)) == NULL) {
        return NULL;
    }

    return strmove(str, ptr + ((keep) ? 0 : strlen2(clip)));
}

char *strrsclip(char *str, const char *clip, bool keep) {
    // TODO: Implement

    return NULL;
}

char *strsclip(char *str, const char *clip, bool keep) {
    strlsclip(str, clip, keep);

    return strrsclip(str, clip, keep);
}

char *strlast(char *str) {
    return strterm(str) - 1;
}

char *strterm(char *str) {
    return (str + strlen2(str));
}

char *strlccut(char *str, const char *cut, bool keep) {
    char *ptr = NULL;

    if (str == NULL || cut == NULL || strlen2(str) <= 0 || strlen2(cut) <= 0) {
        return NULL;
    }

    if ((ptr = strpbrk(str, cut)) == NULL) {
        return NULL;
    }

    *(ptr + ((keep) ? 1 : 0)) = '\0';

    return str;
}

char *strlscut(char *str, const char *cut, bool keep) {
    char *ptr = NULL;

    if (str == NULL || cut == NULL || strlen2(str) <= 0 || strlen2(cut) <= 0) {
        return NULL;
    }

    if ((ptr = strstr(str, cut)) == NULL) {
        return NULL;
    }

    *(ptr + ((keep) ? strlen2(cut) : 0)) = '\0';

    return str;
}

char *strrccut(char *str, const char *cut, bool keep) {
    size_t i = 0;
    char *ptr = NULL;

    if (str == NULL || cut == NULL || strlen2(str) <= 0 || strlen2(cut) <= 0) {
        return NULL;
    }

    for (i = 0; i < strlen2(cut); i++) {
        ptr = MAX(ptr, strrchr(str, cut[i]));
    }

    if (ptr == NULL) {
        return NULL;
    }

    return strmove(str, ptr + ((keep) ? 0 : 1));
}

char *strrscut(char *str, const char *cut, bool keep) {
    // TODO: Implement

    return NULL;
}

char *strscut(char *str, const char *cut, bool keep) {
    strlscut(str, cut, keep);

    return strrscut(str, cut, keep);
}

char *strccut(char *str, const char *cut, bool keep) {
    strlccut(str, cut, keep);

    return strrccut(str, cut, keep);
}

char *strlcat(char *dest, const char *src) {
    return strins(dest, src, 0);
}

char *strnlcat(char *dest, const char *src, size_t num) {
    return strnins(dest, src, 0, num);
}

char *strsfill(char *dest, const char *src) {
    size_t i;
    size_t len = strlen2(src);

    if (src == NULL || dest == NULL || len <= 0) {
        return NULL;
    }

    for (i = 0; i < strlen(dest); i++) {
        dest[i] = src[i % len];
    }

    return dest;
}

char *strcfill(char *dest, char src) {
    if (dest == NULL) {
        return NULL;
    }

    return cmemset(dest, src, strlen2(dest));
}

char *strnull(char *dest) {
    return strcfill(dest, '\0');
}

char *strtolower(char *str) {
    for (size_t i = 0; i < strlen2(str); ++i) {
        str[i] = tolower(str[i]);
    }

    return str;
}

char *strtoupper(char *str) {
    for (size_t i = 0; i < strlen2(str); ++i) {
        str[i] = toupper(str[i]);
    }

    return str;
}

char *strntolower(char *str, size_t num) {
    for (size_t i = 0; i < MIN(num, strlen2(str)); ++i) {
        str[i] = tolower(str[i]);
    }

    return str;
}

char *strntoupper(char *str, size_t num) {
    for (size_t i = 0; i < MIN(num, strlen2(str)); ++i) {
        str[i] = toupper(str[i]);
    }

    return str;
}

char *strrev(char *str) {
    size_t len = strlen2(str);

    if (len == 0) {
        return str;
    }

    for (size_t i = 0; i < (len / 2); ++i) {
        *(str + len) = *(str + i); /* Use NULL for temp storage */
        *(str + i) = *(str + len - i - 1);
        *(str + len - i - 1) = *(str + len);
    }

    *(str + len) = '\0';

    return str;
}

char *strncpy2(char *dest, const char *src, size_t num) {
#if defined(DEBUG_PLUS)
    assert(!(strlen2(src) >= num || dest == NULL || src == NULL || num <= 0));
#endif

    if (dest == NULL || src == NULL || num <= 0) {
        return dest;
    }

    // NULL terminate last char no matter what
    dest[num - 1] = '\0';

    return strncpy(dest, src, num - 1);
}

char *strncat2(char *dest, const char *src, size_t num) {
    size_t len = strlen2(dest);

#if defined(DEBUG_PLUS)
    assert(!(dest == NULL || src == NULL || (len + 1) >= num || num <= 0));
#endif

    if (dest == NULL || src == NULL || (len + 1) >= num || num <= 0) {
        return dest;
    }

    return strncat(dest, src, num - len - 1);
}

#endif	/* STRING_H */

