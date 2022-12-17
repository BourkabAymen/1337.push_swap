/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_to_stack_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <abourkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:09:13 by abourkab          #+#    #+#             */
/*   Updated: 2022/12/17 23:13:51 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
* This function returns 1 if value is in the tab
* especially in the chank specified by the i
*/
int	existe_int_tab(int value, int *tab, int i, int macro)
{
	int	k;

	k = macro * (i - 1);
	while (k < macro * i)
	{
		if (tab[k] == value)
			return (1);
		k++;
	}
	return (0);
}

void	do_ra_pb_help(t_stack **stack_a, t_stack **stack_b, int *tab,
		t_variables *variables)
{
	if (existe_int_tab((*stack_a)->value, tab, variables->i,
			variables->macro))
	{
		do_pb(stack_a, stack_b);
		variables->j = variables->j + 1;
	}
	else if (existe_int_tab((get_stack_bottom(*stack_a))->value, tab,
			variables->i, variables->macro))
	{
		do_rra(stack_a);
		do_pb(stack_a, stack_b);
		variables->j = variables->j + 1;
	}
}

/*
* This function move chank by chank from stack a to stack b
*/
void	do_ra_pb(t_stack **stack_a, t_stack **stack_b, int *tab,
		t_variables variables)
{
	int	i;
	int	k;
	int	macro;

	macro = variables.macro;
	i = variables.i;
	variables.j = 1;
	k = 0;
	while (*stack_a && k < variables.stack_size && variables.j <= macro)
	{
		if (existe_int_tab((*stack_a)->value, tab, variables.i,
				variables.macro) || existe_int_tab(
				(get_stack_bottom(*stack_a))->value, tab,
				variables.i, variables.macro))
			do_ra_pb_help(stack_a, stack_b, tab, &variables);
		if (existe_int_tab((*stack_a)->next->value, tab, i, macro))
			do_ra(stack_a);
		else if (existe_int_tab(
				(get_stack_before_bottom(*stack_a))->value, tab, i, macro))
			do_rra(stack_a);
		else
			do_ra(stack_a);
		k++;
	}
}

/*
* This function calls do_ra_pb to move all the ckanks 
* This function push to stack b the rest of the elements in
* stack a but let in stack a the 3 biggest numbers 
* (in case they exist)
*/
void	stack_a_to_stack_b(t_stack **stack_a, t_stack **stack_b, int *tab,
		t_variables *variables)
{
	int	size;
	int	i;
	int	macro;
	int	stack_size;

	i = 1;
	stack_size = variables->stack_size;
	macro = variables->macro;
	while (i <= stack_size / macro)
	{
		variables->i = i;
		do_ra_pb(stack_a, stack_b, tab, *variables);
		i++;
	}
	size = get_stack_size(*stack_a);
	variables->size = size;
	if (size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (size == 3 && !is_sorted(*stack_a))
		tiny_sort(stack_a, tab[stack_size - 1]);
	else if (size > 3 && !is_sorted(*stack_a))
		three_plus_sort(stack_a, stack_b, tab, variables);
}

void	do_rb_pa_help(t_stack **stack_a, t_stack **stack_b, int *tmp,
		int *k)
{
	do_pa(stack_a, stack_b);
	*k = *k - 1;
	while (*tmp)
	{
		do_rrb(stack_b);
		*tmp = *tmp - 1;
	}
}
