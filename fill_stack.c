/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:39:49 by jcologne          #+#    #+#             */
/*   Updated: 2025/01/31 23:05:55 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isnumber(char *s)
{
	if (!(*s == '+' || *s == '-' || (*s >= '0' && *s <= '9')))
		return (0);
	if ((*s == '+' || *s == '-') && !(s[1] >= '0' && s[1] <= '9'))
		return (0);
	if (s[0] == '+' || s[0] == '-')
		s++;
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9'))
			return (0);
		s++;
	}
	return (1);
}

int	repeats(t_node *stack, int n)
{
	while (stack)
	{
		if (stack->value == n)
		{
			return (1);
		}
		stack = stack->next;
	}
	return (0);
}

void	error_exit(t_node **stack)
{
	free_stack(stack);
	write(1, "Error\n", 5);
	exit(2);
}

void	insert_node(t_node **stack, int num)
{
	t_node	*new_node;
	t_node	*last_node;

	if (stack == NULL)
		return ;
	new_node = malloc (sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->value = num;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = return_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}
