/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:13:20 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/21 01:24:43 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
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

t_list		*ft_init(char **args, int argc);
int			ft_check_int(t_list *res, int num, char *nbr);
void		replace_index(t_list *lst, int i, int x);
int			min_nbr(t_list *lst);
void		add_index(t_list *lst);
int			check_sorting(t_list *lst);
int			check_sorting_a(t_list *lst, int count);
t_list		*find_min_lst(t_list **lst);
t_list		*find_max_lst(t_list **lst);
int			is_rev_sorted(t_stacks *tab);

#endif