/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:10:37 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/24 16:59:31 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	quick_sort(t_list **stack1, t_list **stack2, int count)
{
	t_swap	swaps;

	swaps.next = find_min_lst(stack1)->index;
	swaps.max = find_max_lst(stack1)->index;
	swaps.mid = swaps.max / 2 + swaps.next;
	swaps.flag = 0;
	start_sorting(stack1, stack2, &swaps, count);
	while (!(check_sorting_a(*stack1, count)))
	{
		if (ft_lstsize(*stack2) == 0)
			quick_b(stack1, stack2, &swaps);
		else
			quick_a(stack1, stack2, &swaps);
	}
}

void	quick_b(t_list **stack1, t_list **stack2, t_swap *swaps)
{
	int	new_flag;

	new_flag = (*stack1)->flag;
	if ((*stack1)->flag != 0)
	{
		while ((*stack1)->flag == new_flag)
		{
			if ((*stack1)->index != swaps->next)
				pb(stack1, stack2);
			find_next(stack1, stack2, swaps);
		}
	}
	else if ((*stack1)->flag == 0)
	{
		while ((*stack1)->flag != -1)
		{
			if ((*stack1)->index != swaps->next)
				pb(stack1, stack2);
			find_next(stack1, stack1, swaps);
		}
	}
	if (ft_lstsize(*stack2))
		swaps->max = (find_max_lst(stack2))->index;
	swaps->mid = (swaps->max - swaps->next) / 2 + swaps->next;
}

void	quick_a(t_list **stack1, t_list **stack2, t_swap *swaps)
{
	int	count_b;
	int	i;

	i = -1;
	count_b = ft_lstsize(*stack2);
	while (ft_lstsize(*stack2) && ++i < count_b)
	{
		if ((*stack2)->index == swaps->next)
			find_next(stack1, stack2, swaps);
		else if ((*stack2)->index >= swaps->max)
		{
			(*stack2)->flag = swaps->flag;
			pa(stack1, stack2);
		}
		else if ((*stack2)->index < swaps->next)
			rb(stack2);
	}
	swaps->max = swaps->mid;
	swaps->mid = (swaps->max - swaps->next) / 2 + swaps->next;
	swaps->flag++;
}

void	find_next(t_list **stack1, t_list **stack2, t_swap *swaps)
{
	if (ft_lstsize(*stack2) > 0 && ((*stack2)->index == swaps->next))
		pa(stack1, stack2);
	else if ((*stack1)->index == swaps->next)
	{
		(*stack1)->flag = -1;
		ra(stack1);
		swaps->next++;
	}
	else if ((ft_lstsize(*stack2)) > 2
		&& ft_lstlast(*stack2)->index == swaps->next)
		rrb(stack2);
	else if ((*stack1)->next->index == swaps->next)
		sa(stack1);
	else if ((ft_lstsize(*stack1)) > 1
		&& ((*stack1)->next->index == swaps->next)
		&& ((*stack2)->next->index == swaps->next + 1))
		ss(stack1, stack2);
	else
		return ;
	find_next(stack1, stack2, swaps);
}

void	start_sorting(t_list **stack1, t_list **stack2, t_swap *swaps,
		int count)
{
	int i;

	i = -1;
	while (++i < count)
	{
		if ((*stack1)->index <= swaps->mid)
			pb(stack1, stack2);
		else
		{
			if (ft_lstsize(*stack2) > 1 && (*stack2)->index < (swaps->mid / 2))
				rr(stack1, stack2);
			else
				ra(stack1);
		}
	}
	swaps->max = swaps->mid;
	swaps->mid = (swaps->max - swaps->next) / 2 + swaps->next;
	swaps->flag++;
}