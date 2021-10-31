//ra
//rb
//rr
#include "push_swap.h"

void    ra_rb(t_stack *stack, int ab)
{
    t_elem  *temp;

    if (stack->size == 1)
        return ;
    temp = stack->top->prev;
    stack->bottom->prev = stack->top;
    stack->top->next = stack->bottom;
    stack->bottom = stack->top;
    stack->top = temp;
    stack->top->next = NULL;//이부분
    stack->bottom->prev = NULL;
    if (ab == 'a')
        write(1, "ra\n", 3);
    else if (ab == 'b')
        write(1, "rb\n", 3);
    else if (ab =='t')
        write(1, "rr\n", 3);
}

void    rr(t_stack *stack1, t_stack *stack2)
{
    ra_rb(stack1, 'e');
    ra_rb(stack2, 't');
}

void    rra_rrb(t_stack *stack, int ab)
{
    t_elem  *temp;

    if (stack->size == 1)
        return ;
    temp = stack->bottom->next;
    stack->bottom->prev = stack->top;
    stack->top->next = stack->bottom;
    stack->bottom = temp;
    stack->top = stack->top->next;
    stack->top->next = NULL;
    stack->bottom->prev = NULL;
    if (ab == 'a')
        write(1, "rra\n", 4);
    else if (ab == 'b')
        write(1, "rrb\n", 4);
    else if (ab =='t')
        write(1, "rrr\n", 4);
}

void    rrr(t_stack *stack1, t_stack *stack2)
{
    rra_rrb(stack1, 0);
    rra_rrb(stack2, 't');
}