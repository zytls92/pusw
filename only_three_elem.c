#include "push_swap.h"

void    two_elem(t_stack *a, t_stack *b, int ab)
{
    if (ab == 'a')
    {
        if (a->top->value > a->bottom->value)
            sa_sb(a, 'a');
    }
    else
    {
        if (b->top->value < b->bottom->value)
            sa_sb(b, 'b');
    }
    if (ab == 'b')
    {
        pa_pb(b,a,'a');
        pa_pb(b,a,'a');
    }
}

void    top_max(t_stack *stack, int ab, int min, int max)
{
    t_elem *tmp;

    tmp = stack->top;
    if (tmp->prev->value == min)
    {
        if (ab == 'a')
            ra_rb(stack, 'a');
        else
        {
            rra_rrb(stack, 'b');
            sa_sb(stack, 'b');
        }
    }
    else
    {
        if (ab == 'a')
        {
            ra_rb(stack, 'a');
            sa_sb(stack, 'a');
        }
    }
}

void    top_min(t_stack *stack, int ab, int min, int max)
{
    t_elem *tmp;

    tmp = stack->top;
    if (tmp->prev->value == max)
    {
        if (ab == 'a')
        {
            rra_rrb(stack, 'a');
            sa_sb(stack, 'a');
        }
        else
            ra_rb(stack, 'b');
    }
}

void    top_mid(t_stack *stack, int ab, int min, int max)
{
    t_elem *tmp;

    tmp = stack->top;
    if (tmp->prev->value == min)
    {
        if (ab == 'a')
            sa_sb(stack, 'a');
        else
            rra_rrb(stack, 'b');
    }
    else
    {
        if (ab == 'a')
            rra_rrb(stack, 'a');
        else
            sa_sb(stack, 'b');
    }
}

void    only_three_elem(t_stack *stack, int ab, int size)
{
    int min;
    int max;
    t_elem *tmp;

    tmp = stack->top;
    minmax(stack, &max, &min, size);
    if (tmp->value == max)
        top_max(stack, ab, min, max);
    else if (tmp->value == min)
        top_min(stack, ab, min, max);
    else
        top_mid(stack, ab, min, max);
}
