/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 04:18:32 by aperis            #+#    #+#             */
/*   Updated: 2022/04/09 22:28:05 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	save_max_index(t_stack *stack_a)
{
	t_stack	*tmp_a;
	int		max;

	max = 0;
	tmp_a = stack_a;
	while (tmp_a != NULL)
	{
		if (tmp_a->lis_index > max)
			max = tmp_a->lis_index;
		tmp_a = tmp_a->next;
	}
	return (max);
}

void	tmplis(t_stack **tmp_b, t_stack **stack_a)
{
	t_stack	*tmp_a;
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	tmp_a = *stack_a;
	tmp->value = tmp_a->value;
	tmp->next = NULL;
	ft_stackadd_front(tmp_b, tmp);
}

int	stack_chr(t_stack **tmplis, t_stack **stack_a)
{
	t_stack	*tmp_tmplis;
	t_stack	*tmp_a;

	tmp_tmplis = *tmplis;
	tmp_a = *stack_a;
	while (tmp_tmplis)
	{
		if (tmp_tmplis->value == tmp_a->value)
			return (1);
		tmp_tmplis = tmp_tmplis->next;
	}
	return (0);
}

int	ft_check_lis_pos(t_stack **stack_a, t_stack **tmp_lis)
{
	t_stack	*tmp_a;

	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (stack_chr(tmp_lis, &tmp_a) != 1)
			return (tmp_a->pos);
		tmp_a = tmp_a->next;
	}
	return (0);
}

void	push_lis(t_stack **stack_a, t_stack **stack_b, int pos)
{
	if (pos > 0)
	{
		while (pos > 0)
		{
			ft_ra(stack_a);
			pos--;
		}
		ft_pb(stack_a, stack_b);
	}
	else if (pos < 0)
	{
		while (pos < 0)
		{
			ft_rra(stack_a);
			pos++;
		}
		ft_pb(stack_a, stack_b);
	}
	else
		ft_pb(stack_a, stack_b);
}
