# ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct  s_elem
{
    struct s_elem   *next;
    struct s_elem   *prev;
    int value;
}               t_elem;

typedef struct  s_stack
{
    t_elem   *top;
    t_elem   *bottom;
    int size;
}               t_stack;

typedef struct	s_value
{
	long	b_pi;
	long	s_pi;
	int		ra_cnt;
	int		rb_cnt;
	int		pa_cnt;
	int		pb_cnt;
}               t_value;

void	rot_push_b(t_stack *a, t_stack *b, t_value *var);
void	a_b_roll_b(t_stack *a, t_stack *b, int *cnt, t_value *var);
void	a_b_roll_a(t_stack *a, t_stack *b, int *cnt, t_value *var);
void	a_to_b(int size, t_stack *a, t_stack *b, int *cnt);
void	rot_push_a(t_stack *a, t_stack *b, t_value *var);
void	b_a_roll_a(t_stack *a, t_stack *b, t_value *var);
void	b_a_roll_b(t_stack *a, t_stack *b, t_value *var);
void	b_to_a(int size, t_stack *a, t_stack *b, int *cnt);
void    three_elem(t_stack *a, t_stack *b, int ab, int size);
void    over_three_elem(t_stack *a, t_stack *b,int ab, int size);
void    top_max_no(t_stack *a, t_stack *b, int ab, int min);
void    top_max_n_no(t_stack *a, t_stack *b, int ab, int min);
void    top_max_n_n_no(t_stack *a, t_stack *b, int ab, int min);


int	exceptional_cases(int size, t_stack *a, t_stack *b, int ab);
void		hanlde_sort_five(int size, t_stack *a, t_stack *b, int flag);
void	handle_under_three(int size, t_stack *a, t_stack *b, int ab);

//make_stack.c
t_stack* empty_stack();
t_elem *get_elem(char *argument);
int     split_argv(char *argument, t_stack *stack);
int     fill_stack(int argc, char **argv, t_stack *stack);
//ft_atoi.c
int	check_isspace(char *c);
int	check_pm(int idx, char *c, int *cnt);
int			ft_atoi(const char *str);
//ft_split.c
char	**free_split(char **res, int i, int *len_arry);
int		num_str(char const *s, char c);
void	len_str(int *len_arry, char const *s, char c);
char	**alloc(char **res, char const *s, char c, int idx);
char	**ft_split(char const *s, char c);
//push_swap.c
void    ft_error(char *msg, t_stack *a, t_stack *b);
//utils.c
int ft_strlen(char *s);
int doarr_len(char **arry);
//oper1.c
void    sa_sb(t_stack *stack, int ab);
void    ss(t_stack *stack1, t_stack *stack2);
void    pa_pb(t_stack *ss, t_stack *ds, int ab);
void    push_oper(t_stack *ss, t_stack *ds);
void    push_oper_size1(t_stack *ss, t_stack *ds);
//oper2.c
void    ra_rb(t_stack *stack, int ab);
void    rr(t_stack *stack1, t_stack *stack2);
void    rra_rrb(t_stack *stack, int ab);
void    rrr(t_stack *stack1, t_stack *stack2);
//free.c
void free_all(t_stack *a, t_stack *b);
void free_stack(t_stack *stack);
//minmax.c
void    minmax(t_stack *stack, int *max, int *min, int size);

//sort_stack.c
void    only_three_elem(t_stack *stack, int ab, int size);
void    two_elem(t_stack *a, t_stack *b, int ab);
void    top_mid(t_stack *stack, int ab, int min, int max);
void    top_min(t_stack *stack, int ab, int min, int max);
void    top_max(t_stack *stack, int ab, int min, int max);

int is_sorted(t_stack *stack, int ab, int size);
void		only_five_elem(t_stack *a, t_stack *b);
int			get_mid(t_elem *elem);
void	init_value(t_value *var);
void	select_pivot(int size, t_stack *stack, t_value *var);
int	sort_values(int value[]);
void    push_swap(t_stack  *a, t_stack *b);

//삭제
void    print_stack(t_stack stack, char ab);
//


#endif