#ifndef __UTIL_H__
#define __UTIL_H__

#define ITF_CALL(itf, method, ...) (*(itf)).method((*(itf)).p, ##__VA_ARGS__)

#endif
