#include "push_swap.h"

void    sa_sb(t_stack *stack, int ab)
{
    t_elem  *temp;

    if (!(stack->top) || (stack->top && !(stack->top->prev)))
        return ;
    temp = stack->top->prev;
    stack->top->next = temp;
    stack->top->prev = temp->prev;
    if (!stack->top->prev)
        stack->bottom = stack->top;
    temp->prev = stack->top;
    temp->next = 0;
    stack->top = temp;
    if (ab == 'a')
        write(1, "sa\n",3);
    else if (ab == 'b')
        write(1, "sb\n",3);
    else if (ab == 't')
        write(1, "ss\n", 3);
}

void    ss(t_stack *stack1, t_stack *stack2)
{
    sa_sb(stack1, 0);
    sa_sb(stack2, 't');

}

void    push_oper_size1(t_stack *ss, t_stack *ds)
{
    if (!ds->top && !ds->bottom)
    {
        ds->top = ss->top;
        ds->bottom = ss->top;
    }
    else
    {
        ss->top->prev = ds->top;
        ds->top->next= ss->top;
        ds->top = ss->top;
    }
    ss->top = 0;
    ss->bottom = 0;
}

void    push_oper(t_stack *ss, t_stack *ds)
{
    if (!ss->top)
        return ;
    if (ss->top && !ss->top->prev)
        push_oper_size1(ss, ds);
    else
    {
        if (!ds->top && !ds->bottom)
        {
            ds->top = ss->top;
            ds->bottom = ss->top;
            ss->top = ss->top->prev;
            ss->top->next =0;
            ds->top->prev = 0;
        }
        else
        {
            ds->top->next = ss->top;
            ss->top = ss->top->prev;
            ss->top->next = 0;
            ds->top->next->prev = ds->top;
            ds->top = ds->top->next;
        }
    }
}

void    pa_pb(t_stack *ss, t_stack *ds, int ab)
{
    push_oper(ss, ds);
    if (ab == 'a')
        write(1, "pa\n",3);
    else if (ab == 'b')
        write(1, "pb\n",3);
    ss->size--;
    ds->size++;
}