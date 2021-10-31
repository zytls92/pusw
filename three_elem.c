#include "push_swap.h"

void    three_elem(t_stack *a, t_stack *b, int ab, int size)
{
    if (ab == 'a')
    {
        if (a->size == 3)
            only_three_elem(a, 'a', size);
        else
            over_three_elem(a, b, 'a', size);
    }
    else
    {
        if (b->size == 3)
            only_three_elem(b, 'b', size);
        else
            over_three_elem(a, b,'b', size);
        pa_pb(b, a, 'a');
        pa_pb(b, a, 'a');
        pa_pb(b, a, 'a');
    }
}

void    top_max_no(t_stack *a, t_stack *b, int ab, int min)
{
    if (ab == 'a')
    {
        sa_sb(a,'a');
        ra_rb(a,'a');
        sa_sb(a,'a');
        rra_rrb(a, 'a');
        if (a->top->value != min)
            sa_sb(a,'a');
    }
    else
    {
        if (b->top->prev->value == min)
        {
            ra_rb(b, 'b');
            sa_sb(b, 'b');
            rra_rrb(b,'b');
        }
    }
}

void    top_n_max_no(t_stack *a, t_stack *b, int ab, int min)
{
    if (ab == 'a')
    {
        ra_rb(a,'a');
        sa_sb(a,'a');
        rra_rrb(a, 'a');
        if (a->top->value != min)
            sa_sb(a, 'a');
    }
    else
    {
        sa_sb(b, 'b');
        if (b->top->prev->value == min)
        {
            ra_rb(b, 'b');
            sa_sb(b, 'b');
            rra_rrb(b, 'b');
        }        
    }
}

void    top_n_n_max_no(t_stack *a, t_stack *b, int ab, int min)
{
    if (ab == 'a')
    {
        if (a->top->prev->value == min)
            sa_sb(a,'a');
    }
    else
    {
        if (b->top->value == min)
            sa_sb(b, 'b');
        pa_pb(b, a,'a');
        sa_sb(b, 'b');
        pa_pb(a, b,'b');
        sa_sb(b, 'b');
    }
}

void    over_three_elem(t_stack *a, t_stack *b,int ab, int size)
{
    int min;
    int max;
    t_stack *tmp;

    tmp = a;
    if (ab == 'b')
        tmp = b;
    minmax(tmp, &max, &min, size);
    if (tmp->top->value == max)
        top_max_no(a, b, ab, min);
    else if (tmp->top->prev->value == max)
        top_n_max_no(a, b, ab, min);
    else if (tmp->top->prev->prev->value == max)
        top_n_n_max_no(a, b, ab, min);
}