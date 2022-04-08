#include "push_swap.h"

void futur_pos3(t_stack **stack_a, t_stack **stack_b)
{
    int max;
    t_stack *tmp_a;
    t_stack *tmp_b;

    max = 0;
    tmp_a = *stack_a;
    tmp_b = *stack_b;
    while(tmp_b != NULL)
    {
        if (tmp_b->value > max)
            max = tmp_b->value;
        tmp_b = tmp_b->next;
    }
    tmp_b = *stack_b;
    while (tmp_b->value != max)
        tmp_b = tmp_b->next;
    tmp_a->futur_pos = tmp_b->pos + 1;
}

void futur_pos2(t_stack **stack_a, t_stack **stack_b)
{
    int     i;
    t_stack *tmp_b;
    t_stack *tmp_a;

    i = 0;
    tmp_b = *stack_b;
    tmp_a = *stack_a;
    while (tmp_b->next != NULL)
    {
        if (tmp_a->value > tmp_b->value && tmp_a->value < tmp_b->next->value)
        {
            i = 1;
            tmp_a->futur_pos = tmp_b->next->pos;
        }
        tmp_b = tmp_b->next;
    }
    if ( i == 0)
        futur_pos3(stack_a, stack_b);
}

void initialise_futur_pos(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;
    t_stack *tmp_b;
    t_stack *tmp_a;

    tmp_a = *stack_a;
    tmp_b = *stack_b;
    while (tmp_a != NULL)
    {
        while (tmp_b->next != NULL)
            tmp_b = tmp_b->next;
        tmp = tmp_b;
        tmp_b = *stack_b;
        if (tmp_a->value < tmp_b->value && tmp_a->value > tmp->value)
            tmp_a->futur_pos = 0;
        else
            futur_pos2(&tmp_a, stack_b);
        tmp_a = tmp_a->next;
    }
}