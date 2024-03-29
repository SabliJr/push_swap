/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:51:18 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/29 18:47:22 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

int	ft_check_num(t_list *lst, int num, char *nbr)
{
	t_list	*temp;
	int		j;

	temp = lst;
	j = 0;
	while (nbr[j])
	{
		if ((nbr[j] == '-' || nbr[j] == '+') && (nbr[j + 1] == '-' || nbr[j
					+ 1] == '+'))
			return (0);
		if (!ft_isdigit(nbr[j]) && !(j == 0 && nbr[j] == '-'))
			return (0);
		j++;
	}
	while (temp)
	{
		if (temp->content == num)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	is_sorted(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	while (temp->next)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_input(t_stacks *stacks)
{
	char	*input;

	input = get_next_line(0);
	while (input)
	{
		if (!ft_check_sort_res(input, stacks))
		{
			ft_putstr_fd("Error\n", 1);
			exit(-1);
		}
		input = get_next_line(0);
	}
}

int	ft_check_sort_res(char *input, t_stacks *stacks)
{
	if (ft_strcmp(input, "sa\n") == 0)
		sa(&stacks->stack_a);
	else if (ft_strcmp(input, "sb\n") == 0)
		sb(&stacks->stack_b);
	else if (ft_strcmp(input, "ra\n") == 0)
		ra(&stacks->stack_a);
	else if (ft_strcmp(input, "rb\n") == 0)
		rb(&stacks->stack_b);
	else if (ft_strcmp(input, "pa\n") == 0)
		pa(&stacks->stack_a, &stacks->stack_b);
	else if (ft_strcmp(input, "pb\n") == 0)
		pb(&stacks->stack_a, &stacks->stack_b);
	else if (ft_strcmp(input, "rr\n") == 0)
		rr(&stacks->stack_a, &stacks->stack_b);
	else if (ft_strcmp(input, "rra\n") == 0)
		rra(&stacks->stack_a);
	else if (ft_strcmp(input, "rrb\n") == 0)
		rrb(&stacks->stack_b);
	else if (ft_strcmp(input, "ss\n") == 0)
		ss(&stacks->stack_a, &stacks->stack_b);
	else
		return (free(input), 0);
	return (free(input), 1);
}

int	ft_strcmp(char *str, char *str1)
{
	size_t	i;

	i = 0;
	while (str[i] || str1[i])
	{
		if (str[i] != str1[i])
			return (str[i] - str1[i]);
		i++;
	}
	return (0);
}
