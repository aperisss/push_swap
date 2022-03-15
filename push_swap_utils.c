#include "push_swap.h"

t_stack	*ft_stacklast(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	ft_stackadd_back(t_stack **astack, int i, char **av)
{
    t_stack *new;
    new = malloc(sizeof(t_stack));
    new->value = ft_atoi(av[i]);
	if (*astack)
		ft_stacklast(*astack)->next = new;
	else
		*astack = new;
}

void	ft_lstadd_front(t_stack **alst, t_stack *new)
{
	if (*alst)
	{
		new->next = *alst;
		*alst = new;
	}
	else
		*alst = new;
}