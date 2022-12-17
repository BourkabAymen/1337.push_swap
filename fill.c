/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <abourkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:06:24 by abourkab          #+#    #+#             */
/*   Updated: 2022/12/16 14:03:28 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* 
*	This function return stack_a filled with the provided values. 
*   This function is used when ac = 2
*/
t_stack	*fill_stack_values_help(int ac, char **av)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 0;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stack_a, NULL);
		if (i == 0)
			stack_a = stack_new((int)nb);
		else
			stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}

/* 
*	This function return stack_a filled with the provided values. 
*   This function is used when ac > 2
*/
t_stack	*fill_stack_values_help_prime(int ac, char **av)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stack_a, NULL);
		if (i == 0)
			stack_a = stack_new((int)nb);
		else
			stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}

/*
* This function retuen the len of av1
*/
int	ft_strlen_array_string(char **av1)
{
	int	i;

	i = 0;
	while (av1[i])
		i++;
	return (i);
}

/* fill_stack_values:
*	Fills stack_a with the provided values.
*	If the values are out of integer range, prints and error and exits the program.
*/
t_stack	*fill_stack_values(int ac, char **av)
{
	char	**av1;
	int		len;
	t_stack	*stack_a;

	if (ac == 2)
	{
		av1 = ft_split(av[1], ' ');
		len = ft_strlen_array_string(av1);
		stack_a = fill_stack_values_help(len, av1);
		return (stack_a);
	}
	stack_a = fill_stack_values_help_prime(ac, av);
	return (stack_a);
}
