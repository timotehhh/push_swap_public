/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:23:54 by trouger           #+#    #+#             */
/*   Updated: 2021/11/10 17:22:00 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_check_right_form(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (((argv[i][j] == '-'
					&& (j != 0 || (argv[i][j + 1] < '0'
						|| argv[i][j + 1] > '9')))
					|| ((argv[i][j] < '0' || argv[i][j] > '9')
					&& argv[i][j] != '-')))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_right_form_str2(char *str, int i, int end)
{
	while (i < end)
	{
		if ((str[i] == '-' && (i != 0 && (str[i - 1] != ' '
						|| (str[i + 1] < '0' || str[i + 1] > '9')))))
			return (0);
		else if (str[i] == '-')
			i++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (i < end && str[i] != ' ')
			return (0);
		i++;
		if (i < end && (str[i] != '-' && (str[i] < '0' || str[i] > '9')))
			return (0);
	}
	return (i);
}

int	ft_check_right_form_str(char *str)
{
	int	i;
	int	end;

	i = 0;
	end = 0;
	while (str[end])
		end++;
	if ((str[end - 1] < '0' || str[end - 1] > '9')
		|| ((str[i] < '0' || str[i] > '9') && str[i] != '-'))
		return (0);
	if (!(ft_check_right_form_str2(str, i, end)))
		return (0);
	i = ft_check_right_form_str2(str, i, end);
	if (i < end && (str[i - 1] < '0' || str[i - 1] > '9'))
		return (0);
	return (end);
}

int	ft_check_duplicate_str(char *str, int end, int minus_end)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	end -= minus_end;
	while (i < end && str[++i] != ' ')
		j++;
	while (j < end)
	{
		i = 0;
		while (str[i] == str[j] && str[i] != ' ' && str[j] != ' ')
		{
			i++;
			j++;
		}
		if (str[i] == ' ' && (str[j] == ' ' || j >= end))
		{
			return (1);
		}
		while (j < end && str[j] != ' ')
			j++;
		j++;
	}
	return (0);
}

int	ft_check_atoi(t_stack stack)
{
	t_list	*temp;

	while (stack.a)
	{
		temp = stack.a->next;
		while (temp)
		{
			if (temp->content == stack.a->content)
				return (0);
			temp = temp->next;
		}
		stack.a = stack.a->next;
	}
	return (1);
}
