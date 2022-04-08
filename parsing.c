/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 04:18:22 by aperis            #+#    #+#             */
/*   Updated: 2022/04/02 04:23:46 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_check_arg2(int ac, char **av)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	j = 2;
	tmp = ac;
	if ( ac < 2)
		return (0);
	while (tmp > 1)
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
		while (av[i][j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9')
				&& (av[i][j] != '+' && av[i][j] != '-'))
				return (0);
			if ((av[i][j] == '-' || av[i][j] == '+') && j != 0)
				return (0);
			if ((av[i][0] == '+' || av[i][0] == '-') && !av[i][1])
				return (0);
			j++;
		}
		i++;
		ac--;
		j = 0;
	}
	return (1);
}