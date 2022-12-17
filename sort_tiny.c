/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <abourkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:08:47 by abourkab          #+#    #+#             */
/*   Updated: 2022/12/17 21:47:02 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* tiny_sort:
*	Sorts a stack of 3 numbers in 2 or fewer moves. The sorting is done by index
*	rather than value. Example:
*		values:		 0	 9	 2
*		indexes:	[1]	[3]	[2]
*	Solution, 2 moves:
*	rra:
*		values:		 2	 0	 9
*		indexes:	[2]	[1]	[3]
*	sa:
*		values:		 0	 2	 9
*		indexes:	[1]	[2]	[3]
*/
void	tiny_sort(t_stack **stack, int x)
{
	if ((*stack)->value == x)
	{
		do_ra(stack);
		if ((*stack)->value > (*stack)->next->value)
			do_sa(stack);
	}	
	else if ((*stack)->next->value == x)
	{
		do_rra(stack);
		if ((*stack)->value > (*stack)->next->value)
			do_sa(stack);
	}
	else if ((*stack)->next->next->value == x)
	{
		if ((*stack)->value > ((*stack)->next)->value)
			do_sa(stack);
	}
}

/*
* This function is used in  stack_a_to_stack_b to push the rest 
* of the elements of stack a 
* to stack b and lets the 3 biggest numbers in stack a and it sorts them
* after moving all the chanks of course if they exist
*/
void	three_plus_sort(t_stack **stack_a, t_stack **stack_b, int *tab,
		t_variables *variables)
{
	int	j;
	int	size;
	int	stack_size;

	size = variables->size;
	stack_size = variables->stack_size;
	j = 1;
	while (*stack_a && j <= size - 3)
	{
		if ((*stack_a)->value != tab[stack_size - 1] && (*stack_a)->value
			!= tab[stack_size - 2] && (*stack_a)->value != tab[stack_size - 3])
		{
			do_pb(stack_a, stack_b);
			j++;
		}
		else
			do_ra(stack_a);
	}
	tiny_sort(stack_a, tab[stack_size - 1]);
}
