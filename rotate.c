#include "push_swap.h"

void ft_ra(t_stack *stack)
{
    t_stack *tmp;
    t_stack *tmp2;

    tmp2 = malloc(sizeof(t_stack));
    tmp = malloc(sizeof(t_stack));
    tmp2 = stack;
     printf(" astack = %d\n", stack->value);
    tmp = ft_stacklast(stack);
    while(tmp2->next != tmp)
        tmp2 = tmp2->next;
    tmp2->next = NULL;  
    tmp->next = stack;
    stack = tmp;
  
    printf(" stack = %d\n", stack->value);
    printf(" stack = %d\n", stack->next->value);
    printf(" stack = %d\n", stack->next->next->value);

}

// t_stack *ft_ra(t_stack *stack)
// {
//     t_stack *tmp;

//     tmp = malloc(sizeof(t_stack));
//     tmp = ft_stacklast(stack);
//     tmp->next = stack;
//     while(stack->next != tmp)
//         stack = stack->next;
//     stack->next = NULL;
//     return(tmp);
// }

t_stack *ft_rb(t_stack *stack)
{
    t_stack *tmp;

    tmp = malloc(sizeof(t_stack));
    tmp = ft_stacklast(stack);
    tmp->next = stack;
    while(stack->next != tmp)
        stack = stack->next;
    stack->next = NULL;
    return(tmp);
}

t_stack *ft_rra(t_stack *stack)
{
    t_stack *tmp;

    tmp = malloc(sizeof(t_stack));
    tmp = stack->next;
   
    ft_stacklast(stack)->next = stack;
    stack->next = NULL;
    return (tmp);
}

t_stack *ft_rrb(t_stack *stack)
{
    t_stack *tmp;

    tmp = malloc(sizeof(t_stack));
    tmp = stack->next;
   
    ft_stacklast(stack)->next = stack;
    stack->next = NULL;
    return (tmp);
}
