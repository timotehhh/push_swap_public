/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_hundred.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:55:20 by trouger           #+#    #+#             */
/*   Updated: 2021/10/25 14:07:22 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	ft_sort_hundred(t_stack stack, int *index)
{
	t_list	*stack_end;
	t_list	*temp;

	temp = stack.a;
	stack_end = ft_lstlast(stack.a);
	while (stack.a)
	{
		stack = ft_mark_small_chunk(stack, index);
		while (!(ft_check_chunk_gone(stack, index)))
		{
			stack = ft_push_nb_to_b(stack, stack_end, temp, index);
			temp = stack.a;
			stack_end = ft_lstlast(stack.a);
		}
		(*index)++;
	}
	return (ft_end_sort_hundred(stack, index));
}

t_stack	ft_mark_small_chunk(t_stack stack, int *index)
{
	int		i;
	t_list	*smallest;
	t_list	*temp;

	i = 0;
	temp = stack.a;
	smallest = NULL;
	while (i < 20)
	{
		smallest = ft_find_smallest(stack, smallest, index);
		while (stack.a)
		{
			if (stack.a->content < smallest->content
				&& stack.a->chunk_index != (*index))
				smallest = stack.a;
			stack.a = stack.a->next;
		}
		stack.a = smallest;
		stack.a->chunk_index = (*index);
		stack.a = temp;
		i++;
	}
	return (stack);
}

int	ft_check_chunk_gone(t_stack stack, int *index)
{
	while (stack.a)
	{
		if (stack.a->chunk_index == (*index))
			return (0);
		stack.a = stack.a->next;
	}
	return (1);
}

t_stack	ft_push_nb_to_b(t_stack stack, t_list *end, t_list *temp, int *index)
{
	int	i;
	int	j;
	int	previous;

	i = 0;
	j = 0;
	previous = 1;
	while (stack.a && stack.a->chunk_index != (*index))
	{
		i++;
		stack.a = stack.a->next;
	}
	while (end != stack.a && end->chunk_index != (*index))
	{
		j++;
		end = ft_lst_point_end(stack.a, previous);
		previous++;
	}
	stack.a = temp;
	if (i <= j)
		stack = ft_push_nb_r(stack, index, 'A');
	else
		stack = ft_push_nb_rr(stack, index, 'A');
	return (stack);
}

t_stack	ft_push_nb_rr(t_stack stack, int *index, char main_stack)
{
	if (main_stack == 'B')
	{
		while (stack.b->next && stack.b->chunk_index != (*index))
			stack = ft_rrb(stack);
		stack = ft_pa(stack, index, 0);
		return (stack);
	}
	while (stack.a->next && stack.a->chunk_index != (*index))
		stack = ft_rra(stack);
	stack = ft_pb(stack, index, 0);
	return (stack);
}	
