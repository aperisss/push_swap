/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 04:19:53 by aperis            #+#    #+#             */
/*   Updated: 2022/04/02 04:36:31 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp2 = malloc(sizeof(t_stack));
	tmp = *stack_a;
	 tmp2->lis_index = tmp->lis_index;
	tmp2->value = tmp->value;
	ft_stacklast(*stack_a)->next = tmp2;
	tmp2->next = NULL;
	*stack_a = tmp->next;
	free(tmp);
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp2 = malloc(sizeof(t_stack));
	tmp = *stack_a;
	tmp2->value = tmp->value;
	tmp2->lis_index = tmp->lis_index;
	ft_stacklast(*stack_a)->next = tmp2;
	tmp2->next = NULL;
	*stack_a = tmp->next;
	free(tmp);
	write(1, "rb\n", 3);
}

void	ra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp2 = malloc(sizeof(t_stack));
	tmp = *stack_a;
	 tmp2->lis_index = tmp->lis_index;
	tmp2->value = tmp->value;
	ft_stacklast(*stack_a)->next = tmp2;
	tmp2->next = NULL;
	*stack_a = tmp->next;
	free(tmp);
}

void	rb(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp2 = malloc(sizeof(t_stack));
	tmp = *stack_a;
	tmp2->value = tmp->value;
	tmp2->lis_index = tmp->lis_index;
	ft_stacklast(*stack_a)->next = tmp2;
	tmp2->next = NULL;
	*stack_a = tmp->next;
	free(tmp);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}
