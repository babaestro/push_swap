/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa-ai <ababa-ai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:33:59 by ababa-ai          #+#    #+#             */
/*   Updated: 2024/08/15 16:01:02 by ababa-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	sort_less_than_five(t_stack *a, t_stack *b)
{
	int	size;

	size = stack_size(a);
	if (size <= 1)
		return ;
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
}

void	sort_two(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	top = a->top->value;
	mid = a->top->next->value;
	bot = a->top->next->next->value;
	if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a);
	else if (top > mid && mid < bot && top < bot)
		sa(a);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a);
}

void	sort_four(t_stack *a, t_stack *b)
{
	int	min;

	min = find_min(a);
	if (a->top->value != min)
	{
		if (a->top->next->value == min)
			sa(a);
		else if (a->top->next->next->value == min)
		{
			rra(a);
			rra(a);
		}
		else
			rra(a);
	}
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	min;

	min = find_min(a);
	if (a->top->value != min)
	{
		if (a->top->next->value == min)
			sa(a);
		else if (a->top->next->next->value == min)
		{
			ra(a);
			ra(a);
		}
		else if (a->top->next->next->next->value == min)
		{
			rra(a);
			rra(a);
		}
		else
			rra(a);
	}
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}
