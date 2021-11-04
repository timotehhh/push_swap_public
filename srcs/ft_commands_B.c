/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands_B.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:10:57 by trouger           #+#    #+#             */
/*   Updated: 2021/10/22 14:56:56 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	ft_pa(t_stack stack, int *index, int push)
{
	t_list	*temp;

	temp = stack.b->next;
	ft_lstadd_front(&(stack.a), stack.b);
	stack.a = stack.b;
	stack.b = temp;
	if (push == 0)
		stack.a->chunk_index = *index;
	ft_lstadd_back_toprint(stack.toprint->first, ft_lstnew_toprint(4));
	return (stack);
}

t_stack	ft_rrb_pa(t_stack stack, int *index)
{
	t_list	*temp;

	temp = ft_lstlast(stack.b);
	ft_lst_beforelast(stack.b)->next = NULL;
	temp->next = stack.b;
	stack.b = temp;
	temp = stack.b->next;
	ft_lstadd_front(&(stack.a), stack.b);
	stack.a = stack.b;
	stack.b = temp;
	stack.a->chunk_index = *index;
	ft_lstadd_back_toprint(stack.toprint->first, ft_lstnew_toprint(10));
	ft_lstadd_back_toprint(stack.toprint->first, ft_lstnew_toprint(4));
	return (stack);
}

t_stack	ft_rrb(t_stack stack)
{
	t_list	*temp;

	temp = ft_lstlast(stack.b);
	ft_lst_beforelast(stack.b)->next = NULL;
	temp->next = stack.b;
	stack.b = temp;
	temp = stack.b->next;
	ft_lstadd_back_toprint(stack.toprint->first, ft_lstnew_toprint(10));
	return (stack);
}

t_stack	ft_rb(t_stack stack)
{
	t_list	*temp;

	temp = stack.b->next;
	ft_lstlast(temp)->next = stack.b;
	stack.b->next = NULL;
	stack.b = temp;
	ft_lstadd_back_toprint(stack.toprint->first, ft_lstnew_toprint(2));
	return (stack);
}

t_stack	ft_sb(t_stack stack)
{
	t_list	*temp;

	temp = stack.b->next;
	stack.b->next = stack.b->next->next;
	ft_lstadd_front(&(stack.b), temp);
	ft_lstadd_back_toprint(stack.toprint->first, ft_lstnew_toprint(7));
	return (stack);
}
