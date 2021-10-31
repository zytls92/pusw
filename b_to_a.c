#include "push_swap.h"

void	rot_push_a(t_stack *a, t_stack *b, t_value *var)
{
	if (b->top->value <= var->s_pi)
	{
		ra_rb(b, 'b');
		var->rb_cnt++;
	}
	else
	{
		pa_pb(b, a, 'a');
		var->pa_cnt++;
		if (a->top->value <= var->b_pi)
		{
			ra_rb(a, 'a');
			var->ra_cnt++;
		}
	}
}

void	b_a_roll_a(t_stack *a, t_stack *b, t_value *var)
{
	int	rr;
	int	rem;

	rr = var->rb_cnt;
	rem = var->ra_cnt - rr;
	while (rr--)
		rrr(a, b);
	while (rem--)
		rra_rrb(a, 'a');
}

void	b_a_roll_b(t_stack *a, t_stack *b, t_value *var)
{
	int	rr;
	int	rem;

	rr = var->ra_cnt;
	rem = var->rb_cnt - rr;
	while (rr--)
		rrr(a, b);
	while (rem--)
		rra_rrb(b, 'b');
}

void		b_to_a(int size, t_stack *a, t_stack *b, int *cnt)
{
	int		tmp;
	t_value	var;

	tmp = size;
	(*cnt)++;
	if (!exceptional_cases(size, a, b, 'b'))
		return ;
	init_value(&var);
	select_pivot(size, b, &var);
	tmp = size;
	while (tmp--)
		rot_push_a(a, b, &var);
	a_to_b(var.pa_cnt - var.ra_cnt, a, b, cnt);
	if (var.ra_cnt > var.rb_cnt)
		b_a_roll_a(a, b, &var);
	else
		b_a_roll_b(a, b, &var);
	a_to_b(var.ra_cnt, a, b, cnt);
	b_to_a(var.rb_cnt, a, b, cnt);
}
