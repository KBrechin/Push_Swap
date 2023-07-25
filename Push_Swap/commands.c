/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:44:03 by kbrechin          #+#    #+#             */
/*   Updated: 2023/07/25 16:27:10 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*  The command_swap_a function will swap the first two elements 
	of an array, only if the array has more than one element and
	then print on the standered output "sa\n" */

void	command_swap_a(int *stack_a, t_push_swap store)
{
	int				swap_data;

	if (store.size_of_arr > 1)
	{
		swap_data = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = swap_data;
	}
	printf("sa\n");
}

/*  The command_swap_b function will swap the first two elements 
	of an array, only if the array has more than one element and
	then print on the standered output "sb\n" */

void	command_swap_b(int *stack_b, t_push_swap store)
{
	int				swap_data;

	if ((store.ori_arr_size - store.size_of_arr) >= 2)
	{
		swap_data = stack_b[0];
		stack_b[0] = stack_b[1];
		stack_b[1] = swap_data;
	}
	printf("sb\n");
}

/*  The command_swap_all function will swap the first two elements
	of two arrays, only if both arrays have more than one element and
	then print on the standered output "ss\n" */

void	command_swap_all(int *stack_a, int *stack_b, t_push_swap store)
{
	if (store.size_of_arr > 1 && (store.ori_arr_size - store.size_of_arr) >= 2)
	{
		command_swap_a(stack_a, store);
		command_swap_b(stack_b, store);
	}
	printf("ss\n");
}

void	command_push_b(int *stack_a, int *stack_b, t_push_swap *store)
{
	int				*swap_data_b;
	int				*swap_data_a;
	int				i;
	int				j;
	int				k;

	i = 1;
	j = 0;
	k = 2;
	swap_data_b = malloc(sizeof(int) *(store->ori_arr_size));
	swap_data_a = malloc(sizeof(int) *(store->size_of_arr));
	if (store->size_of_arr != 0)
	{
		swap_data_b[0] = stack_a[0];
		swap_data_a[0] = stack_a[i];
		while (j < store->ori_arr_size)
		{
			swap_data_b[i] = stack_b[j++];
			if (k < store->size_of_arr)
				swap_data_a[i++] = stack_a[k++];
		}
		print_stack(swap_data_a, swap_data_b, store);
		store->stack_b = swap_data_b;
		store->stack_a = swap_data_a;
		/*printf("--%d--\n", swap_data_b[0]);
		printf("--%d--\n", stack_b[0]);
		free(swap_data_b);
		free(swap_data_a);
		printf("--%d--\n", swap_data_b[0]);
		printf("--%d--\n", stack_b[0]);*/
		swap_data_a = NULL;
		swap_data_b = NULL;
		store->size_of_arr = store->size_of_arr - 1;
	}
}
