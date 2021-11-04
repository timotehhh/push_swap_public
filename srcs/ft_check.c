/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:19:34 by trouger           #+#    #+#             */
/*   Updated: 2021/11/02 12:40:35 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_check_chunk_sorted(t_list *tab, char stack, t_list *b)
{
	int	index;

	index = tab->chunk_index;
	if (ft_check_finish(tab, b))
		return (2);
	while (tab != NULL && tab->chunk_index == index)
	{
		if (stack == 'a')
		{
			if (tab->next != NULL && tab->content > tab->next->content)
				return (0);
		}
		if (stack == 'b')
		{
			if (tab->next != NULL && tab->content < tab->next->content)
				return (0);
		}
		tab = tab->next;
	}
	return (1);
}

int	ft_check_finish(t_list *tab, t_list *b)
{
	if (b != NULL)
		return (0);
	while (tab != NULL)
	{
		if (tab->next != NULL && tab->content > tab->next->content)
			return (0);
		tab = tab->next;
	}
	return (1);
}

int	ft_check_validity(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (++i < argc)
	{
		if (!(ft_check_int_min_max(argv[i]))
			|| ft_check_duplicate(argc, argv, argv[i], i))
			return (0);
		j = -1;
		while (argv[i][++j] != '\0')
		{
			if (((argv[i][j - 1] >= '0' && argv[i][j - 1] <= '9') &&
				argv[i][j] == ' '))
			{
				if (!(ft_check_validity_str(argv, i)))
					return (0);
				else if (argv[i + 1])
					return (0);
				else
					return (1);
			}
		}
	}
	return (ft_check_right_form(argv, argc));
}

int	ft_check_duplicate(int argc, char **argv, char *current, int same)
{
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] == current[j] && current[j]
				&& argv[i][j] && i != same)
			j++;
		if (!(current[j]) && !(argv[i][j]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_validity_str(char **argv, int i)
{
	int	j;
	int	end;

	j = 0;
	end = ft_check_right_form_str(argv[i]);
	if (!(end))
		return (0);
	while (j < end)
	{
		if (!(ft_check_int_min_max(argv[i] + j))
			|| ft_check_duplicate_str(argv[i] + j, end, j))
			return (0);
		while (j < end && argv[i][j] != ' ')
			j++;
		if (argv[i][j] == ' ')
			j++;
	}
	return (1);
}
