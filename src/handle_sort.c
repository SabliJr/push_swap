/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:39:01 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/26 01:16:58 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	check_sort(t_stacks *stacks)
{
	int	len;

	len = ft_lstsize(stacks->stack_a);
	printf("The len of len in check sort is: %d\n", len);
	if (check_sorting(&stacks->stack_a))
		return ;
	if (len == 2)
	{
		if (stacks->stack_a->content > stacks->stack_a->next->content)
			sa(&stacks->stack_a);
	}
	else if (len == 3)
		sort_3nbr(stacks);
	else if (len == 5)
		sort_5nbr(stacks);
	else
		quick_sort(&stacks->stack_a, &stacks->stack_b,
			ft_lstsize(stacks->stack_a));
}

void	sort_5nbr(t_stacks *tab)
{
	int	len;

	len = ft_lstsize(tab->stack_a);
	while (len--)
	{
		if (tab->stack_a->index == 0 || tab->stack_a->index == 1)
			pb(&tab->stack_a, &tab->stack_b); // push to stack_b instead
		else
			ra(&tab->stack_a);
	}
	sort_3nbr(tab);
	pa(&tab->stack_a, &tab->stack_b); // push back to stack_a
	pa(&tab->stack_a, &tab->stack_b); // push back to stack_a
	if (tab->stack_a->content > tab->stack_a->next->content)
		sa(&tab->stack_a);
}

void	sort_3nbr(t_stacks *stacks)
{
	t_list *last;

	if (check_sorting(&stacks->stack_a))
		return ;
	last = ft_lstlast(stacks->stack_a);
	if (is_rev_sorted(stacks))
	{
		sa(&stacks->stack_a);
		rra(&stacks->stack_a);
	}
	else if (stacks->stack_a->content < last->content
		&& stacks->stack_a->next->content < last->content)
		sa(&stacks->stack_a);
	else if (stacks->stack_a->content > last->content
		&& stacks->stack_a->next->content < last->content)
		ra(&stacks->stack_a);
	else if (stacks->stack_a->content < last->content
		&& stacks->stack_a->next->content > last->content)
	{
		sa(&stacks->stack_a);
		ra(&stacks->stack_a);
	}
	else if (stacks->stack_a->content > last->content
		&& stacks->stack_a->next->content > last->content)
		rra(&stacks->stack_a);
}