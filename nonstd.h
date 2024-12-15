#ifndef NONSTD_H
#define NONSTD_H

#include <stdint.h>
#include <time.h>

#define null NULL
#define KB 1024
#define MB KB*KB
#define GB KB*KB*KB

#define eval(x) time_t start = clock();\
    x;\
    time_t end = clock();\
    printf("Time elapsed: %d micros.\n", (end - start));

typedef int8_t I8;
typedef int16_t I16;
typedef int32_t I32;
typedef int64_t I64;
typedef uint8_t U8;
typedef uint16_t U16;
typedef uint32_t U32;
typedef uint64_t U64;
typedef float F32;
typedef double F64;

#endif