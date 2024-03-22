/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:15:54 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/21 16:12:14 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	ft_r(t_list **lst)
{
	t_list	*head;

	head = *lst;
	if (!(*lst) || !((*lst)->next))
		return ;
	*lst = head->next;
	head->next = NULL;
	ft_lstlast(*lst)->next = head;
}

void	ra(t_list **stack1)
{
	ft_r(stack1);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack2)
{
	ft_r(stack2);
	write(1, "rb\n", 3);
}

void	rr(t_list **lst1, t_list **lst2)
{
	ft_r(lst1);
	ft_r(lst2);
	write(1, "rr\n", 3);
}