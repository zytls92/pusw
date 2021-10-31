#include "push_swap.h"

char	**free_split(char **res, int i, int *len_arry)
{
	int	idx;

	idx = 0;
	while (idx++ < i)
		free(res[i]);
	free(res);
	free(len_arry);
	return (NULL);
}

int		num_str(char const *s, char c)
{
	char	back;
	int		res;

	res = 0;
	back = c;
	while (*s)
	{
		if (*s == c && back != c)
			res++;
		back = *(s++);
	}
	if (back != c)
		res += 1;
	return (res);
}

void	len_str(int *len_arry, char const *s, char c)
{
	int	len;
	int	flag;
	int	idx;

	len = 0;
	flag = 0;
	idx = 0;
	while (*s)
	{
		if (*s == c && flag == 1)
		{
			len_arry[idx++] = len;
			len = 0;
			flag = 0;
		}
		else if (*s != c)
		{
			flag = 1;
			len++;
		}
		s++;
	}
	if (len != 0)
		len_arry[idx] = len;
}

char	**alloc(char **res, char const *s, char c, int idx)
{
	int		flag;
	int		pos;

	pos = 0;
	flag = 0;
	while (*s)
	{
		if (*s == c && flag == 1)
		{
			flag = 0;
			res[idx++][pos] = '\0';
			pos = 0;
		}
		else if (*s != c)
		{
			flag = 1;
			res[idx][pos++] = *s;
		}
		s++;
	}
	if (flag == 1)
		res[idx][pos] = '\0';
	return (res);
}

char			**ft_split(char const *s, char c)
{
	int		size;
	char	**res;
	int		*len_arry;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	size = num_str(s, c);
	if ((res = (char **)malloc(sizeof(char *) * (size + 1))) == NULL)
		return (NULL);
	len_arry = (int *)malloc(sizeof(int) * size);
	len_str(len_arry, s, c);
	while (i < size)
	{
		if ((res[i] = (char *)malloc(sizeof(char) * (len_arry[i] + 1))) == NULL)
			return (free_split(res, i, len_arry));
		i++;
	}
	free(len_arry);
	res[size] = NULL;
	return (alloc(res, s, c, 0));
}