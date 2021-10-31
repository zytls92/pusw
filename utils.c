#include "push_swap.h"

int ft_strlen(char *s)
{
    int idx;
    int res;

    idx = -1;
    res = 0;
    if (!s)
        return (0);
    while (s[++idx])
        res++;
    return (res);
}

int doarr_len(char **arry)
{
    int res;
    int idx;

    idx = -1;
    res = 0;
    if (!arry)
        return (0);
    while (arry[++idx])
        res++;
    return (res);
}
