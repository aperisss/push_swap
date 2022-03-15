#include "push_swap.h"

void	ft_stackadd_front(t_stack **astack, t_stack *new)
{
	if (*astack)
	{
		new->next = *astack;
		*astack = new;
	}
	else
		*astack = new;
}

int	ft_stacksize(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

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

t_stack	*ft_stacklastcircle(t_stack *stack)
{
	int i;

	i = 0;
	while (i < stack->stacksize)
	{
		i++;
		stack = stack->next;
	}
	return (stack);
}