/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:26:56 by kbrechin          #+#    #+#             */
/*   Updated: 2023/07/25 16:30:21 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_push_swap
{
	int		size_of_arr;
	int		ori_arr_size;
	int		size_of_b;
	int		*stack_a;
	int		*stack_b;
}	t_push_swap;

int	*fill_stack(int arg_size, char **arguments, t_push_swap store)
{
	int				i;
	int				start_at_numbers;
	int				*stack_a;

	i = 0;
	start_at_numbers = 1;
	stack_a = malloc((sizeof(int) * (arg_size + 1)));
	printf("size of arguments = %lu\n", (sizeof(int) * arg_size));
	while (i < arg_size - 1 && start_at_numbers < arg_size)
	{
		stack_a[i] = atoi(arguments[start_at_numbers]);
		i++;
		start_at_numbers++;
	}
	store.size_of_arr = i;
	return (stack_a);
}

int	*fill_blanc(int arguments_total)
{
	int	i;
	int	*stack_b;

	i = 0;
	stack_b = malloc(sizeof(int) * (arguments_total + 1));
	while (i < arguments_total)
		stack_b[i++] = 0;
	return (stack_b);
}

/*void	print_stack(int *stack_a, int *stack_b , t_push_swap *store)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (store->size_of_arr))
	{
		printf ("stack_a[%i] = %i", i, stack_a[i]);
		if (j < (store->ori_arr_size - store->size_of_arr))
			printf ("		stack_b[%i] = %i", j, stack_b[j]);
		printf("\n");
		i++;
		j++;
	}
}*/

void	print_stack(int *stack_a, int *stack_b , t_push_swap *store)
{
	int	i;
	int	j;
	int	size_stack2;

	i = 0;
	j = 0;
	size_stack2 = (store->ori_arr_size - store->size_of_arr);
	while (i < (store->size_of_arr) || j < size_stack2)
	{
		printf ("%i", stack_a[i]);
		if (stack_a[i] == 0)
			printf (" ");
		printf (" %i", stack_b[j]);
		printf("\n");
		i++;
		j++;
	}
	printf("-  -\n");
	printf("a  b\n");
}



int	main(int argc, char *argv[])
{
	int				i;
	t_push_swap		*store;

	i = 0;
	store = malloc(sizeof(int) * ((argc) * 2));
	//store = malloc(4);
	store->ori_arr_size = argc - 1;
	store->size_of_arr = store->ori_arr_size;
	store->size_of_b = (store->ori_arr_size - store->size_of_arr);
// Initalise stacks
	store->stack_a = fill_stack(argc, argv, *store);
	store->stack_b = fill_blanc(argc);
	print_stack(store->stack_a, store->stack_b, store);
// Test commands
	command_push_b(store->stack_a, store->stack_b, store);
	command_push_b(store->stack_a, store->stack_b, store);
	command_push_b(store->stack_a, store->stack_b, store);
	command_push_b(store->stack_a, store->stack_b, store);
	command_push_b(store->stack_a, store->stack_b, store);
	print_stack(store->stack_a, store->stack_b, store);
	printf("store current array size = %i\n", store->size_of_arr);
/*Checking arguments
	while (i < argc)
	{
		printf ("The input arguments are argv[%d] = %s\n", i, argv[i]);
		i++;
	}*/
}
