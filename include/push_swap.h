/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <trouger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:19:24 by trouger           #+#    #+#             */
/*   Updated: 2021/11/10 17:20:35 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	int				chunk_index;
	struct s_list	*next;
}				t_list;

typedef struct l_list
{
	int				command;
	struct l_list	**first;
	struct l_list	*next;
}				t_lst;

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
	t_lst	*toprint;
}				t_stack;

int		ft_find_chunk_size(t_list *chunk);
t_list	*ft_find_next_chunk(t_stack stack);
char	ft_find_next_stack(t_stack stack);
int		ft_check_chunk_sorted(t_list *tab, char stack, t_list *B);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lst_beforelast(t_list *lst);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
int		*ft_malloc_tab(int size);
char	*ft_malloc_str(int size);
void	ft_create_chunks_b(t_stack stack, int *index);
void	ft_create_chunks_a(t_stack stack, int *index);
void	push_swap(t_stack stack, int size);
void	ft_redirect(t_stack stack, int *index);
t_stack	ft_sort_2_nbr(t_stack stack, char next_stack);
t_stack	ft_pa(t_stack stack, int *index, int push);
t_stack	ft_rrb_pa(t_stack stack, int *index);
t_stack	ft_rb(t_stack stack);
t_stack	ft_pb(t_stack stack, int *index, int push);
t_stack	ft_rra_pb(t_stack stack, int *index);
t_stack	ft_ra(t_stack stack);
void	ft_print(t_lst *toprint, t_stack stack);
int		ft_fill_str1(t_lst *toprint, int i, char *str);
int		ft_fill_str2(char *str, char *to_add, int j);
int		ft_atoi(const char *str);
t_stack	ft_push(t_stack stack, int *index, char c);
t_lst	*ft_lstnew_toprint(int command);
int		ft_lstsize_toprint(t_lst *lst);
void	ft_lstadd_front_toprint(t_lst **alst, t_lst *new);
t_lst	*ft_lstlast_toprint(t_lst *lst);
t_lst	*ft_lst_beforelast_toprint(t_lst *lst);
void	ft_lstadd_back_toprint(t_lst **alst, t_lst *new);
int		ft_find_mid_a(t_list *stack);
int		ft_find_mid_b(t_list *stack);
t_stack	ft_sb(t_stack stack);
t_stack	ft_sa(t_stack stack);
int		ft_find_len_toprint(t_lst *toprint);
t_stack	ft_reset_chunk_index(t_stack stack, t_list *chunk, char next_stack);
int		ft_check_finish(t_list *tab, t_list *b);
int		ft_check_duplicate(int argc, char **argv, char *current, int same);
int		ft_check_validity(int argc, char **argv);
int		ft_check_int_min_max(const char *str);
t_stack	ft_sort_3_nbr_b(t_stack stack);
t_stack	ft_sort_3_nbr_a(t_stack stack);
t_stack	ft_sort_3_nbr(t_stack stack, char next_stack);
t_stack	ft_rrb(t_stack stack);
t_stack	ft_rra(t_stack stack);
t_stack	ft_sort_3_nbr_a_long(t_stack stack);
t_stack	ft_sort_3_nbr_b_long(t_stack stack);
t_stack	ft_sort_3_nbr_a_long2(t_stack stack);
t_stack	ft_sort_3_nbr_b_long2(t_stack stack);
t_stack	ft_sort_3_nbr_a2(t_stack stack);
t_stack	ft_sort_3_nbr_b2(t_stack stack);
t_list	*ft_reset2(t_stack stack, t_list *chunk, char next_stack, int index);
void	ft_redirect2(t_stack stack, int *index, t_list *chunk, char next_stack);
t_stack	ft_create_chunks_b2(t_stack stack, int *index, int i, int rrb);
t_stack	ft_create_chunks_a2(t_stack stack, int *index, int i, int rra);
int		ft_find_next_chunk_size(t_list *chunk);
int		ft_strlen(char *str);
void	ft_free(t_stack stack, t_lst *toprint);
int		ft_check_duplicate_str(char *str, int end, int minus_end);
int		ft_check_right_form_str(char *str);
int		ft_check_right_form(char **argv, int argc);
int		ft_check_validity_str(char **argv, int i);
t_stack	ft_fill_stack_a_str(t_stack stack, char *str);
int		ft_check_fill_stack_a_str(char **argv, int i, int j);
t_stack	ft_fill_stack_a(t_stack stack, int argc, char **argv);
t_stack	ft_sort_hundred(t_stack stack, int *index);
t_stack	ft_mark_small_chunk(t_stack stack, int *index);
int		ft_check_chunk_gone(t_stack stack, int *index);
t_stack	ft_push_nb_to_b(t_stack stack, t_list *end, t_list *temp, int *index);
t_stack	ft_push_nb_rr(t_stack stack, int *index, char main_stack);
t_stack	ft_push_nb_r(t_stack stack, int *index, char main_stack);
t_stack	ft_end_sort_hundred(t_stack stack, int *index);
t_stack	ft_mark_biggest(t_stack stack, int *index);
t_stack	ft_push_biggest(t_stack stack, t_list *end, t_list *temp, int *index);
t_list	*ft_lst_point_end(t_list *stack, int previous);
t_list	*ft_find_smallest(t_stack stack, t_list *s, int *index);
int		ft_check_right_form_str2(char *str, int i, int end);
int		ft_check_atoi(t_stack stack);

#endif
