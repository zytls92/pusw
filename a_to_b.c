#include "push_swap.h"
//지울거 있음

void	rot_push_b(t_stack *a, t_stack *b, t_value *var)
{
	if (a->top->value > var->b_pi)
	{
		ra_rb(a, 'a');
		var->ra_cnt++;
	}
	else
	{
		pa_pb(a, b, 'b');
		var->pb_cnt++;
		if (b->top->value > var->s_pi)
		{
			ra_rb(b, 'b');
			var->rb_cnt++;
		}
	}
}

void	a_b_roll_b(t_stack *a, t_stack *b, int *cnt, t_value *var)
{
	int	rr;
	int	rem;

	rr = var->ra_cnt;
	rem = var->rb_cnt - rr;
	if ((*cnt) > 0)
	{
		while (rr--)
			rrr(a,b);
		while (rem--)
			rra_rrb(b, 'b');
	}
	else
	{
		rr = var->rb_cnt;
		while (rr--)
			rra_rrb(b, 'b');
	}
}
void	a_b_roll_a(t_stack *a, t_stack *b, int *cnt, t_value *var)
{
	int	rr;
	int	rem;

	rr = var->rb_cnt;
	rem = var->ra_cnt - rr;
	if ((*cnt) > 0)
	{
		while (rr--)
			rrr(a, b);
		while (rem--)
			rra_rrb(a, 'a');
	}
	else
	{
		while (rr--)
			rra_rrb(b, 'b');
	}
}


void		a_to_b(int size, t_stack *a, t_stack *b, int *cnt)
{
	int		tmp;
	t_value	var;
	if (!exceptional_cases(size, a, b, 'a'))
		return ;
	init_value(&var);
	select_pivot(size, a, &var);
	tmp = size;
	while (tmp--)
		rot_push_b(a, b, &var);
	if (var.ra_cnt > var.rb_cnt)
		a_b_roll_a(a, b, cnt, &var);
	else
		a_b_roll_b(a, b, cnt, &var);
	a_to_b(var.ra_cnt, a, b, cnt);
	b_to_a(var.rb_cnt, a, b, cnt);
	b_to_a(var.pb_cnt - var.rb_cnt, a, b, cnt);
}
