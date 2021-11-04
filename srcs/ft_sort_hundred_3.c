/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_hundred_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:07:44 by trouger           #+#    #+#             */
/*   Updated: 2021/10/25 14:08:06 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*ft_find_smallest(t_stack stack, t_list *s, int *index)
{
	if (stack.a->chunk_index != (*index))
		s = stack.a;
	else
	{
		while (stack.a->chunk_index == (*index))
			stack.a = stack.a->next;
		s = stack.a;
	}
	return (s);
}
