/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_reverse_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:22:00 by aperis            #+#    #+#             */
/*   Updated: 2022/04/12 15:42:48 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bft_rra(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack;
	if (tmp && tmp->next)
	{
		tmp2 = ft_stacklast(*stack);
		if (ft_stacksize(*stack) != 1)
		{
			while (tmp->next->next != NULL)
				tmp = tmp->next;
			ft_stacklast(*stack)->next = *stack;
			tmp->next = NULL;
			*stack = tmp2;
		}
	}
}

void	bft_rrb(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack;
	if (tmp && tmp->next)
	{
		tmp2 = ft_stacklast(*stack);
		if (ft_stacksize(*stack) != 1)
		{
			while (tmp->next->next != NULL)
				tmp = tmp->next;
			ft_stacklast(*stack)->next = *stack;
			tmp->next = NULL;
			*stack = tmp2;
		}
	}
}

void	bft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	if (tmp_a && tmp_a->next && tmp_b && tmp_b->next)
	{
		bft_rra(stack_a);
		bft_rrb(stack_b);
	}
}
