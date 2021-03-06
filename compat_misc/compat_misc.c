/*
 * This file defines various functions and constants that are not properly defined in RIOT yet
 * TODO: move those functions and defines to their appropriate place in RIOT
 */

#include "compat_misc.h"

/* since we don't have virtual memory, this is rather arbitrary
 * but since some programs like to allocate multiples of memory
 * pages, we have to keep this a bit on the low end.
 * (e.g. 4k is too wasteful)
 * Should be changed to something more meaningful if RIOT starts
 * supporting a MMU
 */
inline int getpagesize(void) {
	return 512;
}

// dummy implementation, we don't have interface names
inline char* if_indextoname(unsigned int ifindex, char *ifname) {
	ifname[0] = 'i';
	ifname[1] = 'f';
	ifname[2] = ifindex + '0';
	ifname[3] = 0;

	return ifname;
}

inline unsigned int if_nametoindex(const char *ifname) {
	return 1; // since we don't have interfaces…
}