#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *stack;
	int i;

    if ( ft_check_arg(ac, av) == 0)
        return (0);

    stack = malloc(sizeof(t_stack) * (ac - 1));
    *stack = create_stack(ac, av);
    i = 0;
    while ( i < stack->stacksize)
    {
        i++;
        printf("%d \n", stack->value);
        stack = stack->next;
    }
    ft_ra(stack);
    i = 0;
    while ( i < stack->stacksize)
    {
        i++;
        printf("|%d \n", stack->value);
        stack = stack->next;
    }
    return (0);
}