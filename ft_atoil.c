#include "push_swap.h"

int	check_isspace(char *c)
{
	int idx;

	idx = 0;
	while (c[idx] == '\t' || c[idx] == '\n'
			|| c[idx] == ' ' || c[idx] == '\v'
			|| c[idx] == '\f' || c[idx] == '\r')
		idx++;
	return (idx);
}

int	check_pm(int idx, char *c, int *cnt)
{
	if (c[idx] == '+' || c[idx] == '-')
	{
		if (c[idx] == '-')
			(*cnt)++;
		idx++;
	}
	return (idx);
}

int			ft_atoi(const char *str)
{
	int		cnt;
	int		idx;
	long	res;

	cnt = 0;
	res = 0;
	idx = check_pm(check_isspace((char *)str), (char *)str, &cnt);
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		res = res * 10 + (str[idx] - 48);
		if (res > 2147483647 && cnt == 0)
			return (-1);
		if (res > 2147483648 && cnt == 1)
			return (0);
		idx++;
	}
	if (cnt == 1)
		res *= -1;
	return (res);
}