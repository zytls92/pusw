#include "push_swap.h"

int is_sorted(t_stack *stack, int ab, int size)
{
    t_elem  *tmp;
    int temp;

    tmp = stack->top;
    temp = stack->top->value;
    while (size--)
    {
        if (ab == 'a' && temp > tmp->value)
            return (0);
        if (ab == 'b' && temp < tmp->value)
            return (0);
        tmp = tmp->prev;
        if (tmp)
            temp = tmp->next->value;
    }
    return (1);
}