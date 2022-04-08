#include "push_swap.h"

void	initialise_index(t_stack **stack_a)
{
	t_stack	*tmp_a;
	t_stack	*i;
	t_stack	*j;

	tmp_a = *stack_a;
	i = *stack_a;
	j = tmp_a->next;
	while (tmp_a != NULL)
	{
		tmp_a->lis_index = 1;
		tmp_a = tmp_a->next;
	}
	tmp_a = *stack_a;
	while (j != NULL)
	{
		if ((j->value > i->value) && (i->lis_index + 1 > j->lis_index))
			j->lis_index = i->lis_index + 1;
		if (j->value < i->value)
			j->lis_index = 1;
		if (i->next == j)
		{
			j = j->next;
			i = tmp_a;
		}
		else
			i = i->next;
	}
}

void	initialise_pos(t_stack **stack_a)
{
	t_stack	*tmp_a;
	int		i;
	int		tmp;
	int		pos;

	tmp_a = *stack_a;
	i = 0;
	tmp = 0;
	if (ft_stacksize(*stack_a) % 2 != 0)
		tmp = -1;
	pos = (-ft_stacksize(*stack_a) / 2) + tmp;
	while (tmp_a != NULL)
	{
		if (i < ft_stacksize(*stack_a) / 2)
			tmp_a->pos = i;
		i++;
		if (i > ft_stacksize(*stack_a) / 2)
		{
			tmp_a->pos = pos;
			pos++;
		}
		tmp_a = tmp_a->next;
	}
	tmp_a = *stack_a;
	if (ft_stacksize(*stack_a) == 1)
		tmp_a->pos = 0;
}

void initialise_tmplis(t_stack **stack_a, t_stack **tmp_lis, int max_index)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp2 = *tmp_lis;
	tmp = *stack_a;
	while (tmp->lis_index != max_index)
		tmp = tmp->next;
	if (tmp2)
	{	
		if (tmp->value < tmp2->value)
			tmplis(tmp_lis, &tmp);
		else if (tmp->value > tmp2->value)
		{
           
			while ((tmp->value > tmp2->value) || (tmp->lis_index != max_index))
				tmp = tmp->next;
			tmplis(tmp_lis, &tmp);
        }
	}
	else
		tmplis(tmp_lis, &tmp);
}

void    initialise_best_push(t_stack **stack_a)
{
    t_stack *tmp_a;

    tmp_a = *stack_a;
    while (tmp_a != NULL)
    {
        if (tmp_a->pos > 0 && tmp_a->futur_pos > 0)
            tmp_a->best_push = return_max(tmp_a->pos, tmp_a->futur_pos);
        else if (tmp_a->pos < 0 && tmp_a->futur_pos < 0)
            tmp_a->best_push = return_max(tmp_a->pos, tmp_a->futur_pos);
        else
            tmp_a->best_push = abs(tmp_a->pos) + abs(tmp_a->futur_pos);
        tmp_a = tmp_a->next;
    }
}