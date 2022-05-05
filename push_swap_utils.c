/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 04:19:17 by aperis            #+#    #+#             */
/*   Updated: 2022/04/09 21:57:11 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacklast(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	ft_stackadd_front(t_stack **astack, t_stack *new)
{
	if (*astack)
	{
		new->next = *astack;
		*astack = new;
	}
	else
		*astack = new;
}

void	ft_stackadd_front2(t_stack **astack, int i, char **av)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->value = ft_atoi(av[i]);
	if (*astack)
	{
		new->next = *astack;
		*astack = new;
	}
	else
		*astack = new;
}

int	ft_stacksize(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	ft_stackadd_back(t_stack **astack, int i, char **av)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->value = ft_atoi(av[i]);
	new->next = NULL;
	if (*astack)
		ft_stacklast(*astack)->next = new;
	else
		*astack = new;
}
