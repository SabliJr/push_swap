/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:05:38 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/21 12:34:10 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	add_index(t_list *lst)
{
	int	len;
	int	min;
	int	i;

	i = 0;
	len = ft_lstsize(lst);
	while (i < len)
	{
		min = min_nbr(lst);
		replace_index(lst, min, i);
		i++;
	}
}

int	min_nbr(t_list *lst)
{
	t_list		*temp;
	long int	min;

	min = LONG_MAX;
	temp = lst;
	while (temp)
	{
		if (temp->index == -1 && temp->content < min)
			min = temp->content;
		temp = temp->next;
	}
	return (min);
}

void	replace_index(t_list *lst, int i, int x)
{
	t_list *temp;

	temp = lst;
	while (temp)
	{
		if (temp->index == -1 && temp->content == i)
			break ;
		temp = temp->next;
	}
	temp->index = x;
}