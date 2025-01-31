/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:46:59 by jcologne          #+#    #+#             */
/*   Updated: 2025/01/31 16:13:09 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_node **a, t_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	while (len_a > 3)
	{
		pb(b, a);
		len_a = stack_len(*a);
	}
	sort_three(a);
	set_position(*a);
	print_stack(*a);
}
