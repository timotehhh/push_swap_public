/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_midvalue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 11:28:20 by trouger           #+#    #+#             */
/*   Updated: 2021/09/20 16:28:54 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_find_mid_a(t_list *stack)
{
	int		i;
	int		mid;
	t_list	*temp;
	t_list	*current;

	current = stack;
	temp = stack;
	i = 0;
	mid = ft_find_next_chunk_size(stack);
	while (temp != NULL)
	{
		i = 0;
		current = stack;
		while (current != NULL)
		{
			if (current->content < temp->content)
				i++;
			current = current->next;
		}
		if (i == mid)
			return (temp->content);
		temp = temp->next;
	}
	return (0);
}

int	ft_find_mid_b(t_list *stack)
{
	int		i;
	int		mid;
	t_list	*temp;
	t_list	*current;

	current = stack;
	temp = stack;
	i = 0;
	mid = ft_find_next_chunk_size(stack);
	while (temp != NULL)
	{
		i = 0;
		current = stack;
		while (current != NULL)
		{
			if (current->content > temp->content)
				i++;
			current = current->next;
		}
		if (i == mid)
			return (temp->content);
		temp = temp->next;
	}
	return (0);
}
