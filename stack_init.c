/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa-ai <ababa-ai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:01:20 by ababa-ai          #+#    #+#             */
/*   Updated: 2024/08/16 14:11:17 by ababa-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	return (stack);
}

void	push_stack(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
}

int	fill_stack_from_string(t_stack *stack_a, char *arg)
{
	char	**numbers;
	int		count;

	numbers = ft_split(arg, ' ');
	if (!numbers)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	count = 0;
	while (numbers[count])
		count++;
	while (--count >= 0)
	{
		if (check_range(stack_a, numbers[count]))
		{
			free_split(numbers);
			return (1);
		}
	}
	free_split(numbers);
	return (0);
}

int	fill_stack_from_args(t_stack *stack_a, int ac, char **av)
{
	int		i;
	long	value;

	i = ac - 1;
	while (i > 0)
	{
		value = ft_atol(av[i]);
		if (value < INT_MIN || value > INT_MAX)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		push_stack(stack_a, (int)value);
		i--;
	}
	return (0);
}

int	fill_stack_a(t_stack *stack_a, int ac, char **av)
{
	if (ac == 2)
		return (fill_stack_from_string(stack_a, av[1]));
	else
		return (fill_stack_from_args(stack_a, ac, av));
}
