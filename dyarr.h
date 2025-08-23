
#ifndef __DYARR_H__
#define __DYARR_H__

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    typedef struct
    {
        size_t length;
        size_t capacity;
    } __arr_header;

#define arrheader(arr) ((__arr_header *)(arr) - 1)
#define arrlen(arr) arrheader(arr)->length
#define arrcap(arr) arrheader(arr)->capacity

    void *__arrgrow(void *arr, size_t elm_size, size_t add_len)
    {
        void *new_arr;
        size_t min_len = (arr ? arrlen(arr) : 0) + add_len;
        size_t cur_cap = arr ? arrcap(arr) : 0;

        if (min_len <= cur_cap)
        {
            return arr;
        }

        if (min_len < 2 * cur_cap)
        {
            min_len = 2 * cur_cap;
        }
        else if (min_len < 4)
        {
            min_len = 4;
        }

        new_arr = realloc(arr ? arrheader(arr) : NULL,
                          sizeof(__arr_header) + elm_size * min_len);
        new_arr = (char *)new_arr + sizeof(__arr_header);
        __arr_header *new_header = arrheader(new_arr);

        if (arr == NULL)
        {
            new_header->length = 0;
        }
        new_header->capacity = min_len;
        return new_arr;
    }

#define arrfree(arr)              \
    do                            \
    {                             \
        if (arr)                  \
        {                         \
            free(arrheader(arr)); \
            arr = NULL;           \
        }                         \
    } while (0)

#define __arrpush(arr, val)                                                  \
    do                                                                       \
    {                                                                        \
        if (!(arr) || arrheader(arr)->length + 1 > arrheader(arr)->capacity) \
        {                                                                    \
            arr = __arrgrow(arr, sizeof *(arr), 1);                          \
        }                                                                    \
        arr[arrheader(arr)->length++] = (val);                               \
    } while (0)

#define arrpush(arr, ...)                                        \
    do                                                           \
    {                                                            \
        typeof(*arr) vals[] = {__VA_ARGS__};                       \
        for (size_t i = 0; i < sizeof(vals) / sizeof(*arr); i++) \
        {                                                        \
            __arrpush(arr, vals[i]);                             \
        }                                                        \
    } while (0)

#define arrpop(arr) (arrlen(arr)--, (arr)[arrlen(arr)])

#define arrdel(arr, i)                                                   \
    do                                                                   \
    {                                                                    \
        if (arr)                                                         \
        {                                                                \
            memmove(&(arr)[(i)], &(arr)[(i) + 1],                        \
                    sizeof *(arr) * (arrheader(arr)->length - (i) - 1)); \
            arrheader(arr)->length--;                                    \
        }                                                                \
    } while (0)

#define arrinsert(arr, i, val)                                               \
    do                                                                       \
    {                                                                        \
        if (!(arr) || arrheader(arr)->length + 1 > arrheader(arr)->capacity) \
        {                                                                    \
            arr = __arrgrow(arr, sizeof *(arr), 1);                          \
        }                                                                    \
        memmove(&(arr)[(i) + 1], &(arr)[(i)],                                \
                sizeof *(arr) * (arrheader(arr)->length - (i)));             \
        arr[i] = (val);                                                      \
        arrheader(arr)->length++;                                            \
    } while (0)

#define arrget(arr, i) ((arr)[(i)])
#define arrback(arr) ((arr)[arrlen(arr) - 1])
#define arrfront(arr) ((arr)[0])


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __DYARR_H__