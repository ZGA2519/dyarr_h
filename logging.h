#ifndef __LOGGING_H__
#define __LOGGING_H__

#include <stdio.h>

#define LOG(msg) fprintf(stdout, "[LOG]: %*s\n", (int)sizeof(msg), msg)
#define ERROR(msg) fprintf(stderr, "[ERROR]: %*s\n", (int)sizeof(msg), msg)
#define WARN(msg) fprintf(stderr, "[WARN]: %*s\n", (int)sizeof(msg), msg)
#define INFO(msg) fprintf(stdout, "[INFO]: %*s\n", (int)sizeof(msg), msg)
#define DEBUG(msg) fprintf(stdout, "[DEBUG]: %*s\n", (int)sizeof(msg), msg)
#define TODO(msg) fprintf(stdout, "[TODO]: %*s\n", (int)sizeof(msg), msg)

#define ASSERT(cond, msg)                    \
    do                                       \
    {                                        \
        if (!(cond))                         \
        {                                    \
            ERROR("Assertion failed: " msg); \
            return -1;                       \
        }                                    \
    } while (0)

#endif // __LOGGING_H__