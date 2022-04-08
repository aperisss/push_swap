#include "push_swap.h"

void    little_sort(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_b;

    tmp_b = *stack_b;
    initialise_pos(stack_a);
    initialise_pos(stack_b);
    initialise_futur_pos(&tmp_b, stack_a);
    if (tmp_b->futur_pos > 0)
	{
		while (tmp_b->futur_pos > 0)
		{
			ft_ra(stack_a);
			tmp_b->futur_pos--;
		}
		ft_pa(stack_b, stack_a);
	}
	else if (tmp_b->futur_pos < 0)
	{
		while (tmp_b->futur_pos < 0)
		{
			ft_rra(stack_a);
			tmp_b->futur_pos++;
		}
		ft_pa(stack_b, stack_a);
    }
    else
        ft_pa(stack_b, stack_a);
}


void    sort_of3(t_stack **stack_a)
{
    t_stack *t;

    t = *stack_a;
    if (t->value > t->next->value && t->value < t->next->next->value)
        ft_sa(stack_a);
    else if (t->value > t->next->value && 
        t->next->value > t->next->next->value)
        {
            ft_sa(stack_a);
            ft_rra(stack_a);
        }
    else if (t->value > t->next->value && 
        t->next->value < t->next->next->value)
        ft_ra(stack_a);
    else if (t->value < t->next->value && 
        t->value < t->next->next->value)
        {
            ft_sa(stack_a);
            ft_ra(stack_a);
        }
    else if (t->value < t->next->value && 
        t->next->value > t->next->next->value)
        ft_rra(stack_a);
}

void    sort_of4(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_a;

    tmp_a = *stack_a;
    ft_pb(stack_a, stack_b);
    if (already_sort(stack_a) != 1)
        sort_of3(stack_a);
    little_sort(stack_a, stack_b);
    index_sort(stack_a);
}

void    sort_of5(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_a;

    tmp_a = *stack_a;
    ft_pb(stack_a, stack_b);
    ft_pb(stack_a, stack_b);
    if (already_sort(stack_a) != 1)
        sort_of3(stack_a);
    little_sort(stack_a, stack_b);
    little_sort(stack_a, stack_b);
    index_sort(stack_a);
    
}

void    less_than5(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_a;

    tmp_a = *stack_a;
    if (ft_stacksize(*stack_a) == 2)
    {
        if (tmp_a->value > tmp_a->next->value)
        ft_sa(stack_a);
    }
    if (ft_stacksize(*stack_a) == 3)
        sort_of3(stack_a);
    if (ft_stacksize(*stack_a) == 4)
        sort_of4(stack_a, stack_b);
    if (ft_stacksize(*stack_a) == 5)
        sort_of5(stack_a, stack_b);
}