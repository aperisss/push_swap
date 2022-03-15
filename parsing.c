#include "push_swap.h"

int	ft_check_arg2(int ac, char **av)
{
	int i;
	int j;
	int tmp;
	
	i = 0;
	j = 1;
	tmp = ac;
	while ( tmp > 1)
	{
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
		j = i + 1;
		tmp--;
	}
	return (1);
}

int	ft_check_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (ft_check_arg2(ac, av) == 0)
		return (0);
	while (ac > 1)
	{
		while(av[i][j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9') && (av[i][j] != '+' && av[i][j] != '-'))
				return (0);
			if ((av[i][j] == '-' || av[i][j] == '+') && j != 0)
				return (0);
			j++;
		}
		if (ft_atoi(av[i]) < ft_atoi("-2147483648") || ft_atoi(av[i]) > ft_atoi("2147483647"))
			return (0);
		i++;
		ac--;
		j = 0;
	}
	return (1);
}

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
    stack = malloc(sizeof(t_stack) *  (ac - 1));
    tmp = malloc(sizeof(t_stack));
	stack->next = NULL;
    stack->value = ft_atoi(av[i]);
    tmp = stack;
    while(--ac > 1)
    {
        i++;
        ft_stackadd_back(&stack, i, av);
        stack = stack->next;
		stack->next = NULL;
    }
	stack->next = NULL;
	i = ft_stacksize(stack);
	// stack->next = tmp;
	tmp->stacksize = i;
    return (*tmp);
}