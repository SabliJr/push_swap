/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:10:34 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/25 21:27:07 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	// t_list	*_list;
	if (lst == NULL)
		return (lst);
	// list = lst;
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}
