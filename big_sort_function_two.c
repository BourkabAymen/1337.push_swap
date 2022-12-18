/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_function_two.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:22:05 by abourkab          #+#    #+#             */
/*   Updated: 2022/12/18 22:22:09 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	to_be_push(int size)
{
	int	to_push;

	if (size < 105)
		to_push = (size - 5) / 3 + 1;
	else if (size < 505)
		to_push = (size - 5) / 5 + 1;
	else
		to_push = (size - 5) / 7 + 1;
	if (to_push == 0)
		to_push = 1;
	return (to_push);
}

int	*return1(int a, int b)
{
	int	*r;

	r = malloc(sizeof(int) * 2);
	r[0] = a;
	r[1] = b;
	return (r);
}
