/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa-ai <ababa-ai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:05:23 by ababa-ai          #+#    #+#             */
/*   Updated: 2024/08/15 16:10:34 by ababa-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	set_index(t_stack *a_stack)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = a_stack->top;
	index = 0;
	while (current)
	{
		index = 0;
		compare = a_stack->top;
		while (compare)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	get_max_bits(int size)
{
	int	max_bits;
	int	max_num;

	max_bits = 0;
	max_num = size - 1;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	ft_radix(t_stack *a_stack, t_stack *b_stack, int size)
{
	int	max_bits;
	int	index;
	int	i;
	int	j;

	max_bits = get_max_bits(size);
	index = a_stack->top->index;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			index = a_stack->top->index;
			if (((index >> i) & 1) == 0)
				pb(a_stack, b_stack);
			else
				ra(a_stack);
		}
		while (stack_size(b_stack) > 0)
			pa(a_stack, b_stack);
		i++;
	}
}
