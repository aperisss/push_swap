/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:26:41 by aperis            #+#    #+#             */
/*   Updated: 2022/04/12 15:35:54 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bstack	*ft_stacklast2(t_bstack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int	ft_strcmp(char *s1, char *s2)
{
	if (s1)
	{
		while (*s1 == *s2 && *s1 && *s2)
		{
			s1++;
			s2++;
		}
		return (*s1 - *s2);
	}
	return (0);
}

void	ft_stackadd_back2(t_bstack **astack)
{
	t_bstack	*new;

	new = malloc(sizeof(t_bstack));
	new->next = NULL;
	if (*astack)
		ft_stacklast2(*astack)->next = new;
	else
		*astack = new;
}
