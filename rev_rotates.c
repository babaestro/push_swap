/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa-ai <ababa-ai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 15:14:04 by ababa-ai          #+#    #+#             */
/*   Updated: 2024/08/04 15:45:00 by ababa-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	rev_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*second_last;

	last = stack->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = stack->top;
	stack->top = last;
	second_last->next = NULL;
}

void	rra(t_stack *stack_a)
{
	rev_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack *stack_b)
{
	rev_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_printf("rrr\n");
}
