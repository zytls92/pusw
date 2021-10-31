#include "push_swap.h"
// ================================================
#include <stdio.h>
#include <string.h>

void    ft_error(char *msg, t_stack *a, t_stack *b)
{
    write(1, msg, ft_strlen(msg));
    free_all(a,b);
    exit(0);
}

void    print_stack(t_stack stack, char ab)
{
    t_elem elem;

    if (ab == 'a')
        printf("stack a 출력\n");
    else
        printf("stack b 출력\n");
    if (!stack.top)
        return ;
    elem = *(stack.top);
    while (elem.prev)
    {
        printf("%d  ", elem.value);
        elem = *(elem.prev);
    }
    printf("%d\n", elem.value);
}

void    push_swap(t_stack  *a, t_stack *b)
{
    int cnt;

    cnt = 0;
    if (a->size == 5)
        only_five_elem(a,b);
    else
        a_to_b(a->size, a, b, &cnt);
}

int main(int argc, char**argv)
{
    t_stack *a;
    t_stack *b;
    int nbw;
    
    int min;
    int max;
    if (argc > 1)
    {
        a = empty_stack();
        b = empty_stack();
        nbw = fill_stack(argc, argv, a);
        if (nbw == 1)
            ft_error("wrong input!",a,b);
        if (is_sorted(a, 'a', 3))
        {
            free_all(a,b);
            return (0);
        }
        push_swap(a,b);
        free_all(a,b);
    }
    return (0);
}