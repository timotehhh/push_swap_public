/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:48:13 by trouger           #+#    #+#             */
/*   Updated: 2021/09/20 14:07:35 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*current;

	current = ft_lstlast(*alst);
	if (current == NULL)
		*alst = new;
	else
		current->next = new;
	new->next = NULL;
}

void	ft_lstadd_back_toprint(t_lst **alst, t_lst *new)
{
	t_lst	*current;

	current = ft_lstlast_toprint(*alst);
	if (new->first == NULL)
		new->first = alst;
	current->next = new;
	new->next = NULL;
}
