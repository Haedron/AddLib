/* 
 * File:   net.h
 * Author: sbidny
 *
 * Created on April 5, 2011, 5:59 PM
 */

#ifndef NET_H
#define	NET_H

int getinaddr(const char *hostname, struct in_addr *inAddr)
{
    struct hostent *hp = NULL;

    if (inAddr == NULL) return -1;

    if (hostname == NULL) return getmyinaddr(inAddr);

    hp = gethostbyname(hostname);

    if (hp == NULL) return -2;

    *inAddr = *((struct in_addr*) hp->h_addr);

    return 0;
}

int getmyinaddr(struct in_addr *inAddr)
{
    char hostname[HOST_NAME_MAX] = { '\0' };

    if (inAddr == NULL) return -1;

    if (gethostname(hostname, sizeof (hostname)) == SOCKET_ERROR) return -2;

    return getinaddr(hostname, inAddr);
}

in_addr_t getinaddrt(const char *hostname)
{
    struct in_addr inAddr;

    if (getinaddr(hostname, &inAddr) != 0) return 0;

    return inAddr.s_addr;
}

in_addr_t getmyinaddrt()
{
    struct in_addr inAddr;

    if (getmyinaddr(&inAddr) != 0) return 0;

    return inAddr.s_addr;
}

char *getip(const char *hostname, char *ip, size_t num)
{
    struct in_addr inAddr;

    if (num < 16 || ip == NULL) return NULL;

    if (hostname == NULL) return getmyip(ip, num);

    if (getinaddr(hostname, &inAddr) != 0) return NULL;

    strncpy2(ip, inet_ntoa(inAddr), num);

    return ip;
}

char *getmyip(char *ip, size_t num)
{
    char hostname[HOST_NAME_MAX] = { '\0' };

    if (ip == NULL || num < 16) return NULL;

    if (gethostname(hostname, sizeof (hostname)) == SOCKET_ERROR) return NULL;

    return getip(hostname, ip, num);
}

bool make_sockaddr(
        const char *ip,
        in_port_t port,
        struct sockaddr_in *pAddr)
{
    memset(pAddr, 0, sizeof (struct sockaddr_in));

    pAddr->sin_family = AF_INET;
    pAddr->sin_port = htons(port);

    if (!ip)
    {
        pAddr->sin_addr.s_addr = htonl(INADDR_ANY);
    }
    else if ((pAddr->sin_addr.s_addr = inet_addr(ip)) == INADDR_NONE)
    {
        if (getinaddr(ip, &pAddr->sin_addr) < 0)
            return false;
    }

    return true;
}

int setNonBlocking(SOCKET s)
{
    unsigned long nonblock = 1;
    return ioctlsocket(s, FIONBIO, &nonblock);
}

int setSoLingerSocketOption (SOCKET s, int lingerOnOff, int lingerWaitTime)
{
    linger soLingerValue;
    int sizeOflinger = sizeof (soLingerValue);

    soLingerValue.l_onoff = lingerOnOff;
    soLingerValue.l_linger = lingerWaitTime;

    int n = setsockopt(s, SOL_SOCKET, SO_LINGER, (char*) & soLingerValue,
        sizeOflinger);

    return n;
}

#endif	/* NET_H */

