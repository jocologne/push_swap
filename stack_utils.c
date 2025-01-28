/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:54:15 by jcologne          #+#    #+#             */
/*   Updated: 2025/01/28 18:05:45 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*return_last_node(t_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
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

void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*tmp;

	if (stack == NULL)
		exit(1);
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	set_position(t_node *stack)
{
	int	i;

	i = 0;
	while(stack)
	{
		stack->position = i++;
		stack = stack->next;
	}
}

int stack_len(t_node *stack)
{
	int	i;

	i = 0;
	while(stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}