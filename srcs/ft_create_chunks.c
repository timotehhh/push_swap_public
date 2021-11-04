/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_chunks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:16:05 by trouger           #+#    #+#             */
/*   Updated: 2021/10/25 11:32:52 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_create_chunks_a(t_stack stack, int *index)
{
	int	i;
	int	rra;

	i = 0;
	rra = 0;
	if (ft_check_finish(stack.a, stack.b))
		return ;
	while (ft_find_chunk_size(stack.a) > 3)
	{
		stack = ft_create_chunks_a2(stack, index, i, rra);
		(*index)++;
	}
	if (ft_find_chunk_size(stack.a) == 2)
		stack = ft_sort_2_nbr(stack, 'a');
	if (ft_find_chunk_size(stack.a) == 3)
		stack = ft_sort_3_nbr(stack, 'a');
	ft_redirect(stack, index);
}

t_stack	ft_create_chunks_a2(t_stack stack, int *index, int i, int rra)
{
	int	mid_value;
	int	chunk_size;

	mid_value = ft_find_mid_a(stack.a);
	chunk_size = ft_find_next_chunk_size(stack.a);
	i = 0;
	rra = 1;
	while (i < chunk_size)
	{
		if (stack.a->content < mid_value && ++i >= 0)
			stack = ft_pb(stack, index, 0);
		else
		{
			if (ft_lstlast(stack.a)->content < mid_value && ++i >= 0)
				stack = ft_rra_pb(stack, index);
			else if (++rra)
				stack = ft_ra(stack);
		}
	}
	while (--rra)
		stack = ft_rra(stack);
	return (stack);
}

void	ft_create_chunks_b(t_stack stack, int *index)
{
	int		i;
	int		rrb;

	i = 0;
	rrb = 0;
	if (ft_check_finish(stack.a, stack.b))
		return ;
	while (ft_find_chunk_size(stack.b) > 3)
	{
		stack = ft_create_chunks_b2(stack, index, i, rrb);
		(*index)++;
	}
	if (ft_find_chunk_size(stack.b) == 2)
		stack = ft_sort_2_nbr(stack, 'b');
	if (ft_find_chunk_size(stack.b) == 3)
		stack = ft_sort_3_nbr(stack, 'b');
	ft_redirect(stack, index);
}

t_stack	ft_create_chunks_b2(t_stack stack, int *index, int i, int rrb)
{
	int		mid_value;
	int		chunk_size;

	mid_value = ft_find_mid_b(stack.b);
	chunk_size = ft_find_next_chunk_size(stack.b);
	i = 0;
	rrb = 1;
	while (i < chunk_size)
	{
		if (stack.b->content > mid_value && ++i >= 0)
			stack = ft_pa(stack, index, 0);
		else
		{
			if (ft_lstlast(stack.b)->content > mid_value && ++i >= 0)
				stack = ft_rrb_pa(stack, index);
			else if (++rrb)
				stack = ft_rb(stack);
		}
	}
	while (--rrb)
		stack = ft_rrb(stack);
	return (stack);
}
