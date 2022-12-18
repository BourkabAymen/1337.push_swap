/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_function_utiles.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:22:21 by abourkab          #+#    #+#             */
/*   Updated: 2022/12/18 22:22:32 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	push_to_b(t_list **stack_b, t_list **stack_a, int index, int mid)
{
	if (index < mid)
	{
		p(&(*stack_b), &(*stack_a), 'b');
		r(&(*stack_b), 'b');
	}
	else
		p(&(*stack_b), &(*stack_a), 'b');
}

void	index__1(t_list **stack_a)
{
	t_list	*head;
	t_list	*top;
	int		i;

	i = 0;
	head = *stack_a;
	top = *stack_a;
	while (head)
	{
		i++;
		head = head->next;
	}
	i--;
	while (i)
	{
		top = top->next;
		i--;
	}
	top->index = -1;
}

int	find_index(t_list *list, int big)
{
	while (list->index != big && list->next)
	{
		list = list->next;
	}
	if (list->index == big)
		return (1);
	else
		return (0);
}

int	down_stack(t_list *list)
{
	t_list	*head;
	int		i;

	while (list->next)
	{
		list = list->next;
		head = list;
	}
	i = head->index;
	return (i);
}
