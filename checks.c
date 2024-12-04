/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa-ai <ababa-ai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 15:53:25 by ababa-ai          #+#    #+#             */
/*   Updated: 2024/08/16 15:39:15 by ababa-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (stack == NULL || stack->top == NULL)
		return (1);
	current = stack->top;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	is_empty(t_stack *stack)
{
	if (stack->top == NULL)
		return (1);
	else
		return (0);
}

int	check_range(t_stack *stack_a, char *str)
{
	long	value;

	value = ft_atol(str);
	if (value < INT_MIN || value > INT_MAX)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	push_stack(stack_a, (int)value);
	return (0);
}

int	check_input(char **av)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	if (av[j][i] == 0)
		write(2, "Error\n", 6);
	while (av[j])
	{
		i = 0;
		while (av[j][i] == '+' || av[j][i] == '-')
			i++;
		while (av[j][i] != '\0')
		{
			if ((av[j][i] < '0' || av[j][i] > '9') && av[j][i] != ' ')
			{
				write(2, "Error\n", 6);
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	check_if_equals(char **av, int ac)
{
	int	x;
	int	y;

	x = 1;
	while (x < ac)
	{
		y = x + 1;
		while (y < ac)
		{
			if (ft_atol(av[x]) == ft_atol(av[y]))
			{
				write(2, "Error\n", 6);
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}
