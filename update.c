/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:48:36 by jcologne          #+#    #+#             */
/*   Updated: 2025/02/01 22:00:22 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_target(t_node *a, t_node *b)
{
	t_node	*anode;
	t_node	*target;
	long	guess;

	while (b)
	{
		guess = LONG_MAX;
		anode = a;
		while (anode)
		{
			if (anode->value > b->value && anode->value < guess)
			{
				guess = anode->value;
				target = anode;
			}
			anode = anode->next;
		}
		if (guess == LONG_MAX)
			b->target = return_low(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	price(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->price = b->position;
		if (!(b->tophalf))
			b->price = len_b - b->position;
		if (b->target->tophalf)
			b->price = b->price + b->target->position;
		else
			b->price = b->price + (len_a - b->target->position);
		b = b->next;
	}
}

static void	best_price(t_node *b)
{
	long		best;
	t_node		*result;

	result = NULL;
	best = LONG_MAX;
	while (b)
	{
		b->isbest = 0;
		if (b->price < best)
		{
			best = b->price;
			result = b;
		}
		b = b->next;
	}
	if (result)
		result->isbest = 1;
}

t_node	*return_best(t_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->isbest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	update_values(t_node *a, t_node *b)
{
	set_position(a);
	set_position(b);
	find_target(a, b);
	price(a, b);
	best_price(b);
}
