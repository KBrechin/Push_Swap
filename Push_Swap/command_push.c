/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:26:18 by kbrechin          #+#    #+#             */
/*   Updated: 2023/07/25 16:33:43 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	take_top_a(int *stack_a, int *stack_b, t_push_swap *store)
{
	int				*swap_data;
	int				i;
	int				j;

	i = 1;
	j = 0;
	swap_data = malloc(sizeof(int) *(store->ori_arr_size));
	if (store->ori_arr_size != 0)
	{
		swap_data[0] = stack_a[0];
		while (j <= store->ori_arr_size - store->size_of_arr)
		{
			swap_data[i] = stack_b[j];
			i++;
			j++;
		}
		store->stack_b = swap_data;
	}
}

int	*clear_take_a(int *stack_a, t_push_swap *store)
{
	int				*swap_data;
	int				i;
	int				j;

	i = 1;
	j = 0;
	swap_data = malloc(sizeof(int) *(store->ori_arr_size));
	while (i < store->size_of_arr)
	{
		swap_data[j] = stack_a[i];
		j++;
		i++; 
	}
	return (swap_data);	
}

void	command_push_b(int *stack_a, int *stack_b, t_push_swap *store)
{
	take_top_a(stack_a, stack_b, store);
	store->stack_a = clear_take_a(stack_a, store);
	print_stack(store->stack_a, store->stack_b, store);
	store->size_of_arr = store->size_of_arr - 1;
}

void	take_top_b(int *stack_a, int *stack_b, t_push_swap *store)
{
	int				*swap_data;
	int				i;
	int				j;

	i = 1;
	j = 0;
	swap_data = malloc(sizeof(int) *(store->ori_arr_size));
	if (store->size_of_b != 0)
	{
		swap_data[0] = stack_b[0];
		while (j <= store->ori_arr_size)
		{
			swap_data[i] = stack_a[j];
			i++;
			j++;
		}
		store->stack_a = swap_data;
		store->size_of_b = store->size_of_b - 1;
	}
}

int	*clear_take_a(int *stack_b, t_push_swap *store)
{
	int				*swap_data;
	int				i;
	int				j;

	i = 1;
	j = 0;
	swap_data = malloc(sizeof(int) *(store->ori_arr_size - 1));
	while (i < store->size_of_b - 1)
	{
		swap_data[j] = stack_b[i];
		j++;
		i++; 
	}
	return (swap_data);
}

void	command_push_b(int *stack_a, int *stack_b, t_push_swap *store)
{
	take_top_a(stack_a, stack_b, store);
	store->stack_b = clear_take_a(stack_b, store);
	print_stack(store->stack_a, store->stack_b, store);
	store->size_of_b = store->size_of_b - 1;
}
