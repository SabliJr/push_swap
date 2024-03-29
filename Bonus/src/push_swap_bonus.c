/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:53:52 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/29 18:13:37 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

t_list	*ft_int(char **args, int argc, int is_allocated);
void	ft_print_err(t_list *res, char **args, int is_allocated);
void	main_extand(t_stacks *stacks);

int	main(int argc, char *argv[])
{
	t_stacks	*stacks;
	char		**args;
	int			is_allocate;

	args = NULL;
	is_allocate = 0;
	if (argc < 2)
		return (1);
	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (-1);
	if (argc == 2)
	{
		is_allocate = 1;
		args = ft_split(argv[1], ' ');
	}
	else
		args = argv;
	stacks->stack_b = NULL;
	stacks->stack_a = ft_int(args, argc, is_allocate);
	if (!stacks->stack_a)
		return (-1);
	main_extand(stacks);
	free_stacks_b(stacks);
	return (0);
}

void	main_extand(t_stacks *stacks)
{
	ft_input(stacks);
	if (is_sorted(stacks->stack_a) && !stacks->stack_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

t_list	*ft_int(char **args, int argc, int is_allocated)
{
	t_list	*temp;
	t_list	*res;
	int		x;
	long	nbr;
	int		err_status;

	res = NULL;
	if (argc == 2)
		x = 0;
	else
		x = 1;
	while (args[x])
	{
		nbr = ft_atoi(args[x], &err_status);
		if ((err_status == -3 || err_status == -7) || (nbr > INT_MAX
				|| nbr < INT_MIN) || (ft_check_num(res, nbr, args[x]) == 0))
			(ft_print_err(res, args, is_allocated), exit(-1));
		temp = ft_lstnew(nbr);
		ft_lstadd_back(&res, temp);
		x++;
	}
	if (is_allocated)
		_free_b(args, is_allocated);
	return (res);
}

void	ft_print_err(t_list *res, char **args, int is_allocated)
{
	ft_putstr_fd("Error Here MF\n", 2);
	free_lst_b(res);
	if (is_allocated)
		_free_b(args, is_allocated);
}

void	free_lst_b(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}
}
