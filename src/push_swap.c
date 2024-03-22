/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:12:42 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/21 15:02:24 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	main(int argc, char *argv[])
int	main(void)
{
	int			argc;
	char		*argv[3];
	t_stacks	*tab;
	char		**args;
	char		*s;
	char		*num;

	argc = 2;
	s = "Some BS";
	num = "3 -3";
	argv[0] = s;
	argv[1] = num;
	args = NULL;
	if (argc < 2)
		return (1);
	tab = malloc(sizeof(t_swap));
	if (!tab)
		return (-1);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv;
	tab->stack_a = ft_init(args, argc);
	if (!tab->stack_a)
		return (-1);
	tab->stack_b = NULL;
	tab->a_size = ft_lstsize(tab->stack_a);
	tab->b_size = ft_lstsize(tab->stack_b);
	printf("%d\n", tab->a_size);
	printf("This is the push swap project");
	return (0);
}
