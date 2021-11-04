/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:11:39 by trouger           #+#    #+#             */
/*   Updated: 2021/10/25 14:17:03 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	ft_fill_stack_a(t_stack stack, int argc, char **argv)
{
	t_list	*temp;
	int		i;
	int		j;

	j = 0;
	i = 1;
	temp = stack.a;
	if (ft_check_fill_stack_a_str(argv, i, j))
		return (ft_fill_stack_a_str(stack, argv[i]));
	while (++i < argc)
	{
		ft_lstadd_back(&(stack.a), ft_lstnew(ft_atoi(argv[i])));
		stack.a = stack.a->next;
	}
	stack.a = temp;
	return (stack);
}

int	ft_check_fill_stack_a_str(char **argv, int i, int j)
{
	while (argv[i][j] == '-'
			|| (argv[i][j] >= '0' && argv[i][j] <= '9'))
		j++;
	if (argv[i][j] && argv[i][j] == ' ')
		return (1);
	return (0);
}

t_stack	ft_fill_stack_a_str(t_stack stack, char *str)
{
	int	i;

	i = 0;
	while (str[i] == '-' || (str[i] >= '0'
			&& str[i] <= '9'))
		i++;
	i++;
	while (str[i] == '-' || (str[i] >= '0'
			&& str[i] <= '9') || str[i] == ' ')
	{
		ft_lstadd_back(&(stack.a), ft_lstnew(ft_atoi(str + i)));
		while (str[i] == '-' || (str[i] >= '0'
				&& str[i] <= '9'))
			i++;
		i++;
	}
	return (stack);
}
