/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa-ai <ababa-ai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:29:40 by ababa-ai          #+#    #+#             */
/*   Updated: 2024/08/16 15:39:33 by ababa-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	int				index;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
}	t_stack;

t_stack	*init_stack(void);
void	push_stack(t_stack *stack, int value);
int		fill_stack_a(t_stack *stack_a, int ac, char **av);
void	top_swap(t_stack *stack);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack *src, t_stack *dest);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_b, t_stack *stack_a);
void	rev_rotate(t_stack *stack);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
int		is_sorted(t_stack *stack);
int		stack_size(t_stack *stack);
void	sort_less_than_five(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	cases_of_three(t_stack *a, int top, int mid, int bot);
void	sort_more_than_three(t_stack *a, t_stack *b, int size);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
void	free_stack(t_stack *stack);
void	free_both_stacks(t_stack *stack_a, t_stack *stack_b);
int		is_empty(t_stack *stack);
int		check_range(t_stack *stack_a, char *str);
void	free_split(char **split);
int		check_input(char **av);
int		check_if_equals(char **av, int ac);
void	sort_large_stack(t_stack *stack_a, t_stack *stack_b);
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	ft_radix(t_stack *a_stack, t_stack *b_stack, int size);
int		get_max_bits(int size);
void	set_index(t_stack *a_stack);

#endif