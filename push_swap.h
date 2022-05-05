/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 04:19:05 by aperis            #+#    #+#             */
/*   Updated: 2022/04/12 15:48:01 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_stack
{
	struct s_stack	*next;
	int				value;
	int				lis_index;
	int				pos;
	int				futur_pos;
	int				best_push;
	int				nopush;
}	t_stack;

typedef struct instruct_stack
{
	struct instruct_stack	*next;
	char					*str;
}	t_bstack;

int			ft_strlen(char *str);
char		*ft_strchr(char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*get_next_line(int fd);
char		*ft_get_line(char *save);
char		*ft_save(char *save);
char		*ft_read_and_save(int fd, char *save);
void		ft_stackadd_back(t_stack **astack, int i, char **av);
void		ft_stackadd_front2(t_stack **astack, int i, char **av);
void		ft_stackadd_front(t_stack **astack, t_stack *new);
t_stack		*ft_stacklast(t_stack *stack);
int			ft_stacksize(t_stack *stack);
int			return_max(int a, int b);
int			return_min(int a, int b);
int			abs(int a);
void		ft_ra(t_stack **stack);
void		ra(t_stack **stack_a);
void		ft_rb(t_stack **stack);
void		rb(t_stack **stack_a);
void		ft_rr(t_stack **stack_a, t_stack **stack_b);
void		ft_rra(t_stack **stack);
void		rra(t_stack **stack);
void		ft_rrb(t_stack **stack);
void		rrb(t_stack **stack);
void		ft_rrr(t_stack **stack_a, t_stack **stack_b);
void		ft_pa(t_stack **stack, t_stack **stack2);
void		ft_pb(t_stack **stack, t_stack **stack2);
void		ft_sa(t_stack **stack_a);
void		ft_sb(t_stack **stack_b);
void		bft_ra(t_stack **stack);
void		bra(t_stack **stack_a);
void		bft_rb(t_stack **stack);
void		brb(t_stack **stack_a);
void		bft_rr(t_stack **stack_a, t_stack **stack_b);
void		bft_rra(t_stack **stack);
void		brra(t_stack **stack);
void		bft_rrb(t_stack **stack);
void		brrb(t_stack **stack);
void		bft_rrr(t_stack **stack_a, t_stack **stack_b);
void		bft_pa(t_stack **stack, t_stack **stack2);
void		bft_pb(t_stack **stack, t_stack **stack2);
void		bft_sa(t_stack **stack_a);
void		bft_sb(t_stack **stack_b);
int			ft_atoi(const char *nptr);
int			ft_check_arg2(int ac, char **av);
int			ft_check_arg(int ac, char **av);
void		create_stack(t_stack **stack_a, int ac, char **av);
void		initialise_index(t_stack **stack_a);
void		initialise_indexto1(t_stack **stack_a);
void		initialise_pos(t_stack **stack_a);
void		initialise_pos_size1(t_stack **stack_a);
int			save_max_index(t_stack *stack_a);
void		tmplis(t_stack **stack_a, t_stack **tmp_b);
void		push_lis(t_stack **stack_a, t_stack **stack_b, int pos);
void		initialise_tmplis(t_stack **stack_a, t_stack **stack_b,
				int max_index);
void		create_lis(t_stack **stack_a, t_stack **tmp_lis, t_stack **stack_b);
int			stack_chr(t_stack **tmplis, t_stack **stack_a);
int			ft_check_lis_pos(t_stack **stack_a, t_stack **tmp_lis);
void		futur_pos3(t_stack **stack_a, t_stack **stack_b);
void		futur_pos2(t_stack **stack_a, t_stack **stack_b);
void		initialise_futur_pos(t_stack **stack_a, t_stack **stack_b);
void		initialise_best_push(t_stack **stack_a);
int			push_min(t_stack **stack_a);
void		push(t_stack **stack_a, t_stack **stack_b);
void		push2(t_stack **stack_a, t_stack **stack_b, int pos, int futur_pos);
void		push3(t_stack **stack_a, t_stack **stack_b, int pos, int futur_pos);
void		push4(t_stack **stack_a, t_stack **stack_b, int pos, int futur_pos);
void		check_push34(t_stack **stack_a, t_stack **stack_b,
				int pos, int f_pos);
void		best_push(t_stack **stack_a, t_stack **stack_b);
void		index_sort(t_stack **stack_a);
int			already_sort(t_stack **stack_a);
void		little_sort(t_stack **stack_a, t_stack **stack_b);
void		sort_of3(t_stack **stack_a);
void		sort_of4(t_stack **stack_a, t_stack **stack_b);
void		sort_of5(t_stack **stack_a, t_stack **stack_b);
void		less_than5(t_stack **stack_a, t_stack **stack_b);
void		exit_error(void);
void		free_stack(t_stack **stack);
int			ft_strcmp(char *s1, char *s2);
void		instruction(t_bstack **stack, t_stack **stack_a, t_stack **stack_b);
void		wrong_instruction(t_bstack **stack);
void		instruction2(t_bstack **stack, t_stack **stack_a,
				t_stack **stack_b);
void		checker(t_stack **stack_a, t_stack **stack_b);
t_bstack	*ft_stacklast2(t_bstack *stack);
void		ft_stackadd_back2(t_bstack **astack);
void		f_stack(t_bstack **stack);
void		free_stack_str(t_bstack **stack);
void		free_checker(t_stack **stack_a, t_stack **stack_b);
#endif
