/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_to_stack_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <abourkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:09:13 by abourkab          #+#    #+#             */
/*   Updated: 2022/12/17 23:12:23 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
* This function move chank by chank from stack b to stack a
*/
void	do_rb_pa(t_stack **stack_a, t_stack **stack_b, int *tab,
		t_variables variables)
{
	int	k;
	int	tmp;
	int	stack_size_b;
	int	macro;
	int	i;

	macro = variables.macro;
	i = variables.i;
	stack_size_b = get_stack_size(*stack_b) + (i - 1) * macro;
	k = stack_size_b - 1 - (i - 1) * macro;
	tmp = 0;
	while (*stack_b && k > stack_size_b - 1 - i * macro)
	{
		if (tab[k] == (*stack_b)->value)
			do_rb_pa_help(stack_a, stack_b, &tmp, &k);
		else if ((*stack_b)->value < (*stack_b)->next->value)
			do_sb(stack_b);
		else
		{
			do_rb(stack_b);
			tmp++;
		}
	}
}

/*
* This function move all the elements by chank in order from stack b to a  
*/
void	stack_b_to_stack_a(t_stack **stack_a, t_stack **stack_b,
		int *tab, int macro)
{
	int			i;
	int			stack_size_b;
	t_variables	variables;

	stack_size_b = get_stack_size(*stack_b);
	i = 1;
	while (i <= (stack_size_b % macro))
	{
		variables.i = i;
		variables.macro = 1;
		do_rb_pa(stack_a, stack_b, tab, variables);
		i++;
	}
	i = 1;
	while (i <= (stack_size_b / macro))
	{
		variables.i = i;
		variables.macro = macro;
		do_rb_pa(stack_a, stack_b, tab, variables);
		i++;
	}
}
