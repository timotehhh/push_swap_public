/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 09:12:34 by trouger           #+#    #+#             */
/*   Updated: 2021/09/23 15:42:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_find_chunk_size(t_list *chunk)
{
	int	i;
	int	index;

	i = 0;
	index = chunk->chunk_index;
	while (chunk != NULL && chunk->chunk_index == index)
	{
		i++;
		chunk = chunk->next;
	}
	return (i);
}

t_list	*ft_find_next_chunk(t_stack stack)
{
	if (stack.a == NULL)
		return (stack.b);
	if (stack.b == NULL)
		return (stack.a);
	if (stack.b->chunk_index > stack.a->chunk_index)
		return (stack.b);
	return (stack.a);
}

char	ft_find_next_stack(t_stack stack)
{
	if (stack.b && stack.a)
	{
		if (stack.a->chunk_index < stack.b->chunk_index)
			return ('b');
	}
	if (stack.a)
		return ('a');
	return ('b');
}

int	ft_find_next_chunk_size(t_list *chunk)
{
	int	i;
	int	index;

	i = 0;
	index = chunk->chunk_index;
	while (chunk != NULL && chunk->chunk_index == index)
	{
		i++;
		chunk = chunk->next;
	}
	return (i / 2);
}
