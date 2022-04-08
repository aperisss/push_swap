/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 04:18:52 by aperis            #+#    #+#             */
/*   Updated: 2022/04/02 04:28:05 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	create_stack(int ac, char **av)
{
	t_stack	*stack;
	int		i;

	i = 1;
	stack = malloc(sizeof(t_stack));
	stack->value = ft_atoi(av[i]);
	stack->next = NULL;
	while (--ac > 1)
	{
		i++;
		ft_stackadd_back(&stack, i, av);
	}
	ft_stacklast(stack)->next = NULL;
	return (*stack);
}

void	create_lis(t_stack **stack_a, t_stack **tmp_lis, t_stack **stack_b)
{
	t_stack *tmp_a;
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
	while(tmp > 0)
	{
		initialise_pos(&tmp_a);
		pos = ft_check_lis_pos(&tmp_a, tmp_lis);
		push_lis(&tmp_a, stack_b, pos);
		tmp--;
	}
	*stack_a = tmp_a;
}

void    best_push(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_a;
    tmp_a = *stack_a;
    while(tmp_a != NULL)
    {
        initialise_pos(stack_b);
	    initialise_pos(&tmp_a);
	    initialise_futur_pos(&tmp_a, stack_b);
	    initialise_best_push(&tmp_a);
        push(&tmp_a, stack_b);
    }
    *stack_a = tmp_a;
}

void index_sort(t_stack **stack_a)
{
	t_stack *tmp_a;
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
	while ( tmp_a->value != index_sort)
		tmp_a = tmp_a->next;
	if (tmp_a->pos > 0)
	{
		while(tmp_a->pos > 0)
		{
			ft_rb(stack_a);
			tmp_a->pos--;
		}
	}
	else if (tmp_a->pos < 0)
	{
		while(tmp_a->pos < 0)
		{
			ft_rrb(stack_a);
			tmp_a->pos++;
		}
	}
}

int	main(int ac, char **av)
{
	t_stack *tmp_a;
	t_stack *tmplis;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	stack_b = NULL;
	tmplis = malloc(sizeof(t_stack));
	tmplis = NULL;
	if (ft_check_arg(ac, av) == 0)
		return (0);
	*stack_a = create_stack(ac, av);
	if (already_sort(&stack_a) == 1)
		return (0);
	if (ft_stacksize(stack_a) < 6)
	{
		less_than5(&stack_a, &stack_b);

	while(stack_a)
	{
		printf("less = %d\n", stack_a->value);
		stack_a = stack_a->next;
	}
		return (0);
	}
	create_lis(&stack_a, &tmplis, &stack_b);
	best_push(&stack_b, &stack_a);
	index_sort(&stack_a);
	
	while(stack_a->next)
	{
		tmp_a = stack_a->next;
		free(stack_a);
		stack_a = tmp_a;
	}
	return (0);
}
