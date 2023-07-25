/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:04:49 by kbrechin          #+#    #+#             */
/*   Updated: 2023/07/06 19:31:19 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_push_swap
{
	int		size_of_arr;
	int		ori_arr_size;
	char	*commands;
}	t_push_swap;

/*  The command_swap_a function will swap the first two elements 
	of an array, only if the array has more than one element and
	then print on the standered output "sa\n" */

void	command_swap_a(int *stack_a, t_push_swap store);

/*  The command_swap_b function will swap the first two elements 
	of an array, only if the array has more than one element and
	then print on the standered output "sb\n" */

void	command_swap_b(int *stack_b, t_push_swap store);




#endif