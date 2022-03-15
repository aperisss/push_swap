#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include  <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
	int value;
	int stacksize;
	struct s_stack *next;
}	t_stack;

int	ft_check_arg(int ac, char **av);
int	ft_check_arg2(int ac, char **av);
void	ft_stackadd_back(t_stack **astack, int i, char **av);
void	ft_stackadd_front(t_stack **astack, t_stack *new);
int	ft_atoi(const char *nptr);
t_stack	*ft_stacklast(t_stack *stack);
int	ft_stacksize(t_stack *stack);
t_stack create_stack(int ac, char **av);
t_stack ft_ra(t_stack *stack_a);
t_stack	*ft_stacklastcircle(t_stack *stack);

#endif