/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:40:27 by aperis            #+#    #+#             */
/*   Updated: 2022/04/12 00:40:41 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(t_stack **stack_a, int ac, char **av)
{
	t_stack	*tmp_a;
	int		i;

	tmp_a = *stack_a;
	i = 1;
	tmp_a->value = ft_atoi(av[i]);
	tmp_a->next = NULL;
	while (--ac > 1)
	{
		i++;
		ft_stackadd_back(&tmp_a, i, av);
	}
	ft_stacklast(tmp_a)->next = NULL;
}

void	create_lis(t_stack **stack_a, t_stack **tmp_lis, t_stack **stack_b)
{
	t_stack	*tmp_a;
	int		pos;
	int		max_index;
	int		tmp;

	initialise_index(stack_a);
	max_index = save_max_index(*stack_a);
	while (max_index > 0)
	{
		initialise_tmplis(stack_a, tmp_lis, max_index);
		max_index--;
	}
	tmp = ft_stacksize(*stack_a) - ft_stacksize(*tmp_lis);
	tmp_a = *stack_a;
	while (tmp > 0)
	{
		initialise_pos(&tmp_a);
		pos = ft_check_lis_pos(&tmp_a, tmp_lis);
		push_lis(&tmp_a, stack_b, pos);
		tmp--;
	}
	*stack_a = tmp_a;
}

void	best_push(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*tmp_b;

	tmp_b = *stack_b;
	while (tmp_b != NULL)
	{
		initialise_pos(stack_a);
		initialise_pos(&tmp_b);
		initialise_futur_pos(&tmp_b, stack_a);
		initialise_best_push(&tmp_b);
		push(&tmp_b, stack_a);
	}
	*stack_b = tmp_b;
}

void	index_sort(t_stack **stack_a)
{
	t_stack	*tmp_a;
	int		index_sort;

	initialise_pos(stack_a);
	tmp_a = *stack_a;
	index_sort = tmp_a->value;
	while (tmp_a != NULL)
	{
		if (tmp_a->value < index_sort)
			index_sort = tmp_a->value;
		tmp_a = tmp_a->next;
	}
	tmp_a = *stack_a;
	while (tmp_a->value != index_sort)
		tmp_a = tmp_a->next;
	if (tmp_a->pos > 0)
	{
		while (tmp_a->pos-- > 0)
			ft_ra(stack_a);
	}
	else if (tmp_a->pos < 0)
	{
		while (tmp_a->pos++ < 0)
			ft_rra(stack_a);
	}
}
