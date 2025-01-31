/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:00:24 by jcologne          #+#    #+#             */
/*   Updated: 2025/01/31 16:09:29 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*return_high(t_node *stack)
{
	t_node	*result;
	long	high;

	result = stack;
	high = stack->value;
	while (stack)
	{
		if (stack->value > high)
		{
			high = stack->value;
			result = stack;
		}
		stack = stack->next;
	}
	return (result);
}

void sort_three(t_node **stack)
{
	if (*stack == return_high(*stack))
		ra(stack);
	else if ((*stack)->next == return_high(*stack))
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}