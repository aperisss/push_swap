/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 04:19:05 by aperis            #+#    #+#             */
/*   Updated: 2022/04/02 04:29:49 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include  <stdlib.h>
#include <stdio.h>

typedef struct	s_stack
{
	int		value;
	int		lis_index;
	int		pos;
	int		futur_pos;
	int		best_push;
	int		nopush;
	struct s_stack	*next;
}	t_stack;

void    ft_stackadd_back(t_stack **astack, int i, char **av);
void	ft_stackadd_front2(t_stack **astack, int i, char **av);
void	ft_stackadd_front(t_stack **astack, t_stack *new);
t_stack	*ft_stacklast(t_stack *stack);
int		ft_stacksize(t_stack *stack);
int		return_max(int a, int b);
int		return_min(int a, int b);
int		abs(int a);
void	ft_ra(t_stack **stack);
void	ra(t_stack **stack_a);
void	ft_rb(t_stack **stack);
void	rb(t_stack **stack_a);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rra(t_stack **stack);
void	rra(t_stack **stack);
void	ft_rrb(t_stack **stack);
void	rrb(t_stack **stack);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_pa(t_stack **stack, t_stack **stack2);
void	ft_pb(t_stack **stack, t_stack **stack2);
void	ft_sa(t_stack **stack_a);
int	ft_atoi(const char *nptr);
int	ft_check_arg2(int ac, char **av);
int	ft_check_arg(int ac, char **av);
t_stack	create_stack(int ac, char **av);
void	initialise_index(t_stack **stack_a);
void	initialise_pos(t_stack **stack_a);
int	save_max_index(t_stack *stack_a);
void	tmplis(t_stack **stack_a, t_stack **tmp_b);
void	push_lis(t_stack **stack_a, t_stack **stack_b, int pos);
void	initialise_tmplis(t_stack **stack_a, t_stack **stack_b, int max_index);
void	create_lis(t_stack **stack_a, t_stack **tmp_lis, t_stack **stack_b);
int		stack_chr(t_stack **tmplis, t_stack **stack_a);
int ft_check_lis_pos(t_stack **stack_a, t_stack **tmp_lis);
void futur_pos3(t_stack **stack_a, t_stack **stack_b);
void futur_pos2(t_stack **stack_a, t_stack **stack_b);
void initialise_futur_pos(t_stack **stack_a, t_stack **stack_b);
void    initialise_best_push(t_stack **stack_a);
int push_min(t_stack **stack_a);
void    push(t_stack **stack_a, t_stack **stack_b);
void    push2(t_stack **stack_a, t_stack **stack_b, int pos, int futur_pos);
void    push3(t_stack **stack_a, t_stack **stack_b, int pos, int futur_pos);
void    push4(t_stack **stack_a, t_stack **stack_b, int pos, int futur_pos);
void    best_push(t_stack **stack_a, t_stack **stack_b);
void index_sort(t_stack **stack_a);
int	already_sort(t_stack **stack_a);
void    little_sort(t_stack **stack_a, t_stack **stack_b);
void    sort_of3(t_stack **stack_a);
void    sort_of4(t_stack **stack_a, t_stack **stack_b);
void    sort_of5(t_stack **stack_a, t_stack **stack_b);
void    less_than5(t_stack **stack_a, t_stack **stack_b);
#endif
