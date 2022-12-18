/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:23:12 by abourkab          #+#    #+#             */
/*   Updated: 2022/12/18 22:23:17 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	get_index(int stack_a_data, t_list *list)
{
	int	i;

	i = 0;
	while (list != NULL)
	{
		if (stack_a_data < list->data)
			i++;
		list = list->next;
	}
	return (i);
}

void	ft_index(int argc, t_list *stack_a)
{
	int		n;
	int		data_size;
	t_list	*list;

	data_size = argc - 1;
	list = stack_a;
	while (list != NULL)
	{
		n = get_index(list->data, stack_a);
		if (argc - 1 <= 5)
			list->index = data_size - n;
		else
			list->index = data_size - n - 1;
		list = list->next;
	}
}
