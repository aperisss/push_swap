#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + nptr[i] - 48;
		i++;
	}
	return (nb * sign);
}

t_stack create_stack(int ac, char **av)
{
    t_stack *stack;
    t_stack *tmp;
    int i;

    i = 1;
    stack = malloc(sizeof(t_stack) *  ac);
    tmp = malloc(sizeof(t_stack));
    stack->value = ft_atoi(av[i]);
    tmp = stack;
    while(--ac > 1)
    {
        i++;
        ft_stackadd_back(&stack, i, av);
    }
    return (*tmp);
}