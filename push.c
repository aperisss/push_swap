#include "push_swap.h"

int push_min(t_stack **stack_a)
{
    int push_min;
    t_stack *tmp_a;

    tmp_a = *stack_a;
    push_min = tmp_a->best_push;
    while (tmp_a != NULL)
    {
        if (tmp_a->best_push < push_min)
            push_min = tmp_a->best_push;
        tmp_a = tmp_a->next;
    }
    return (push_min);
}

void    push4(t_stack **stack_a, t_stack **stack_b, int pos, int futur_pos)
{
    if (pos > 0)
    {
        while (pos > 0)
        {
            ft_ra(stack_a);
            pos--;
        }
        while (futur_pos < 0)
        {
            ft_rrb(stack_b);
            futur_pos++;
        }
    }
    else if (futur_pos > 0)
    {
        while (futur_pos > 0)
        {
            ft_rb(stack_b);
            futur_pos--;
        }
        while (pos < 0)
        {
            ft_rra(stack_a);
            pos++;
        }
    }
}

void    push3(t_stack **stack_a, t_stack **stack_b, int pos, int futur_pos)
{
    if (pos > 0)
    {
        while ( pos != 0)
        {
            ft_ra(stack_a);
            pos--;
        }
    }
    else if (pos < 0)
    {
        while (pos != 0)
        {
            ft_rra(stack_a);
            pos++;
        }
    }
    else if (futur_pos > 0)
    {
        while (futur_pos != 0)
        {
            ft_rb(stack_b);
            futur_pos--;
        }
    }
    else if (futur_pos < 0)
    {
        while (futur_pos != 0)
        {
            ft_rrb(stack_b);
            futur_pos++;
        }
    }
}

void    push2(t_stack **stack_a, t_stack **stack_b, int pos, int futur_pos)
{
    t_stack *tmp_a;
    t_stack *tmp_b;
    int i;

    tmp_a = *stack_a;
    tmp_b = *stack_b;
    i = 0;
    if (pos < 0 && futur_pos < 0)
    {
        while (i < return_min(pos, futur_pos))
        {
            ft_rrr(stack_a, stack_b);
            i++;
        }
        while (i < return_max(pos, futur_pos))
        {
            if (pos > futur_pos)
                ft_rrb(stack_b);
            else if (pos < futur_pos)
                ft_rra(stack_a);
            i++;
        }
    }
    if ((pos == 0 && futur_pos != 0)
         || (pos != 0 && futur_pos == 0))
         push3(stack_a, stack_b, pos, futur_pos);
    if ((pos > 0 && futur_pos < 0) || (pos < 0 && futur_pos > 0))
        push4(stack_a, stack_b, pos, futur_pos);
    ft_pa(stack_a, stack_b);
}


void    push(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_a;
    t_stack *tmp_b;
    int i;

    tmp_a = *stack_a;
    tmp_b = *stack_b;
    i = 0;
    while( tmp_a->best_push != push_min(stack_a))
            tmp_a = tmp_a->next;
    if (tmp_a->pos > 0 && tmp_a->futur_pos > 0)
    {
        while (i < return_min(tmp_a->pos, tmp_a->futur_pos))
        {
            ft_rr(stack_a, stack_b);
            i++;
        }
        while ( i < return_max(tmp_a->pos, tmp_a->futur_pos))
        {
            if (tmp_a->pos > tmp_a->futur_pos)
                ft_ra(stack_a);
            else if ( tmp_a->pos < tmp_a->futur_pos)
                ft_rb(stack_b);
            i++;
        }
    }
    push2(stack_a, stack_b, tmp_a->pos, tmp_a->futur_pos);
}