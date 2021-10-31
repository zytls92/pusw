#include "push_swap.h"

int	sort_values(int value[])
{
	int	i;
	int	j;
	int	tmp;

	i = 5;
	while (--i > 0)
	{
		j = -1;
		while (++j < i)
		{
			if (value[j] > value[j + 1])
			{
				tmp = value[j + 1];
				value[j + 1] = value[j];
				value[j] = tmp;
			}
		}
	}
	return (value[2]);
}

int			get_mid(t_elem *elem)
{
	int	i;
	int	value[5];

	i = -1;
	while (++i < 5)
	{
		value[i] = elem->value;
		if (elem->prev)
			elem = elem->prev;
		else
			break ;
	}
	while (elem->next)
	    elem = elem->next;
	return (sort_values(value));
}

void		only_five_elem(t_stack *a, t_stack *b)
{
	int	pb;
	int	mid;

	pb = 0;
	mid = get_mid(a->top);
	while (1)
	{
		if (a->top->value < mid)
		{
			pa_pb(a, b, 'b');
			pb++;
		}
		else
			ra_rb(a, 'a');
		if (pb == 2)
			break ;
	}
	only_three_elem(a,'a',a->size);
	two_elem(a, b, 'b');
}