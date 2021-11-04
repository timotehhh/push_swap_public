/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 07:24:39 by marvin            #+#    #+#             */
/*   Updated: 2021/10/07 17:22:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_redirect(t_stack stack, int *index)
{
	t_list	*next_chunk;
	char	next_stack;

	next_chunk = ft_find_next_chunk(stack);
	next_stack = ft_find_next_stack(stack);
	if (ft_check_chunk_sorted(next_chunk, next_stack, stack.b) == 2)
	{
		ft_print(stack.toprint, stack);
		return ;
	}
	if (ft_check_chunk_sorted(next_chunk, next_stack, stack.b) == 1)
	{
		stack = ft_reset_chunk_index(stack, next_chunk, next_stack);
		stack = ft_push(stack, index, next_stack);
		ft_redirect(stack, index);
	}
	else
		ft_redirect2(stack, index, next_chunk, next_stack);
}

void	ft_redirect2(t_stack stack, int *index, t_list *chunk, char next_stack)
{
	if (!(ft_check_chunk_sorted(chunk, next_stack, stack.b)))
	{
		if (ft_find_chunk_size(chunk) == 2
			|| ft_find_chunk_size(chunk) == 3)
		{
			if (ft_find_chunk_size(chunk) == 2)
				stack = ft_sort_2_nbr(stack, next_stack);
			else if (ft_find_chunk_size(chunk) == 3)
				stack = ft_sort_3_nbr(stack, next_stack);
			ft_redirect(stack, index);
		}
		else
		{
			if (next_stack == 'a')
				ft_create_chunks_a(stack, index);
			else if (next_stack == 'b')
				ft_create_chunks_b(stack, index);
		}
	}
}
