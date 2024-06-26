/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:55:07 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/28 09:22:02 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(*new_list) * 1);
	if (!new_list)
		return (NULL);
	new_list->content = content;
	new_list->next = NULL;
	new_list->flag = 0;
	new_list->index = 0;
	return (new_list);
}
