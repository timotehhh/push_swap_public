/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:02:39 by trouger           #+#    #+#             */
/*   Updated: 2021/11/02 13:30:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (!(argv[1]))
		return (0);
	if (argv[1])
		stack.a = ft_lstnew(ft_atoi(argv[1]));
	stack.b = NULL;
	if (!(ft_check_validity(argc, argv)))
	{
		write (2, "Error\n", 6);
		ft_free(stack, NULL);
		return (0);
	}
	stack = ft_fill_stack_a(stack, argc, argv);
	push_swap(stack, ft_lstsize(stack.a) - 1);
	return (0);
}

void	push_swap(t_stack stack, int size)
{
	int		*index;

	index = ft_malloc_tab(1);
	*index = 1;
	stack.toprint = ft_lstnew_toprint(0);
	stack.toprint->first = &(stack.toprint);
	if (ft_check_chunk_sorted (stack.a, 'a', stack.b))
	{
		ft_free(stack, stack.toprint);
		free(index);
		return ;
	}
	if (size == 2)
	{
		ft_redirect (stack, index);
		free(index);
		return ;
	}
	if (ft_lstsize(stack.a) == 100 && stack.b == NULL)
		ft_redirect(ft_sort_hundred(stack, index), index);
	else
		ft_create_chunks_a (stack, index);
	free(index);
}
