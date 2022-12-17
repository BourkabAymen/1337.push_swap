/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <abourkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:08:35 by abourkab          #+#    #+#             */
/*   Updated: 2022/12/17 18:58:11 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* to_tab_dupplicated:
*   calls dupplicated_tab depending of the value of ac
*   in other terms (we will split or not)
*   this function is used to solve this case
*   having for example 0 1 2 3 4 5 6 as arguments
*   and having for example "0 1 2 3 4 5 6" as arguments
*/
void	to_tab_dupplicated(int ac, int *tab, char **av)
{
	char	**av1;
	int		len;

	if (ac == 2)
	{
		av1 = ft_split(av[1], ' ');
		len = ft_strlen_array_string(av1);
		dupplicated_tab(tab, len);
	}
	if (ac < 2)
		return ;
	dupplicated_tab(tab, ac);
}

/* dupplicated_tab:
*   checks if there is there is a dupplicated element in tab
*	and exit
*   this function is used to avoid this case
*   having for example 01 and 1 (an error case)
*/
void	dupplicated_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;	

	i = 0;
	while (i < (size - 1))
	{
		j = i + 1;
		while (j < (size - 2))
		{
			if (tab[i] == tab[j])
			{
				exit_error(NULL, NULL);
			}
			else
				j++;
		}
		i++;
	}
}

/* to_tab_sorted:
*   returns a tab filled with the stack_a elements
*	sorts this tab (array of integers) by calling to_tab_sort.
*   or to_tab_sort_prime depending on the of ac
*/
int	*to_tab_sorted(int ac, char **av)
{
	char	**av1;
	int		len;

	if (ac == 2)
	{
		av1 = ft_split(av[1], ' ');
		len = ft_strlen_array_string(av1);
		return (to_tab_sort_prime(len, av1));
	}
	if (ac < 2)
		return (NULL);
	return (to_tab_sort(ac, av));
}

/* to_tab_sort:
*   returns a tab filled with the stack_a elements
*	sorts this tab (array of integers) by calling sort_int_tab.
*   it is used when ac > 2
*/
int	*to_tab_sort(int ac, char **av)
{
	int	i;
	int	*tab;

	i = 0;
	tab = (int *)malloc ((ac - 1) * 4);
	if (!tab)
		return (NULL);
	while (i < ac -1)
	{
		tab[i] = ft_atoi(av[i + 1]);
		i++;
	}
	sort_int_tab (tab, ac - 1);
	return (tab);
}

/* to_tab_sort_prime:
*   returns a tab filled with the stack_a elements
*	sorts this tab (array of integers) by calling sort_int_tab.
*   it is used when ac = 2
*/
int	*to_tab_sort_prime(int len, char **av)
{
	int	i;
	int	*tab;

	i = 0;
	tab = (int *)malloc ((len) * 4);
	if (!tab)
		return (NULL);
	while (i < len)
	{
		tab[i] = ft_atoi(av[i]);
		i++;
	}
	sort_int_tab (tab, len);
	return (tab);
}
