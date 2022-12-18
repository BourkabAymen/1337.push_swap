/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_part_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:24:40 by abourkab          #+#    #+#             */
/*   Updated: 2022/12/18 22:24:43 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_error(unsigned int n, int signe)
{
	long int	i;

	i = (long int)n * signe;
	if ((i > INT_MAX) || i < INT_MIN)
	{
		ft_putstr_error("Error\n");
		exit(1);
	}
}

int	ft_atoi(char *str)
{
	int				i;
	int				signe;
	unsigned long	n;

	n = 0;
	signe = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = signe * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - 48);
		i++;
	}
	ft_error(n, signe);
	return (n * signe);
}

int	min_index(t_list *list)
{
	t_list	*head;
	int		i;

	head = list;
	i = head->index;
	while (head)
	{
		if (i > head->index)
		{
			i = head->index;
		}
		head = head->next;
	}
	return (i);
}

void	ft_putstr_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}
