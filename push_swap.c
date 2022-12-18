/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:24:08 by abourkab          #+#    #+#             */
/*   Updated: 2022/12/18 22:24:12 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

t_list	*create_stack(int argc, char **argv)
{
	int		i;
	t_list	*tmp;
	t_list	*before;
	t_list	*head;

	before = 0;
	i = 1;
	while (i < argc)
	{
		tmp = malloc(sizeof(t_list));
		tmp->data = ft_atoi(argv[i]);
		if (i == 1)
			head = tmp;
		if (before != 0)
			before->next = tmp;
		before = tmp;
		i++;
	}
	tmp->next = NULL;
	return (head);
}

void	sort_function(t_list **stack_a, t_list **stack_b, int argc)
{
	if (argc == 3)
		s(stack_a, 'a');
	else if (argc == 4)
		function_3(stack_a);
	else if (argc == 5)
		function_4(stack_a, stack_b);
	else if (argc == 6)
		function_5(stack_a, stack_b);
	else if (argc > 6)
		function_big_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc > 1)
	{
		check_error(argc, argv);
		stack_a = NULL;
		stack_b = NULL;
		stack_a = create_stack(argc, argv);
		ft_index(argc, stack_a);
		sort_function(&stack_a, &stack_b, argc);
	}
	return (0);
}
