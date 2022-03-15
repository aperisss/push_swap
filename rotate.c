#include "push_swap.h"

void ft_ra(t_stack *stack)
{
    t_stack *tmp;

    tmp = malloc(sizeof(t_stack));
    tmp = ft_stacklast(stack);
    tmp->next = stack;
    while(stack->next != tmp)
        stack = stack->next;
    stack->next = NULL;

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
