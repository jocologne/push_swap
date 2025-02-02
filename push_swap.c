/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:46:59 by jcologne          #+#    #+#             */
/*   Updated: 2025/02/01 22:01:15 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_a_b(t_node **a, t_node **b, t_node *best)
{
	while (*a != best->target && *b != best)
		rr(a, b);
	set_position(*a);
	set_position(*b);
}

static void	reverse_rotate_a_b(t_node **a, t_node **b, t_node *best)
{
	while (*a != best->target && *b != best)
		rrr(a, b);
	set_position(*a);
	set_position(*b);
}

static void	rotate_one(t_node **a, t_node **b, t_node *best)
{
	while (*a != best->target && best->target->tophalf)
		ra(a);
	while (*a != best->target && !best->target->tophalf)
		rra(a);
	while (*b != best && best->tophalf)
		rb(b);
	while (*b != best && !best->tophalf)
		rrb(b);
}

static void	move_nodes(t_node **a, t_node **b)
{
	t_node	*best;

	best = return_best(*b);
	if (best->tophalf && best->target->tophalf)
		rotate_a_b(a, b, best);
	if (!best->tophalf && !best->target->tophalf)
		reverse_rotate_a_b(a, b, best);
	rotate_one(a, b, best);
	pa(a, b);
}

void	push_swap(t_node **a, t_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	while (len_a > 3)
	{
		pb(b, a);
		len_a = stack_len(*a);
	}
	sort_three(a);
	while (*b)
	{
		update_values(*a, *b);
		move_nodes(a, b);
	}
	set_position(*a);
	if (return_low(*a)->tophalf)
	{
		while (*a != return_low(*a))
			ra(a);
	}
	else
	{
		while (*a != return_low(*a))
			rra(a);
	}
}
