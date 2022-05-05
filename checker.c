/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:27:58 by aperis            #+#    #+#             */
/*   Updated: 2022/05/05 20:56:23 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	wrong_instruction(t_bstack **stack)
{
	t_bstack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (ft_strcmp(tmp->str, "rra\n") != 0
			&& ft_strcmp(tmp->str, "rrb\n") != 0
			&& ft_strcmp(tmp->str, "rrr\n") != 0
			&& ft_strcmp(tmp->str, "ra\n") != 0
			&& ft_strcmp(tmp->str, "rb\n") != 0
			&& ft_strcmp(tmp->str, "rr\n") != 0
			&& ft_strcmp(tmp->str, "sa\n") != 0
			&& ft_strcmp(tmp->str, "sb\n") != 0
			&& ft_strcmp(tmp->str, "pa\n") != 0
			&& ft_strcmp(tmp->str, "pb\n") != 0)
		{
			write(1, "Error\n", 6);
			free_stack_str(&tmp);
			f_stack(&tmp);
			exit(0);
		}
		tmp = tmp->next;
	}
}

void	instruction2(t_bstack **stack, t_stack **stack_a, t_stack **stack_b)
{
	t_bstack	*tmp;

	tmp = *stack;
	if (ft_strcmp(tmp->str, "sa\n") == 0)
		bft_sa(stack_a);
	else if (ft_strcmp(tmp->str, "sb\n") == 0)
		bft_sb(stack_b);
	else if (ft_strcmp(tmp->str, "pa\n") == 0)
		bft_pa(stack_b, stack_a);
	else if (ft_strcmp(tmp->str, "pb\n") == 0)
		bft_pb(stack_a, stack_b);
}

void	instruction(t_bstack **stack, t_stack **stack_a, t_stack **stack_b)
{
	t_bstack	*tmp;

	tmp = *stack;
	while (tmp->str != NULL)
	{
		if (ft_strcmp(tmp->str, "rra\n") == 0)
			bft_rra(stack_a);
		else if (ft_strcmp(tmp->str, "rrb\n") == 0)
			bft_rrb(stack_b);
		else if (ft_strcmp(tmp->str, "rrr\n") == 0)
			bft_rrr(stack_a, stack_b);
		else if (ft_strcmp(tmp->str, "ra\n") == 0)
			bft_ra(stack_a);
		else if (ft_strcmp(tmp->str, "rb\n") == 0)
			bft_rb(stack_b);
		else if (ft_strcmp(tmp->str, "rr\n") == 0)
			bft_rr(stack_a, stack_b);
		else if (ft_strcmp(tmp->str, "sa\n") == 0
			|| ft_strcmp(tmp->str, "sb\n") == 0
			|| ft_strcmp(tmp->str, "pa\n") == 0
			|| ft_strcmp(tmp->str, "pb\n") == 0)
			instruction2(&tmp, stack_a, stack_b);
		tmp = tmp->next;
	}
}

void	checker(t_stack **stack_a, t_stack **stack_b)
{
	t_bstack	*stack;
	t_bstack	*tmp;

	if (!*stack_a)
		exit(0);
	stack = malloc(sizeof(t_bstack));
	tmp = stack;
	stack->str = get_next_line(0);
	wrong_instruction(&stack);
	stack->next = NULL;
	while (stack->str != NULL)
	{
		ft_stackadd_back2(&stack);
		stack = ft_stacklast2(stack);
		stack->str = get_next_line(0);
		wrong_instruction(&stack);
	}
	stack = tmp;
	wrong_instruction(&tmp);
	instruction(&tmp, stack_a, stack_b);
	free_stack_str(&stack);
	f_stack(&stack);
}

int	main(int ac, char **av)
{
	t_stack	*stack_b;
	t_stack	*stack_a;

	ft_check_arg(ac, av);
	stack_a = malloc(sizeof(t_stack));
	stack_b = NULL;
	create_stack(&stack_a, ac, av);
	checker(&stack_a, &stack_b);
	if (!stack_a)
	{
		write(1, "KO\n", 3);
		free(stack_a);
		free_stack(&stack_b);
		return (0);
	}
	if (already_sort(&stack_a) == 1 && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_checker(&stack_a, &stack_b);
	return (0);
}
