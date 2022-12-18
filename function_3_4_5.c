/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_3_4_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:23:00 by abourkab          #+#    #+#             */
/*   Updated: 2022/12/18 22:23:04 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	if_1(t_list **stack_a)
{
	rr_a_b(&(*stack_a), 'a');
	s(&(*stack_a), 'a');
}

void	if_5(t_list **stack_a)
{
	s(&(*stack_a), 'a');
	rr_a_b(&(*stack_a), 'a');
}

void	function_3(t_list **stack_a)
{
	if ((*stack_a)->data < (*stack_a)->next->data
		&& (*stack_a)->next->data > (*stack_a)->next->next->data
		&& (*stack_a)->next->next->data > (*stack_a)->data)
		if_1(&(*stack_a));
	else if ((*stack_a)->data < (*stack_a)->next->data
		&& (*stack_a)->next->data > (*stack_a)->next->next->data
		&& (*stack_a)->next->next->data < (*stack_a)->data)
		rr_a_b(&(*stack_a), 'a');
	else if ((*stack_a)->data > (*stack_a)->next->data
		&& (*stack_a)->next->data < (*stack_a)->next->next->data
		&& (*stack_a)->next->next->data > (*stack_a)->data)
		s(&(*stack_a), 'a');
	else if ((*stack_a)->data > (*stack_a)->next->data
		&& (*stack_a)->next->data < (*stack_a)->next->next->data
		&& (*stack_a)->next->next->data < (*stack_a)->data)
		r(&(*stack_a), 'a');
	else if ((*stack_a)->data > (*stack_a)->next->data
		&& (*stack_a)->next->data > (*stack_a)->next->next->data
		&& (*stack_a)->next->next->data < (*stack_a)->data)
		if_5(&(*stack_a));
}

void	function_4(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		size;
	int		position;

	size = stack_size(*stack_a);
	i = min_index(*stack_a);
	position = index_position(*stack_a, i);
	if ((*stack_a)->data == i)
		p(&(*stack_b), &(*stack_a), 'b');
	else
	{
		if (position > size / 2)
			while ((*stack_a)->index != i)
				rr_a_b(&(*stack_a), 'a');
		else if (position <= size / 2)
			while ((*stack_a)->index != i)
				r(&(*stack_a), 'a');
		p(&(*stack_b), &(*stack_a), 'b');
	}
	function_3(&(*stack_a));
	p(&(*stack_a), &(*stack_b), 'a');
}

void	function_5(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		size;
	int		position;

	size = stack_size(*stack_a);
	i = min_index(*stack_a);
	position = index_position(*stack_a, i);
	if ((*stack_a)->data == i)
		p(&(*stack_b), &(*stack_a), 'b');
	else
	{
		if (position > size / 2)
			while ((*stack_a)->index != i)
				rr_a_b(&(*stack_a), 'a');
		else if (position <= size / 2)
			while ((*stack_a)->index != i)
				r(&(*stack_a), 'a');
		p(&(*stack_b), &(*stack_a), 'b');
	}
	function_4(&(*stack_a), &(*stack_b));
	p(&(*stack_a), &(*stack_b), 'a');
}
