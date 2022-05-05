/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 04:18:22 by aperis            #+#    #+#             */
/*   Updated: 2022/04/12 15:02:47 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*f;

	tmp = *stack;
	while (tmp->next)
	{
		f = tmp->next;
		free(tmp);
		tmp = f;
	}
	free(tmp);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	long int	nb;
	int			sign;

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
	if (nb > 2147483647 && sign > 0)
		exit_error();
	if (nb > 2147483648 && sign < 0)
		exit_error();
	return (nb * sign);
}

int	ft_check_arg2(int ac, char **av)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	j = 2;
	tmp = ac;
	if (ac < 2)
		exit(0);
	while (tmp > 1)
	{
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				exit_error();
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
	ft_check_arg2(ac, av);
	while (ac > 1)
	{
		while (av[i][j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9')
				&& (av[i][j] != '+' && av[i][j] != '-'))
				exit_error();
			if ((av[i][j] == '-' || av[i][j] == '+') && j != 0)
				exit_error();
			if ((av[i][0] == '+' || av[i][0] == '-') && !av[i][1])
				exit_error();
			j++;
		}
		i++;
		ac--;
		j = 0;
	}
	return (1);
}
