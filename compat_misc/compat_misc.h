/*
 * This file defines various functions and constants that are not properly defined in RIOT yet
 * TODO: move those functions and defines to their appropriate place in RIOT
 */

#ifndef COMPAT_MISC_H_
#define COMPAT_MISC_H_

// since we only support v6…
#define sockaddr_in		socka6
#define sockaddr_in6		socka6
#define sockaddr		socka6
#define sockaddr_storage	socka6

#define sa_family	sin6_family
#define sin_port	sin6_port
#define sin_addr	sin6_addr

#define htons HTONS
#define htonl HTONL
#define ntohs NTOHS
#define ntohl NTOHL

#define INET_ADDRSTRLEN		(16)
#define INET6_ADDRSTRLEN	(48)

extern int getpagesize(void);

#define IF_NAMESIZE 4
// dummy implementation, we don't have interface names
extern char* if_indextoname(unsigned int ifindex, char *ifname);
extern unsigned int if_nametoindex(const char *ifname);

#endif