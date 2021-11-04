/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands_A.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 09:55:26 by trouger           #+#    #+#             */
/*   Updated: 2021/10/22 14:59:28 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	ft_pb(t_stack stack, int *index, int push)
{
	t_list	*temp;

	temp = stack.a->next;
	ft_lstadd_front(&(stack.b), stack.a);
	stack.b = stack.a;
	stack.a = temp;
	if (push == 0)
		stack.b->chunk_index = *index;
	ft_lstadd_back_toprint(stack.toprint->first, ft_lstnew_toprint(5));
	return (stack);
}

t_stack	ft_rra_pb(t_stack stack, int *index)
{
	t_list	*temp;

	temp = ft_lstlast(stack.a);
	ft_lst_beforelast(stack.a)->next = NULL;
	temp->next = stack.a;
	stack.a = temp;
	temp = stack.a->next;
	ft_lstadd_front(&(stack.b), stack.a);
	stack.b = stack.a;
	stack.a = temp;
	stack.b->chunk_index = *index;
	ft_lstadd_back_toprint(stack.toprint->first, ft_lstnew_toprint(9));
	ft_lstadd_back_toprint(stack.toprint->first, ft_lstnew_toprint(5));
	return (stack);
}

t_stack	ft_rra(t_stack stack)
{
	t_list	*temp;

	temp = ft_lstlast(stack.a);
	ft_lst_beforelast(stack.a)->next = NULL;
	temp->next = stack.a;
	stack.a = temp;
	temp = stack.a->next;
	ft_lstadd_back_toprint(stack.toprint->first, ft_lstnew_toprint(9));
	return (stack);
}

t_stack	ft_ra(t_stack stack)
{
	t_list	*temp;

	temp = stack.a->next;
	ft_lstlast(temp)->next = stack.a;
	stack.a->next = NULL;
	stack.a = temp;
	ft_lstadd_back_toprint(stack.toprint->first, ft_lstnew_toprint(1));
	return (stack);
}

t_stack	ft_sa(t_stack stack)
{
	t_list	*temp;

	temp = stack.a->next;
	stack.a->next = stack.a->next->next;
	ft_lstadd_front(&(stack.a), temp);
	ft_lstadd_back_toprint(stack.toprint->first, ft_lstnew_toprint(6));
	return (stack);
}
