/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope3_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:12:08 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/29 17:47:58 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

static void	ft_s(t_list **lst)
{
	t_list	*temp;

	if (!(*lst) || !(*lst)->next)
		return ;
	temp = *lst;
	*lst = (*lst)->next;
	temp->next = (*lst)->next;
	(*lst)->next = temp;
}

void	sa(t_list **stack1)
{
	ft_s(stack1);
}

void	sb(t_list **stack2)
{
	ft_s(stack2);
}

void	ss(t_list **stack1, t_list **stack2)
{
	ft_s(stack1);
	ft_s(stack2);
}

void	_free_b(char **args, int is_allocated)
{
	int	k;

	k = 0;
	if (is_allocated)
	{
		while (args[k])
		{
			free(args[k]);
			k++;
		}
		free(args);
	}
}
