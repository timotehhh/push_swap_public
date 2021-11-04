/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3_nbr_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:16:06 by trouger           #+#    #+#             */
/*   Updated: 2021/09/20 14:32:11 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	ft_sort_3_nbr_b(t_stack stack)
{
	if (stack.b->content < stack.b->next->content
		&& stack.b->content > stack.b->next->next->content)
		stack = ft_sb(stack);
	if (ft_lstsize(stack.b) > 3)
	{
		stack = ft_sort_3_nbr_b_long(stack);
		return (stack);
	}
	stack = ft_sort_3_nbr_b2(stack);
	return (stack);
}

t_stack	ft_sort_3_nbr_b2(t_stack stack)
{
	if (stack.b->content > stack.b->next->next->content
		&& stack.b->next->content < stack.b->next->next->content)
	{
		stack = ft_sb(stack);
		stack = ft_rb(stack);
	}
	else if (stack.b->content > stack.b->next->content
		&& stack.b->content < stack.b->next->next->content)
		stack = ft_rrb(stack);
	else if (stack.b->content < stack.b->next->content
		&& stack.b->next->content < stack.b->next->next->content)
	{
		stack = ft_sb(stack);
		stack = ft_rrb(stack);
	}
	else if (stack.b->content < stack.b->next->next->content
		&& stack.b->next->content > stack.b->next->next->content)
		stack = ft_rb(stack);
	return (stack);
}

t_stack	ft_sort_3_nbr_b_long(t_stack stack)
{
	if (stack.b->content > stack.b->next->next->content
		&& stack.b->next->content < stack.b->next->next->content)
	{
		stack = ft_rb(stack);
		stack = ft_sb(stack);
		stack = ft_rrb(stack);
	}
	else if (stack.b->content > stack.b->next->content
		&& stack.b->content < stack.b->next->next->content)
	{
		stack = ft_rb(stack);
		stack = ft_sb(stack);
		stack = ft_rrb(stack);
		stack = ft_sb(stack);
	}
	else
		stack = ft_sort_3_nbr_b_long2(stack);
	return (stack);
}

t_stack	ft_sort_3_nbr_b_long2(t_stack stack)
{
	if (stack.b->content < stack.b->next->content
		&& stack.b->next->content < stack.b->next->next->content)
	{
		stack = ft_sb(stack);
		stack = ft_rb(stack);
		stack = ft_sb(stack);
		stack = ft_rrb(stack);
		stack = ft_sb(stack);
	}
	else if (stack.b->content < stack.b->next->next->content
		&& stack.b->next->content > stack.b->next->next->content)
	{
		stack = ft_sb(stack);
		stack = ft_rb(stack);
		stack = ft_sb(stack);
		stack = ft_rrb(stack);
	}
	return (stack);
}
