/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_stackpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:23:33 by aperis            #+#    #+#             */
/*   Updated: 2022/04/12 15:23:36 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bft_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (*stack_a)
	{
		tmp2 = malloc(sizeof(t_stack));
		tmp = *stack_a;
		tmp2->value = tmp->value;
		tmp2->next = NULL;
		ft_stackadd_front(stack_b, tmp2);
		*stack_a = tmp->next;
		free(tmp);
	}
}

void	bft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (*stack_a)
	{
		tmp2 = malloc(sizeof(t_stack));
		tmp = *stack_a;
		tmp2->value = tmp->value;
		tmp2->next = NULL;
		ft_stackadd_front(stack_b, tmp2);
		*stack_a = tmp->next;
		free(tmp);
	}
}

void	bft_sa(t_stack **stack_a)
{
	t_stack	*tmp_a;
	int		tmp;

	tmp_a = *stack_a;
	if (tmp_a && tmp_a->next)
	{
		tmp = tmp_a->value;
		tmp_a->value = tmp_a->next->value;
		tmp_a->next->value = tmp;
	}
}

void	bft_sb(t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		tmp;

	tmp_b = *stack_b;
	if (tmp_b && tmp_b->next)
	{
		tmp = tmp_b->value;
		tmp_b->value = tmp_b->next->value;
		tmp_b->next->value = tmp;
	}
}
