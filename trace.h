#ifndef TRACE_HEADER
#define TRACE_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <str.h>

#ifdef DEBUG

#define TRACE(...) do{ \
        FILE *f = fopen("trace.log","a"); \
        time_t t;\
        time(&t);\
        fprintf(f,"%.*s " __FILE__ ":" STR(__LINE__) " ( %s ): ",24,ctime(&t),__func__); \
        fprintf(f,"" __VA_ARGS__);\
        fprintf(f,"\n");\
        fclose(f);\
    } while(0)
#else
#define TRACE(...)
#endif

#endif