/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:23:35 by abourkab          #+#    #+#             */
/*   Updated: 2022/12/18 22:23:39 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_list **list, char s)
{
	t_list	*top;
	t_list	*head;

	if (!*list || !(*list)->next)
		return ;
	head = *list;
	top = (*list)->next;
	*list = (*list)->next->next;
	top->next = head;
	head->next = *list;
	*list = top;
	if (s == 'a')
		ft_putstr("sa\n");
	else if (s == 'b')
		ft_putstr("sb\n");
}

void	ss(t_list *list_a, t_list *list_b)
{
	ss_a_b(list_a);
	ss_a_b(list_b);
	ft_putstr("ss\n");
}

void	p(t_list **list_a, t_list **list_b, char p)
{
	t_list	*tmp;

	tmp = *list_b;
	if (*list_b)
	{
		*list_b = (*list_b)->next;
		tmp->next = *list_a;
		*list_a = tmp;
		if (p == 'a')
			ft_putstr("pa\n");
		else if (p == 'b')
			ft_putstr("pb\n");
	}
}

void	r(t_list **list, char r)
{
	t_list	*tmp;
	t_list	*top;

	if (!*list || !(*list)->next)
		return ;
	tmp = *list;
	*list = (*list)->next;
	tmp->next = NULL;
	top = *list;
	while (top->next != NULL)
	{
		top = top->next;
	}
	top->next = tmp;
	if (r == 'a')
		ft_putstr("ra\n");
	else if (r == 'b')
		ft_putstr("rb\n");
}

void	rr_a_b(t_list **list, char rr)
{
	t_list	*tmp;
	t_list	*top;

	if (!*list || !(*list)->next)
		return ;
	tmp = *list;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	top = tmp->next;
	tmp->next = tmp->next->next;
	top->next = *list;
	*list = top;
	if (rr == 'a')
		ft_putstr("rra\n");
	else if (rr == 'b')
		ft_putstr("rrb\n");
}
