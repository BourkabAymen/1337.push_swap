/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_function_one.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:21:25 by abourkab          #+#    #+#             */
/*   Updated: 2022/12/18 22:21:40 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_big_sort(t_list **stack_a, t_list **stack_b, int index, int *r1)
{
	int		size;
	int		mid;
	int		position;
	t_list	*head;

	size = r1[0];
	mid = r1[1];
	free(r1);
	position = 0;
	head = *stack_a;
	while (head->index != index)
	{
		position++;
		head = head->next;
	}
	while ((*stack_a)->index != index)
	{
		if (position > size / 2)
			rr_a_b(&(*stack_a), 'a');
		else if (position <= size / 2)
			r(stack_a, 'a');
	}
	push_to_b(stack_b, stack_a, index, mid);
}

void	big_sort(t_list **stack_a, t_list **stack_b, int size)
{
	t_struct	vars;
	t_list		*head;

	while (size > 5)
	{
		head = *stack_a;
		vars.to_be_push = to_be_push(size);
		vars.min = min_index(*stack_a);
		vars.max = vars.min + vars.to_be_push - 1;
		vars.mid = (vars.min + vars.max) / 2;
		while (vars.to_be_push && size > 5 && head)
		{
			if (head->index >= vars.min && head->index <= vars.max)
			{
				push_big_sort(&(*stack_a), &(*stack_b), head->index,
					return1(size, vars.mid));
				size--;
				vars.to_be_push--;
				head = *stack_a;
			}
			head = head->next;
		}
	}
	function_5(&*(stack_a), &(*stack_b));
}

void	push_big_sort_to_a(t_list **stack_a,
		t_list **stack_b, int big, int size)
{
	int		position;
	t_list	*head;

	position = 0;
	head = *stack_b;
	while (head->index != big)
	{
		position++;
		head = head->next;
	}
	while ((*stack_b)->index != big)
	{
		if (position > size / 2)
			rr_a_b(&(*stack_b), 'b');
		else if (position <= size / 2)
			r(&(*stack_b), 'b');
	}
	p(&(*stack_a), &(*stack_b), 'a');
}

void	big_push_to_stack_a(t_list **stack_a, t_list **stack_b,
		int big, int down_stk_a)
{
	int	size;

	size = stack_size(*stack_b);
	if (*stack_b)
	{
		if ((*stack_b)->index == big)
			p(&(*stack_a), &(*stack_b), 'a');
		else if ((*stack_b)->index < big + 1 && (*stack_b)->index > down_stk_a)
		{
			p(&(*stack_a), &(*stack_b), 'a');
			r(&(*stack_a), 'a');
		}
		else if (find_index(*stack_b, big) != 1)
			rr_a_b(&(*stack_a), 'a');
		else
			push_big_sort_to_a(&(*stack_a), &(*stack_b), big, size);
	}
	else
		rr_a_b(&(*stack_a), 'a');
}

void	function_big_sort(t_list **stack_a, t_list **stack_b)
{
	int	big;
	int	down_stk_a;
	int	size;

	size = stack_size(*stack_a);
	big_sort(&(*stack_a), &(*stack_b), size);
	index__1(&(*stack_a));
	big = (*stack_a)->index - 1;
	down_stk_a = down_stack(*stack_a);
	while (big != -1)
	{
		down_stk_a = down_stack(*stack_a);
		big_push_to_stack_a(&(*stack_a), &(*stack_b), big, down_stk_a);
		big = (*stack_a)->index - 1;
	}
}
