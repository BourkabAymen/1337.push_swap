/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:24:22 by abourkab          #+#    #+#             */
/*   Updated: 2022/12/18 22:24:26 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}					t_list;

typedef struct s_struct
{
	int			min;
	int			max;
	int			mid;
	int			to_be_push;
}				t_struct;

// push_swap.c
void	chek_duplicate(int argc, char **argv);
t_list	*create_stack(int argc, char **argv);
void	sort_function(t_list **stack_a, t_list **stack_b, int argc);

// utiles_part_one.c
void	ft_putstr(char *str);
int		ft_atoi(char *str);
void	ft_error(unsigned int n, int signe);
int		min_index(t_list *list);
void	ft_putstr_error(char *str);

// utiles_part_two.c
int		stack_size(t_list *stack);
int		index_position(t_list *stack, int index);

// check_error.c
void	check_error(int argc, char **argv);
void	check_empty_arg(char **argv);
void	check_is_digit(int argc, char **argv);
void	check_duplicate(int argc, char **argv);
int		check_sort(int argc, char **argv);

// operations.c
void	s(t_list **list, char s);
void	ss(t_list *list_a, t_list *list_b);
void	p(t_list **list_a, t_list **list_b, char p);
void	r(t_list **list, char r);
void	rr_a_b(t_list **list, char rr);

// operations2.c
t_list	*rrr_a_b(t_list *list);
void	rrr(t_list **list_a, t_list **list_b);
void	r_a_b(t_list *list);
void	rr(t_list *list_a, t_list *list_b);
void	ss_a_b(t_list *list);

// function_3_4_5.c
void	if_1(t_list **stack_a);
void	if_5(t_list **stack_a);
void	function_3(t_list **stack_a);
void	function_4(t_list **stack_a, t_list **stack_b);
void	function_5(t_list **stack_a, t_list **stack_b);

// big_sort_function_one.c
void	function_big_sort(t_list **stack_a, t_list **stack_b);
void	big_sort(t_list **stack_a, t_list **stack_b, int size);
void	push_big_sort(t_list **stack_a, t_list **stack_b, int index, int *r1);
void	big_push_to_stack_a(t_list **stack_a, t_list **stack_b,
			int big, int down_stk_a);
void	push_big_sort_to_a(t_list **stack_a, t_list **stack_b,
			int big, int size);

// big_sort_function_two.c
int		to_be_push(int size);
int		*return1(int a, int b);

// big_sort_function_utiles.c
void	push_to_b(t_list **stack_b, t_list **stack_a, int index, int mid);
void	index__1(t_list **stack_a);
int		find_index(t_list *list, int big);
int		down_stack(t_list *list);

// index.c
int		get_index(int stack_a_data, t_list *list);
void	ft_index(int argc, t_list *stack_a);
#endif
