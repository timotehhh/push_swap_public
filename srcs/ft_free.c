/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:29:52 by trouger           #+#    #+#             */
/*   Updated: 2021/10/14 17:30:13 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free(t_stack stack, t_lst *toprint)
{
	t_list	*temp;
	t_lst	*tmp;

	while (stack.a != NULL)
	{
		temp = stack.a;
		if (stack.a != NULL)
		{
			stack.a = stack.a->next;
			free(temp);
		}
	}
	while (toprint != NULL)
	{
		tmp = toprint;
		toprint = toprint->next;
		free (tmp);
	}
}
