/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   futur_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:15:56 by aperis            #+#    #+#             */
/*   Updated: 2022/04/09 20:38:29 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_push34(t_stack **stack_a, t_stack **stack_b, int pos, int f_pos)
{
	if ((pos == 0 && f_pos != 0)
		|| (pos != 0 && f_pos == 0))
		push3(stack_a, stack_b, pos, f_pos);
	if ((pos > 0 && f_pos < 0) || (pos < 0 && f_pos > 0))
		push4(stack_a, stack_b, pos, f_pos);
}

void	initialise_pos_size1(t_stack **stack_a)
{
	t_stack	*tmp_a;

	tmp_a = *stack_a;
	if (ft_stacksize(*stack_a) == 1)
		tmp_a->pos = 0;
}

void	futur_pos3(t_stack **stack_a, t_stack **stack_b)
{
	int		max;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	max = tmp_b->value;
	while (tmp_b != NULL)
	{
		if (tmp_b->value > max)
			max = tmp_b->value;
		tmp_b = tmp_b->next;
	}
	tmp_b = *stack_b;
	while (tmp_b->value != max)
		tmp_b = tmp_b->next;
	tmp_a->futur_pos = tmp_b->pos + 1;
}

void	futur_pos2(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp_b;
	t_stack	*tmp_a;

	i = 0;
	tmp_b = *stack_b;
	tmp_a = *stack_a;
	while (tmp_b->next != NULL)
	{
		if (tmp_a->value > tmp_b->value && tmp_a->value < tmp_b->next->value)
		{
			i = 1;
			tmp_a->futur_pos = tmp_b->next->pos;
		}
		tmp_b = tmp_b->next;
	}
	if (i == 0)
		futur_pos3(stack_a, stack_b);
}

void	initialise_futur_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp_b;
	t_stack	*tmp_a;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	while (tmp_a != NULL)
	{
		while (tmp_b->next != NULL)
			tmp_b = tmp_b->next;
		tmp = tmp_b;
		tmp_b = *stack_b;
		if (tmp_a->value < tmp_b->value && tmp_a->value > tmp->value)
			tmp_a->futur_pos = 0;
		else
			futur_pos2(&tmp_a, stack_b);
		tmp_a = tmp_a->next;
	}
}
