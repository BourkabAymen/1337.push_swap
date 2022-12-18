/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_part_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:24:53 by abourkab          #+#    #+#             */
/*   Updated: 2022/12/18 22:24:57 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_list *stack)
{
	int		i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	index_position(t_list *stack, int index)
{
	int	position;

	position = 1;
	while (stack)
	{
		if (stack->index == index)
			return (position);
		position++;
		stack = stack->next;
	}
	return (position);
}
