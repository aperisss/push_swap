/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackpush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 04:20:01 by aperis            #+#    #+#             */
/*   Updated: 2022/04/02 04:37:37 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp2 = malloc(sizeof(t_stack));
	tmp = *stack_a;
	tmp2->value = tmp->value;
	tmp2->next = NULL;
	ft_stackadd_front(stack_b, tmp2);
	*stack_a = tmp->next;
	free(tmp);
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp2 = malloc(sizeof(t_stack));
	tmp = *stack_a;
	tmp2->value = tmp->value;
	tmp2->next = NULL;
	ft_stackadd_front(stack_b, tmp2);
	*stack_a = tmp->next;
	free(tmp);
	write(1, "pb\n", 3);
}



void	ft_sa(t_stack **stack_a)
{
	t_stack *tmp_a;
	int		tmp;

	tmp_a = *stack_a;
	tmp = tmp_a->value;
	tmp_a->value = tmp_a->next->value;
	tmp_a->next->value = tmp;
	write(1, "sa\n", 3);
}
