/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_2_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:46:31 by trouger           #+#    #+#             */
/*   Updated: 2021/09/20 13:57:36 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	ft_sort_2_nbr(t_stack stack, char next_stack)
{
	if (next_stack == 'a')
	{
		if (stack.a->content > stack.a->next->content)
			stack = ft_sa(stack);
	}
	else if (next_stack == 'b')
	{
		if (stack.b->content < stack.b->next->content)
			stack = ft_sb(stack);
	}
	return (stack);
}
