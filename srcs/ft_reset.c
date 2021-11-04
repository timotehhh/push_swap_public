/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 11:02:19 by trouger           #+#    #+#             */
/*   Updated: 2021/09/20 14:42:03 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	ft_reset_chunk_index(t_stack stack, t_list *chunk, char next_stack)
{
	int		index;
	t_list	*temp;

	index = chunk->chunk_index;
	temp = chunk;
	chunk = ft_reset2(stack, chunk, next_stack, index);
	chunk = temp;
	if (next_stack == 'a')
		stack.a = chunk;
	else if (next_stack == 'b')
		stack.b = chunk;
	return (stack);
}

t_list	*ft_reset2(t_stack stack, t_list *chunk, char next_stack, int index)
{
	while (chunk != NULL && chunk->chunk_index == index)
	{
		if (next_stack == 'a')
		{
			if (stack.b)
				chunk->chunk_index = stack.b->chunk_index;
			else
				chunk->chunk_index = 0;
		}
		if (next_stack == 'b')
		{
			if (stack.a)
				chunk->chunk_index = stack.a->chunk_index;
			else
				chunk->chunk_index = 0;
		}
		chunk = chunk->next;
	}
	return (chunk);
}
