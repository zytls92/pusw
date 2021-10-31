#include "push_swap.h"

t_stack *empty_stack()
{
    t_stack *res;
    res = (t_stack *)malloc(sizeof(t_stack));
    if (!res)
        return (0);
    res->bottom = 0;
    res->top = 0;
    res->size = 0;
    return (res);
}

t_elem  *get_elem(char *argument)
{
    t_elem  *res;
    res = (t_elem *)malloc(sizeof(t_elem));
    if (!res)
        return (0);
    res->prev = 0;
    res->next = 0;
    res->value = ft_atoi(argument);
    return (res);
}

int    fill_elem(t_elem *elem, t_stack *stack)
{
    t_elem  *temp;

    temp = stack->top;
    if (!stack->top && !stack->bottom)
        {
            elem->next = 0;
            elem->prev = 0;
            stack->top = elem;
            stack->bottom = elem;
        }
    else
    {
        while (temp)
        {
            if (temp->value == elem->value)
                return (1);
            temp = temp->prev;
        }
        (stack->bottom)->prev = elem;
        elem->next = stack->bottom;
        stack->bottom = elem;
        elem->prev = 0;
    }
    stack->size++;
    return (0);
}

int     split_argv(char *argument, t_stack *stack)
{
     char    **temp;
    int i;
    t_elem  *elem;
    int err;

    i = -1;

    temp = ft_split(argument, ' ');
    if (!temp || !*temp)
        return (1);
    while (temp[++i])
    {
        elem = get_elem(temp[i]);
        err = fill_elem(elem, stack);
        free(temp[i]);
        if (err)
        {
            free(elem);
            free(temp);
            return (1);
        }
    }
    free(temp);
    return (0);
}

int     fill_stack(int argc, char **argv, t_stack *stack)
{
    int idx;
    int temp;

    idx = 0;
    while (++idx < argc)
    {
        temp = split_argv(argv[idx], stack);
        if (temp == 1)
            return (1);
    }
    return (0);
}