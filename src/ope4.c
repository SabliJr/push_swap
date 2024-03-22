/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:35:23 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/21 19:34:05 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	ft_rr(t_list **lst)
{
	t_list	*temp;
	t_list	*end;

	if (!(*lst) || !((*lst)->next))
		return ;
	temp = *lst;
	end = ft_lstlast(*lst);
	while ((*lst)->next->next)
		*lst = (*lst)->next;
	end->next = temp;
	(*lst)->next = NULL;
	*lst = end;
}

void	rra(t_list **lst1)
{
	ft_rr(*lst1);
	write(1, "rra\n", 4);
}

void	rrb(t_list **lst2)
{
	ft_rr(lst2);
	write(1, "rrb\n", 4);
}