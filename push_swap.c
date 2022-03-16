#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *stack;
    t_stack *tmp;

    stack = malloc(sizeof(t_stack) * (ac - 1));

    *stack = create_stack(ac, av);
    ft_ra(stack);
    printf("stackka = %d\n", stack->value);
    while ( stack != NULL)
    {
        printf("|||||%d \n", stack->value);
        stack = stack->next;
    }
    return (0);
}

