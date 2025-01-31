/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:48:36 by jcologne          #+#    #+#             */
/*   Updated: 2025/01/31 17:37:08 by jcologne         ###   ########.fr       */
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

void	update_values(t_node *a, t_node *b)
{
	set_position(a);
	set_position(b);
	find_target(a, b);
}
