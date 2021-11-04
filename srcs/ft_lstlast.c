/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:49:52 by trouger           #+#    #+#             */
/*   Updated: 2021/10/21 16:12:42 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
		{
			lst = lst->next;
		}
	}
	return (lst);
}

t_lst	*ft_lstlast_toprint(t_lst *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

t_list	*ft_lst_beforelast(t_list *lst)
{
	if (lst)
	{
		if (!(lst->next))
			return (NULL);
		while (lst->next->next)
			lst = lst->next;
	}
	return (lst);
}

t_lst	*ft_lst_beforelast_toprint(t_lst *lst)
{
	if (lst)
	{
		while (lst->next->next)
			lst = lst->next;
	}
	return (lst);
}
