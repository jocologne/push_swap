/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:46:59 by jcologne          #+#    #+#             */
/*   Updated: 2025/01/29 19:05:57 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_node **a, t_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	set_position(*a);
	print_stack(*a);
	while (len_a > 3)
	{
		pb(b, a);
		len_a = stack_len(*a);
	}
	set_position(*a);
	print_stack(*a);
	set_position(*b);
	print_stack(*b);
	sa(a);
	sb(b);
	set_position(*a);
	print_stack(*a);
	set_position(*b);
	print_stack(*b);
}