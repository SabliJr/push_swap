/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:13:59 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/28 10:11:21 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	_free(char **args, int is_allocated)
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
	printf("This is the k value: %d\n", k);
}

t_list	*ft_init(char **args, int argc, int is_allocated)
{
	t_list	*temp;
	t_list	*res;
	int		i;
	long	nbr;

	res = NULL;
	temp = NULL;
	if (argc == 2)
		i = 0;
	else
		i = 1;
	while (args[i] && (i < argc || argc == 2))
	{
		nbr = ft_atoi(args[i]);
		if (nbr > INT_MAX || nbr < INT_MIN || (ft_check_int(res, nbr,
					args[i])) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			free_list(res);
			if (is_allocated)
				_free(args, is_allocated);
			return (NULL);
		}
		temp = ft_lstnew(nbr);
		ft_lstadd_back(&res, temp);
		temp->index = -1;
		i++;
	}
	if (is_allocated)
		_free(args, is_allocated);
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
