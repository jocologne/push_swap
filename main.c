/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:29:13 by jcologne          #+#    #+#             */
/*   Updated: 2025/02/02 02:41:52 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_stack(t_node **stack, char *str)
{
	long	n;

	if (!isnumber(str))
		error_exit(stack);
	n = ft_atol(str);
	if (n < INT_MIN || n > INT_MAX)
		error_exit(stack);
	if (repeats(*stack, n))
		error_exit(stack);
	insert_node(stack, n);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || ac == 2)
	{
		return (1);
	}
	av++;
	while (*av)
	{
		fill_stack(&a, *av);
		av++;
	}
	if (is_sorted(a))
	{
		free_stack(&a);
		return (1);
	}
	push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
