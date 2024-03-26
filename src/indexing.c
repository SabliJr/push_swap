/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:05:38 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/25 12:00:53 by sabakar-         ###   ########.fr       */
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
	// printf("The min in indexing function is %d\n", min);
}

int	min_nbr(t_list *lst)
{
	t_list		*temp;
	long int	min;

	min = LONG_MAX;
	// printf("The min from log max is: %ld\n", min);
	temp = lst;
	while (temp)
	{
		if (temp->index == -1 && temp->content < min)
			min = temp->content;
		temp = temp->next;
	}
	// printf("The min_nbr in indexing function is %ld\n", min);
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