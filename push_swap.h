#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include  <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
	int value;
	struct s_stack *next;
}	t_stack;

void	ft_stackadd_back(t_stack **astack, int i, char **av);
void	ft_lstadd_front(t_stack **alst, t_stack *new);
t_stack	*ft_stacklast(t_stack *stack);
void	ft_ra(t_stack *stack);
t_stack *ft_rb(t_stack *stack);
t_stack *ft_rra(t_stack *stack);
t_stack *ft_rrb(t_stack *stack);
int	ft_atoi(const char *nptr);
t_stack create_stack(int ac, char **av);


#endif