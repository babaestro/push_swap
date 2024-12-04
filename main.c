/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa-ai <ababa-ai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:33:56 by ababa-ai          #+#    #+#             */
/*   Updated: 2024/08/15 16:04:23 by ababa-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (1);
	if (check_input(argv) || check_if_equals(argv, argc))
		return (1);
	stack_a = init_stack();
	stack_b = init_stack();
	if (!stack_a || !stack_b)
		return (1);
	if (fill_stack_a(stack_a, argc, argv) == 1)
		return (1);
	if (is_sorted(stack_a) == 1)
	{
		free_both_stacks(stack_a, stack_b);
		return (0);
	}
	set_index(stack_a);
	if (stack_size(stack_a) <= 5)
		sort_less_than_five(stack_a, stack_b);
	else
		ft_radix(stack_a, stack_b, stack_size(stack_a));
	free_both_stacks(stack_a, stack_b);
	return (0);
}
