/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:01:17 by aperis            #+#    #+#             */
/*   Updated: 2022/04/12 00:11:25 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_min(t_stack **stack_a)
{
	int		push_min;
	t_stack	*tmp_a;

	tmp_a = *stack_a;
	push_min = tmp_a->best_push;
	while (tmp_a != NULL)
	{
		if (tmp_a->best_push < push_min)
			push_min = tmp_a->best_push;
		tmp_a = tmp_a->next;
	}
	return (push_min);
}

void	push4(t_stack **stack_b, t_stack **stack_a, int pos, int futur_pos)
{
	if (pos > 0)
	{
		while (pos > 0)
		{
			ft_rb(stack_b);
			pos--;
		}
		while (futur_pos < 0)
		{
			ft_rra(stack_a);
			futur_pos++;
		}
	}
	else if (futur_pos > 0)
	{
		while (futur_pos > 0)
		{
			ft_ra(stack_a);
			futur_pos--;
		}
		while (pos++ < 0)
			ft_rrb(stack_b);
	}
}

void	push3(t_stack **stack_b, t_stack **stack_a, int pos, int futur_pos)
{
	if (pos > 0)
	{
		while (pos-- != 0)
			ft_rb(stack_b);
	}
	else if (pos < 0)
	{
		while (pos++ != 0)
			ft_rrb(stack_b);
	}
	else if (futur_pos > 0)
	{
		while (futur_pos-- != 0)
			ft_ra(stack_a);
	}
	else if (futur_pos < 0)
	{
		while (futur_pos++ != 0)
			ft_rra(stack_a);
	}
}

void	push2(t_stack **stack_b, t_stack **stack_a, int pos, int futur_pos)
{
	int		i;

	i = 0;
	if (pos < 0 && futur_pos < 0)
	{
		while (i < return_min(pos, futur_pos))
		{
			ft_rrr(stack_b, stack_a);
			i++;
		}
		while (i < return_max(pos, futur_pos))
		{
			if (pos > futur_pos)
				ft_rra(stack_a);
			else if (pos < futur_pos)
				ft_rrb(stack_b);
			i++;
		}
	}
	check_push34(stack_b, stack_a, pos, futur_pos);
	ft_pa(stack_b, stack_a);
}

void	push(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*tmp_b;
	int		i;

	tmp_b = *stack_b;
	i = 0;
	while (tmp_b->best_push != push_min(stack_b))
		tmp_b = tmp_b->next;
	if (tmp_b->pos > 0 && tmp_b->futur_pos > 0)
	{
		while (i < return_min(tmp_b->pos, tmp_b->futur_pos))
		{
			ft_rr(stack_b, stack_a);
			i++;
		}
		while (i++ < return_max(tmp_b->pos, tmp_b->futur_pos))
		{
			if (tmp_b->pos > tmp_b->futur_pos)
				ft_rb(stack_b);
			else if (tmp_b->pos < tmp_b->futur_pos)
				ft_ra(stack_a);
		}
	}
	push2(stack_b, stack_a, tmp_b->pos, tmp_b->futur_pos);
}
