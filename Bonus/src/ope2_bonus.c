/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope2_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:10:06 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/29 18:10:10 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

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
}

void	rb(t_list **stack2)
{
	ft_r(stack2);
}

void	rr(t_list **lst1, t_list **lst2)
{
	ft_r(lst1);
	ft_r(lst2);
}

void	free_stacks_b(t_stacks *stacks)
{
	free_lst_b(stacks->stack_a);
	free_lst_b(stacks->stack_b);
	free(stacks);
}
