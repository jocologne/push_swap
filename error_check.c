/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:39:49 by jcologne          #+#    #+#             */
/*   Updated: 2025/01/28 17:29:59 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isnumber(char *s)
{
	if (!(*s == '+' || *s == '-' || (*s >= '0' && *s <= '9')))
		return (0);
	if ((*s == '+' || *s == '-') && !(s[1] >= '0' && s[1] <= '9'))
		return (0);
	while (*++s)
	{
		if (!(*s >= '0' && *s <= '9'))
			return (0);
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
	write(1, "Argument Error\n", 14);
	exit(2);
}
