/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa-ai <ababa-ai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:14:57 by ababa-ai          #+#    #+#             */
/*   Updated: 2024/08/11 17:25:54 by ababa-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	first = stack->top;
	last = stack->top;
	if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
		return ;
	while (last->next != NULL)
		last = last->next;
	stack->top = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack *stack_b, t_stack *stack_a)
{
	rotate(stack_b);
	rotate(stack_a);
	ft_printf("rr\n");
}
