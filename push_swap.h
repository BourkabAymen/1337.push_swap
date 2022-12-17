/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <abourkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:08:03 by abourkab          #+#    #+#             */
/*   Updated: 2022/12/17 23:16:41 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_variables
{
	int				macro;
	int				i;
	int				j;
	int				size;
	int				stack_size;
}	t_variables;

/* Initialization */

t_stack		*fill_stack_values(int ac, char **av);
t_stack		*fill_stack_values_help(int ac, char **av);
t_stack		*fill_stack_values_help_prime(int ac, char **av);
int			ft_strlen_array_string(char **av1);
t_stack		*fill_stack_values(int ac, char **av);

/* Sorting Algorithms */

int			is_sorted(t_stack *stack);
void		tiny_sort(t_stack **stack, int x);
void		dupplicated_tab(int *tab, unsigned int size);
void		to_tab_dupplicated(int ac, int *tab, char **av);
int			*to_tab_sorted(int ac, char **av);
int			*to_tab_sort_prime(int len, char **av);
int			*to_tab_sort(int ac, char **av);
void		sort_int_tab(int *tab, unsigned int size);
void		three_plus_sort(t_stack **stack_a, t_stack **stack_b, int *tab,
				t_variables *variables);

/* Operations */

void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);
void		do_sa(t_stack **stack_a);
void		do_sb(t_stack **stack_b);
void		do_ss(t_stack **stack_a, t_stack **stack_b);
void		do_ra(t_stack **stack_a);
void		do_rb(t_stack **stack_b);
void		do_rr(t_stack **stack_a, t_stack **stack_b);
void		do_rrr(t_stack **stack_a, t_stack **stack_b);
void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);

/* Stack Functions */

t_stack		*get_stack_bottom(t_stack *stack);
t_stack		*get_stack_before_bottom(t_stack *stack);
t_stack		*stack_new(int value);
void		stack_add_bottom(t_stack **stack, t_stack *new);
int			get_stack_size(t_stack	*stack);

/* Utils */

void		free_stack(t_stack **stack);
long int	ft_atoi(const char *str);
void		ft_putstr(char *str);
int			nb_abs(int nb);

/* Error */

void		exit_error(t_stack **stack_a, t_stack **stack_b);

/* Input Check */

int			is_correct_input(char **av, int ac);
int			is_digit(char c);
int			is_sign(char c);
int			nbstr_cmp(const char *s1, const char *s2);
char		**ft_split(char const *s, char c);

/* Stack_to_stack */

int			existe_int_tab(int value, int *tab, int i, int macro);
void		stack_a_to_stack_b(t_stack **stack_a, t_stack **stack_b, int *tab,
				t_variables *variables);
void		stack_b_to_stack_a(t_stack **stack_a, t_stack **stack_b, int *tab,
				int macro);
void		do_ra_pb(t_stack **stack_a, t_stack **stack_b, int *tab,
				t_variables variables);
void		do_ra_pb_help(t_stack **stack_a, t_stack **stack_b, int *tab,
				t_variables *variables);
void		do_rb_pa(t_stack **stack_a, t_stack **stack_b, int *tab,
				t_variables variables);
void		do_rb_pa_help(t_stack **stack_a, t_stack **stack_b, int *tmp,
				int *k);

#endif