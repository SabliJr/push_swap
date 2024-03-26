/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:21:20 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/25 21:28:57 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	check_sorting(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	while (temp && temp->next)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	check_sorting_a(t_list *lst, int count)
{
	int	len;

	len = ft_lstsize(lst);
	if (len != count)
		return (0);
	if (check_sorting(&lst) == 0)
		return (0);
	return (1);
}

t_list	*find_min_lst(t_list **lst)
{
	t_list	*temp;
	t_list	*min;

	min = *lst;
	temp = *lst;
	while (temp)
	{
		if (temp->content < min->content)
			min = temp;
		temp = temp->next;
	}
	// print_lst(min);
	return (min);
}

t_list	*find_max_lst(t_list **lst)
{
	t_list	*max;
	t_list	*temp;

	max = *lst;
	temp = *lst;
	while (temp)
	{
		if (temp->content > max->content)
			max = temp;
		temp = temp->next;
	}
	// print_lst(max);
	return (max);
}

int	is_rev_sorted(t_stacks *tab)
{
	t_list *temp;

	temp = tab->stack_a;
	while (temp->next)
	{
		if (temp->content < temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}