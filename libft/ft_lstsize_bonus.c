/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:07:19 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/26 19:00:51 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_lstsize(t_list *lst)
{
	long int	i;
	t_list		*temp;

	i = 0;
	temp = lst;
	if (temp == NULL)
		return (0);
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
