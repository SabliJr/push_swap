/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:13:20 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/27 15:52:02 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_swap
{
	int		next;
	int		mid;
	int		max;
	int		flag;
}			t_swap;

typedef struct s_stacks
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		a_size;
	int		b_size;
}			t_stacks;

t_list		*ft_init(char **args, int argc, int is_allocated);
int			ft_check_int(t_list *res, int num, char *nbr);
void		replace_index(t_list *lst, int i, int x);
int			min_nbr(t_list *lst);
void		add_index(t_list *lst);
int			check_sorting(t_list **lst);
int check_sorting_a(t_list **lst, int count);
t_list		*find_min_lst(t_list **lst);
t_list		*find_max_lst(t_list **lst);
int			is_rev_sorted(t_stacks *tab);

void		ra(t_list **stack1);
void		pa(t_list **stack1, t_list **stack2);
void		pb(t_list **stack1, t_list **stack2);
void		rb(t_list **stack2);
void		rr(t_list **lst1, t_list **lst2);
void		ss(t_list **stack1, t_list **stack2);
void		sa(t_list **stack1);
void		sb(t_list **stack2);
void		rra(t_list **lst1);
void		rrb(t_list **lst2);
void		sort_5nbr(t_stacks *tab);
void		check_sort(t_stacks *stacks);
void		sort_3nbr(t_stacks *stacks);
void		quick_sort(t_list **stack1, t_list **stack2, int count);
void		start_sorting(t_list **stack1, t_list **stack2, t_swap *swaps,
				int count);
void		find_next(t_list **stack1, t_list **stack2, t_swap *swaps);
void		quick_a(t_list **stack1, t_list **stack2, t_swap *swaps);
void		quick_b(t_list **stack1, t_list **stack2, t_swap *push);
void		quick_sort(t_list **stack1, t_list **stack2, int count);
// void		print_lst(t_list *lst);

#endif