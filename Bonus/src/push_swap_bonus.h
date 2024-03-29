/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:00:03 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/29 18:06:30 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../../gnl/get_next_line.h"
# include "../../libft/libft.h"

typedef struct s_stacks
{
	t_list	*stack_a;
	t_list	*stack_b;
}			t_stacks;

int			ft_check_num(t_list *lst, int num, char *nbr);
int			ft_strcmp(char *str, char *str1);
int			is_sorted(t_list *stack);
void		ft_input(t_stacks *stacks);
int			ft_check_sort_res(char *input, t_stacks *stacks);
int			ft_strcmp(char *str, char *str1);
void		_free_b(char **args, int is_allocated);
void		free_stacks_b(t_stacks *stacks);
void		free_lst_b(t_list *lst);

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

#endif