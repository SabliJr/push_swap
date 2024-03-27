/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:12:42 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/27 15:54:31 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	main(void)
int	main(int argc, char *argv[])
{
	t_stacks	*tab;
	char		**args;
	int			is_allocated;

	is_allocated = 0;
	if (argc < 2)
		return (1);
	tab = malloc(sizeof(t_stacks));
	if (!tab)
		return (-1);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		is_allocated = 1;
	}
	else
		args = argv;
	tab->stack_a = ft_init(args, argc, is_allocated);
	if (!tab->stack_a)
		return (-1);
	tab->stack_b = NULL;
	tab->a_size = ft_lstsize(tab->stack_a);
	tab->b_size = ft_lstsize(tab->stack_b);
	add_index(tab->stack_a);
	check_sort(tab);
	free(tab);
	return (0);
}

// int			x;
// int			argc;
// char		*argv[8];
// char		*s;
// char		*num;
// argc = 8;
// s = "Some BS";
// num = "-3 17 4 90 1 20 0 10 6";
// argv[0] = s;
// argv[1] = "-3";
// argv[2] = "17";
// argv[3] = "4";
// argv[4] = "90";
// argv[5] = "1";
// argv[6] = "20";
// argv[7] = "0";
// args = NULL;
// x = 0;
