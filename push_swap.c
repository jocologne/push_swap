/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:46:59 by jcologne          #+#    #+#             */
/*   Updated: 2025/01/31 18:15:01 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_node **a, t_node **b)
{
	//int	len_a;

	//len_a = stack_len(*a);
	/*while (len_a > 3)
	{
		pb(b, a);
		len_a = stack_len(*a);
	}
	sort_three(a);
	while (*b)
	{
		update_values(*a,*b);
		move_nodes(a,b);
	}*/
	set_position(*a);
	if (return_low(*a)->tophalf)
	{
		while(*a != return_low(*a))
			ra(a);
	}
	else
	{
		while(*a != return_low(*a))
			rra(a);
	}
	set_position(*a);
	set_position(*b);
	print_stack(*a);
}
