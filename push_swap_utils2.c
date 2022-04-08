#include "push_swap.h"

int abs(int a)
{
    if (a < 0)
        return (-a);
    return (a);
}

int	return_max(int a, int b)
{
	if (a > 0 && b > 0)
	{
		if ( a > b)
			return (a);
		else
			return (b);
	}
	if (a < 0 && b < 0)
	{
		if (a < b)
			return (-a);
		else
			return (-b);
	}
	return (0);
}

int	return_min(int a, int b)
{
	if (a > 0 && b > 0)
	{
		if ( a > b)
			return (b);
		else
			return (a);
	}
	if (a < 0 && b < 0)
	{
		if (a < b)
			return (-b);
		else
			return (-a);
	}
	return (0);
}

int	already_sort(t_stack **stack_a)
{
	t_stack *tmp_a;

	tmp_a = *stack_a;
	while (tmp_a->next)
	{
		if (tmp_a->value > tmp_a->next->value)
			return (0);
		tmp_a = tmp_a->next;
	}
	return (1);
}