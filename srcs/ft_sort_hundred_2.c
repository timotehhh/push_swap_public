/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_hundred_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:26:22 by trouger           #+#    #+#             */
/*   Updated: 2021/11/01 15:28:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	ft_push_nb_r(t_stack stack, int *index, char main_stack)
{
	if (main_stack == 'B')
	{
		while (stack.b->next && stack.b->chunk_index != (*index))
			stack = ft_rb(stack);
		stack = ft_pa(stack, index, 0);
		return (stack);
	}
	while (stack.a->next && stack.a->chunk_index != (*index))
		stack = ft_ra(stack);
	stack = ft_pb(stack, index, 0);
	return (stack);
}

t_stack	ft_end_sort_hundred(t_stack stack, int *index)
{
	t_list	*stack_end;
	t_list	*temp;

	temp = stack.b;
	stack_end = ft_lstlast(stack.b);
	while (stack.b)
	{
		stack = ft_mark_biggest(stack, index);
		stack = ft_push_biggest(stack, stack_end, temp, index);
		temp = stack.b;
		(*index)++;
	}
	return (stack);
}

t_stack	ft_mark_biggest(t_stack stack, int *index)
{
	t_list	*biggest;
	t_list	*temp;

	temp = stack.b;
	biggest = stack.b;
	while (stack.b)
	{
		if (stack.b->content > biggest->content)
			biggest = stack.b;
		stack.b = stack.b->next;
	}
	stack.b = biggest;
	stack.b->chunk_index = (*index);
	stack.b = temp;
	return (stack);
}

t_stack	ft_push_biggest(t_stack stack, t_list *end, t_list *temp, int *index)
{
	int	i;
	int	j;
	int	previous;

	i = 0;
	j = 0;
	previous = 0;
	while (stack.b && stack.b->chunk_index != (*index))
	{
		i++;
		stack.b = stack.b->next;
	}
	while (end->chunk_index != (*index))
	{
		j++;
		end = ft_lst_point_end(stack.b, previous);
		previous++;
	}
	stack.b = temp;
	if (i <= j)
		stack = ft_push_nb_r(stack, index, 'B');
	else
		stack = ft_push_nb_rr(stack, index, 'B');
	return (stack);
}

t_list	*ft_lst_point_end(t_list *stack, int previous)
{
	int	i;

	i = ft_lstsize(stack) - 1;
	while (stack && i > previous)
	{
		stack = stack->next;
		i = i - 1;
	}
	return (stack);
}
