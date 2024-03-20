/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:12:42 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/20 19:17:09 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int main (int argc, char *argv[])
{

  if (argc < 2 || (argc >= 2 && argv[1][0]))
    return (1);
  printf("This is the push swap project");
  return (0);
}
