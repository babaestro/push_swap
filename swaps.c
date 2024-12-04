/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa-ai <ababa-ai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:17:15 by ababa-ai          #+#    #+#             */
/*   Updated: 2024/08/11 17:21:44 by ababa-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	top_swap(t_stack *stack)
{
	int	temp;

	if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
		return ;
	temp = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = temp;
}

void	sa(t_stack *stack_a)
{
	top_swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	top_swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	top_swap(stack_a);
	top_swap(stack_b);
	ft_printf("ss\n");
}
