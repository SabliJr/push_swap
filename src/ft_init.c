/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:13:59 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/25 11:31:27 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_list	*ft_init(char **args, int argc)
{
	t_list	*temp;
	t_list	*res;
	int		i;
	long	nbr;

	if (argc == 2)
		i = 0;
	else
		i = 1;
	res = NULL;
	while (args[i])
	{
		nbr = ft_atoi(args[i]);
		if (nbr > INT_MAX || nbr < INT_MIN || (ft_check_int(res, nbr,
					args[i])) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			return (NULL);
		}
		temp = ft_lstnew(nbr);
		ft_lstadd_back(&res, temp);
		temp->index = -1;
		i++;
	}
	return (res);
}

int	ft_check_int(t_list *lst, int num, char *nbrs)
{
	t_list	*temp;
	int		k;

	temp = lst;
	k = 0;
	while (nbrs[k])
	{
		if ((nbrs[k] == '-' || nbrs[k] == '+') && (nbrs[k + 1] == '-' || nbrs[k
				+ 1] == '+'))
			return (0);
		else if (!ft_isdigit(nbrs[k]) && nbrs[k] != '-' && nbrs[k] != '+')
			return (0);
		k++;
	}
	while (temp)
	{
		if (temp->content == num)
			return (0);
		temp = temp->next;
	}
	return (1);
}
