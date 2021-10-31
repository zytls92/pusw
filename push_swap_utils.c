#include "push_swap.h"

void	init_value(t_value *var)
{
	var->ra_cnt = 0;
	var->rb_cnt = 0;
	var->pa_cnt = 0;
	var->pb_cnt = 0;
    var->b_pi = 0;
    var->s_pi = 0;
}

void	select_pivot(int size, t_stack *stack, t_value *var)
{
	int	min;
	int	max;
	long	sum;

    minmax(stack, &max, &min, size);
	sum = min + max;
	var->b_pi = sum / 2;
	sum = min + var->b_pi;
	var->s_pi = sum / 2;
}