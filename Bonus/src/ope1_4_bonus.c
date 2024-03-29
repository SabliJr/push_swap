/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope1_4_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:07:29 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/29 17:33:56 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

void	pb(t_list **stack1, t_list **stack2)
{
	t_list	*push_a;

	if (!*stack1)
		return ;
	push_a = (*stack1)->next;
	(*stack1)->next = *stack2;
	*stack2 = *stack1;
	*stack1 = push_a;
}

void	pa(t_list **stack1, t_list **stack2)
{
	t_list	*push_b;

	if (!*stack2)
		return ;
	push_b = (*stack2)->next;
	(*stack2)->next = *stack1;
	*stack1 = *stack2;
	*stack2 = push_b;
}

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
	ft_rr(lst1);
}

void	rrb(t_list **lst2)
{
	ft_rr(lst2);
}
