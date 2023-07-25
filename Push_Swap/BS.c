/*
#include <stdio.h>
 
void count_to_ten ( int count )
{
	printf("%d\n", count);
     we only keep counting if we have a value less than ten 
       if ( count < 10 )   
       {
           count_to_ten( count + 1 );
       }
	printf("%d\n", count);
}*/

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
 
int main()
{
  //count_to_ten ( 0 ); /* First function call, so it starts at one */
  ft_realloc();
  return 0;
}
