#include "push_swap.h"

int	exceptional_cases(int size, t_stack *a, t_stack *b, int ab)
{
	if (size <= 3)
	{
		handle_under_three(size, a, b, ab);
		return (0);
	}
	else if (size == 5)
	{
		hanlde_sort_five(5, a, b, ab);
		return (0);
	}
	else
		return (1);
}

void	sort_five_a(int size, t_stack *a, t_stack *b)
{
	int	mid;
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	mid = get_mid(a->top);
	while (size--)
	{
		if (a->top->value < mid)
		{
			pa_pb(a, b, 'b');
			push++;
		}
		else
		{
			ra_rb(a, 'a');
			rotate++;
		}
		if (push == 2)
			break ;
	}
	while (rotate--)
		rra_rrb(a, 'a');
}

void	sort_five_b(int size, t_stack *a, t_stack *b)
{
	int	mid;
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	mid = get_mid(b->top);
	while (size--)
	{
		if (b->top->value >= mid)
		{
			pa_pb(b, a, 'a');
			push++;
		}
		else
		{
			ra_rb(b, 'b');
			rotate++;
		}
		if (push == 3)
			break ;
	}
	while (rotate--)
		rra_rrb(b, 'b');
}

void		hanlde_sort_five(int size, t_stack *a, t_stack *b, int flag)
{
	if (flag == 'a')
		sort_five_a(size, a, b);
	else
		sort_five_b(size, a, b);
	only_three_elem(a,'a',a->size);
	two_elem(a, b, 'b');
}


void	handle_under_three(int size, t_stack *a, t_stack *b, int ab)
{
	if (size == 3)
	{
		if (ab == 'a')
			three_elem(a, b,'a', size);
		else
			three_elem(a, b, 'b', size);
	}
	else if (size == 2)
		two_elem(a, b, ab);
	else if (size == 1)
	{
		if (ab == 'b')
			pa_pb(b, a, 'a');
	}
}