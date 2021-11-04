/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:19:41 by trouger           #+#    #+#             */
/*   Updated: 2021/09/20 13:42:56 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*ft_malloc_tab(int size)
{
	int		*result;

	result = malloc(sizeof(int) * (size + 1));
	if (result == NULL)
		return (NULL);
	return (result);
}

char	*ft_malloc_str(int size)
{
	char	*result;

	result = malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (NULL);
	return (result);
}
