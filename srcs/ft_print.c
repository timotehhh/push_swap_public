/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 01:37:04 by trouger           #+#    #+#             */
/*   Updated: 2021/11/09 01:37:12 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_print(t_lst *toprint, t_stack stack)
{
	int		size;
	char	*str;
	int		i;
	t_lst	*temp;

	i = 0;
	size = ft_find_len_toprint(toprint);
	str = ft_malloc_str(size);
	temp = toprint;
	while (toprint != NULL && i < size)
	{
		i = ft_fill_str1(toprint, i, str);
		toprint = toprint->next;
	}
	str[i] = '\0';
	if (str[0] != '\0')
		write (1, str, ft_strlen(str));
	free (str);
	ft_free(stack, temp);
}

int	ft_fill_str1(t_lst *toprint, int i, char *str)
{
	if (toprint->command == 1)
		i = ft_fill_str2(str, "ra\n", i);
	if (toprint->command == 2)
		i = ft_fill_str2(str, "rb\n", i);
	if (toprint->command == 3)
		i = ft_fill_str2(str, "rr\n", i);
	if (toprint->command == 4)
		i = ft_fill_str2(str, "pa\n", i);
	if (toprint->command == 5)
		i = ft_fill_str2(str, "pb\n", i);
	if (toprint->command == 6)
		i = ft_fill_str2(str, "sa\n", i);
	if (toprint->command == 7)
		i = ft_fill_str2(str, "sb\n", i);
	if (toprint->command == 8)
		i = ft_fill_str2(str, "ss\n", i);
	if (toprint->command == 9)
		i = ft_fill_str2(str, "rra\n", i);
	if (toprint->command == 10)
		i = ft_fill_str2(str, "rrb\n", i);
	if (toprint->command == 11)
		i = ft_fill_str2(str, "rrr\n", i);
	return (i);
}

int	ft_fill_str2(char *str, char *to_add, int j)
{
	int	i;

	i = 0;
	while (to_add[i])
	{
		str[j] = to_add[i];
		i++;
		j++;
	}
	return (j);
}

int	ft_find_len_toprint(t_lst *toprint)
{
	t_lst	*current;
	int		i;

	i = -2;
	current = toprint;
	while (current != NULL)
	{
		if (current->command <= 8)
			i = i + 2;
		else if (current->command > 8)
			i = i + 3;
		i++;
		current = current->next;
	}
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
