#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_elem	*elem;
	t_elem	*pre;

	elem = stack->top;
	while (elem)
	{
		if (elem->prev)
			pre = elem->prev;
		else
			pre = NULL;
		free(elem);
		if (pre)
			elem = pre;
		else
			break ;
	}
	free(stack);
}

void free_all(t_stack *a, t_stack *b)
{   
    free_stack(a);
    free_stack(b);
}

