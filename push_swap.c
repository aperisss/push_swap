/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 04:18:52 by aperis            #+#    #+#             */
/*   Updated: 2022/04/12 15:06:53 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*tmplis;
	t_stack	*stack_a;
	t_stack	*stack_b;

	ft_check_arg(ac, av);
	stack_a = malloc(sizeof(t_stack));
	stack_b = NULL;
	tmplis = NULL;
	create_stack(&stack_a, ac, av);
	if (already_sort(&stack_a) == 1)
	{
		free_stack(&stack_a);
		return (0);
	}
	if (ft_stacksize(stack_a) < 6)
	{
		less_than5(&stack_a, &stack_b);
		return (0);
	}
	create_lis(&stack_a, &tmplis, &stack_b);
	best_push(&stack_b, &stack_a);
	index_sort(&stack_a);
	free_stack(&tmplis);
	free_stack(&stack_a);
	return (0);
}
