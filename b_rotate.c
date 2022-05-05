/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:22:25 by aperis            #+#    #+#             */
/*   Updated: 2022/04/12 15:43:00 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bft_ra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack_a;
	if (tmp && tmp->next)
	{
		tmp2 = malloc(sizeof(t_stack));
		tmp2->lis_index = tmp->lis_index;
		tmp2->value = tmp->value;
		ft_stacklast(*stack_a)->next = tmp2;
		tmp2->next = NULL;
		*stack_a = tmp->next;
		free(tmp);
	}
}

void	bft_rb(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack_a;
	if (tmp && tmp->next)
	{
		tmp2 = malloc(sizeof(t_stack));
		tmp2->value = tmp->value;
		tmp2->lis_index = tmp->lis_index;
		ft_stacklast(*stack_a)->next = tmp2;
		tmp2->next = NULL;
		*stack_a = tmp->next;
		free(tmp);
	}
}

void	bft_rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	if (tmp_a && tmp_a->next && tmp_b && tmp_b->next)
	{
		bft_ra(stack_a);
		bft_rb(stack_b);
	}
}
