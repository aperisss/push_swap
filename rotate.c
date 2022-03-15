#include "push_swap.h"

// t_stack ft_ra(t_stack *stack_a)
// {
//     int i;
//     int tmp;
//     int first;

//     first = stack->value;
//     i = 0;
//     while( i < (stack_a->stacksize / 2))
//     {
//             i++;
//             tmp = stack_a->next->value;
//             stack_a->next->value = stack_a->value;
//             stack_a->next->next->value = tmp;
//             stack_a = stack_a->next;
//     }
//     return (*stack_a);
// }

t_stack ft_ra(t_stack *stack_a)
{
    t_stack *tmp;
    t_stack *first;
    
    int i;

    tmp = stack_a;
    while ( i != stack_a->stacksize)
    {
        stack_a = stack_a->next;
        i++;
    }
    first->value = stack_a->value;
    free (stack_a);
    i = 0;
     while ( i < stack_a->stacksize)
    {
        i++;
        printf("|%d \n", stack_a->value);
        stack_a = stack_a->next;
    }
    ft_stackadd_front(&tmp, first);
    ft_stacklastcircle(tmp)->next = tmp;
    return (*tmp);
}
