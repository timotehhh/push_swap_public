/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: trouger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:42:49 by trouger           #+#    #+#             */
/*   Updated: 2021/09/20 13:55:25 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	ft_push(t_stack stack, int *index, char c)
{
	int	i;

	i = 0;
	if (c == 'b')
	{
		i = stack.b->chunk_index;
		while (stack.b != NULL && stack.b->chunk_index == i)
			stack = ft_pa(stack, index, 1);
	}
	if (c == 'a')
	{
		i = stack.a->chunk_index;
		while (stack.a != NULL && stack.a->chunk_index == i)
			stack = ft_pb(stack, index, 1);
	}
	return (stack);
}
