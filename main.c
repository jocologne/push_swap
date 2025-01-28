/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:29:13 by jcologne          #+#    #+#             */
/*   Updated: 2025/01/28 16:17:19 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void fill_stack(t_node **stack, char *str)
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

int main(int ac, char **av)
{
	t_node *a; //Cria o primeiro nó da lista a.

	a = NULL;
	if (ac == 1)
		error_exit(&a);
	av++;
	while (*av)
	{
		fill_stack(&a, *av);
		av++;
	}
	while (a)
	{
		printf("%d\n", a->value);
		a = a->next;
	}
	return (0);
}