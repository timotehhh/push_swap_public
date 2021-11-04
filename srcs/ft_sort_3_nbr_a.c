/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3_nbr_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:31:56 by trouger           #+#    #+#             */
/*   Updated: 2021/09/20 14:33:32 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	ft_sort_3_nbr(t_stack stack, char next_stack)
{
	if (next_stack == 'a')
		stack = ft_sort_3_nbr_a(stack);
	if (next_stack == 'b')
		stack = ft_sort_3_nbr_b(stack);
	return (stack);
}

t_stack	ft_sort_3_nbr_a(t_stack stack)
{
	if (stack.a->content > stack.a->next->content
		&& stack.a->content < stack.a->next->next->content)
		stack = ft_sa(stack);
	if (ft_lstsize(stack.a) > 3)
	{
		stack = ft_sort_3_nbr_a_long(stack);
		return (stack);
	}
	stack = ft_sort_3_nbr_a2(stack);
	return (stack);
}

t_stack	ft_sort_3_nbr_a2(t_stack stack)
{
	if (stack.a->content < stack.a->next->next->content
		&& stack.a->next->content > stack.a->next->next->content)
	{
		stack = ft_sa(stack);
		stack = ft_ra(stack);
	}
	else if (stack.a->content < stack.a->next->content
		&& stack.a->content > stack.a->next->next->content)
		stack = ft_rra(stack);
	else if (stack.a->content > stack.a->next->content
		&& stack.a->next->content > stack.a->next->next->content)
	{
		stack = ft_ra(stack);
		stack = ft_sa(stack);
	}
	else if (stack.a->content > stack.a->next->next->content
		&& stack.a->next->content < stack.a->next->next->content)
		stack = ft_ra(stack);
	return (stack);
}

t_stack	ft_sort_3_nbr_a_long(t_stack stack)
{
	if (stack.a->content < stack.a->next->next->content
		&& stack.a->next->content > stack.a->next->next->content)
	{
		stack = ft_sa(stack);
		stack = ft_ra(stack);
		stack = ft_rra(stack);
	}
	else if (stack.a->content < stack.a->next->content
		&& stack.a->content > stack.a->next->next->content)
	{
		stack = ft_ra(stack);
		stack = ft_sa(stack);
		stack = ft_rra(stack);
		stack = ft_sa(stack);
	}
	else
		stack = ft_sort_3_nbr_a_long2(stack);
	return (stack);
}

t_stack	ft_sort_3_nbr_a_long2(t_stack stack)
{
	if (stack.a->content > stack.a->next->content
		&& stack.a->next->content > stack.a->next->next->content)
	{
		stack = ft_sa(stack);
		stack = ft_ra(stack);
		stack = ft_sa(stack);
		stack = ft_rra(stack);
		stack = ft_sa(stack);
	}
	else if (stack.a->content > stack.a->next->next->content
		&& stack.a->next->content < stack.a->next->next->content)
	{
		stack = ft_sa(stack);
		stack = ft_ra(stack);
		stack = ft_sa(stack);
		stack = ft_rra(stack);
	}
	return (stack);
}
