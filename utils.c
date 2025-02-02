/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:38:42 by jcologne          #+#    #+#             */
/*   Updated: 2025/02/02 02:55:25 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *n)
{
	int		sign;
	long	num;
	int		i;

	i = 0;
	sign = 1;
	num = 0;
	if (n[i] == '\0')
		return (0);
	while ((n[i] >= 9 && n[i] <= 13) || n[i] == 32)
		i++;
	if (n[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (n[i] == '+')
		i++;
	while (n[i] >= '0' && n[i] <= '9')
	{
		num = (num * 10) + (n[i]) - 48;
		i++;
	}
	return (num * sign);
}

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->next->value < stack->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
