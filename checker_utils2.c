/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:14:48 by aperis            #+#    #+#             */
/*   Updated: 2022/05/05 21:01:36 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f_stack(t_bstack **stack)
{
	t_bstack	*tmp;
	t_bstack	*f;

	tmp = *stack;
	while (tmp->next)
	{
		f = tmp->next;
		free(tmp);
		tmp = f;
	}
	free(tmp);
}

void	free_stack_str(t_bstack **stack)
{
	t_bstack	*tmp;
	t_bstack	*f;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		f = tmp->next;
		free(tmp->str);
		tmp = f;
	}
}

void	free_checker(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a)
	{
		if (ft_stacksize(*stack_a) > 1)
			free_stack(stack_a);
		else
			free(*stack_a);
	}
	if (*stack_b)
	{
		if (ft_stacksize(*stack_b) > 1)
			free_stack(stack_b);
		else
			free(*stack_b);
	}
}
