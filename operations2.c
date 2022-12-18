/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:23:51 by abourkab          #+#    #+#             */
/*   Updated: 2022/12/18 22:23:55 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	r_a_b(t_list *list)
{
	t_list	*tmp;
	t_list	*top;

	if (!list || !list->next)
		return ;
	tmp = list;
	list = list->next;
	top = list;
	while (top != NULL)
	{
		top = top->next;
	}
	top = tmp;
}

void	rr(t_list *list_a, t_list *list_b)
{
	r_a_b(list_a);
	r_a_b(list_b);
	ft_putstr("rr\n");
}

t_list	*rrr_a_b(t_list *list)
{
	t_list	*tmp;
	t_list	*top;

	if (!list || !list->next)
		return (list);
	tmp = list;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	top = tmp->next;
	tmp->next = tmp->next->next;
	top->next = list;
	list = top;
	return (list);
}

void	rrr(t_list **list_a, t_list **list_b)
{
	*list_a = rrr_a_b(*list_a);
	*list_b = rrr_a_b(*list_b);
	ft_putstr("rrr\n");
}

void	ss_a_b(t_list *list)
{
	int	tmp;

	if (!list || !list->next)
		return ;
	tmp = list->data;
	list->data = list->next->data;
	list->next->data = tmp;
}
