#include "push_swap.h"

void    minmax(t_stack *stack, int *max, int *min, int size)
{
    t_elem *tmp;
    int mx;
    int mn;
    int value;

    tmp = stack->top;
    mx = tmp->value;
    mn = tmp->value;
    tmp = tmp->prev;
    while (--size)
    {
        value = tmp->value;
        if (value > mx)
            mx = tmp->value;
        if (value < mn)
            mn = tmp->value;
        tmp = tmp->prev;
    }
    *max = mx;
    *min = mn;  
}