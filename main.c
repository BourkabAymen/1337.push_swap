/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <abourkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:07:35 by abourkab          #+#    #+#             */
/*   Updated: 2022/12/17 23:27:56 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_one(t_stack **stack_a, t_stack **stack_b, int *tab,
		int stack_size)
{
	t_variables	variables;

	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3 && !is_sorted(*stack_a))
		tiny_sort(stack_a, tab[2]);
	else if (stack_size > 3 && stack_size < 100 && !is_sorted(*stack_a))
	{
		variables.size = stack_size;
		variables.stack_size = stack_size;
		three_plus_sort(stack_a, stack_b, tab, &variables);
		stack_b_to_stack_a(stack_a, stack_b, tab, 1);
	}
}

void	push_swap_two(t_stack **stack_a, t_stack **stack_b, int *tab,
		int stack_size)
{
	t_variables	variables;

	if (stack_size == 100 && !is_sorted(*stack_a))
	{
		variables.stack_size = stack_size;
		variables.macro = 8;
		stack_a_to_stack_b(stack_a, stack_b, tab, &variables);
		stack_b_to_stack_a(stack_a, stack_b, tab, 8);
	}
	else if (stack_size > 100 && !is_sorted(*stack_a))
	{
		variables.stack_size = stack_size;
		variables.macro = 24;
		stack_a_to_stack_b(stack_a, stack_b, tab, &variables);
		stack_b_to_stack_a(stack_a, stack_b, tab, 24);
	}
}

/* push_swap:
*	Chooses a sorting method depending on the number
*	of values to be sorted.
*/
void	push_swap(t_stack **stack_a, t_stack **stack_b, int *tab,
		int stack_size)
{
	if (stack_size < 100)
		push_swap_one(stack_a, stack_b, tab, stack_size);
	else
		push_swap_two(stack_a, stack_b, tab, stack_size);
}

/* main:
*	Checks if the input is correct, in which case 
*   it initializes stacks a and b,
*	assigns each value indexes and sorts the stacks. 
*   When sorting is done, frees
*	the stacks and exits.
*/
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*tab;
	int		stack_size;

	if (ac < 2)
		return (0);
	if (!is_correct_input(av, ac))
		exit_error(NULL, NULL);
	tab = to_tab_sorted(ac, av);
	to_tab_dupplicated(ac, tab, av);
	stack_b = NULL;
	stack_a = fill_stack_values(ac, av);
	stack_size = get_stack_size(stack_a);
	push_swap(&stack_a, &stack_b, tab, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	free(tab);
	tab = NULL;
	return (0);
}
