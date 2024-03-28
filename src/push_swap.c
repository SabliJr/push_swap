/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:12:42 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/28 10:47:16 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_stacks *stacks);
void	free_list(t_list *list);

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
	tab->stack_b = NULL;
	if (!tab->stack_a)
	{
		free_stacks(tab);
		return (-1);
	}
	tab->a_size = ft_lstsize(tab->stack_a);
	tab->b_size = ft_lstsize(tab->stack_b);
	add_index(tab->stack_a);
	check_sort(tab);
	free_stacks(tab);
	return (0);
}

void	free_stacks(t_stacks *stacks)
{
	free_list(stacks->stack_a);
	free_list(stacks->stack_b);
	free(stacks);
}

void	free_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}
