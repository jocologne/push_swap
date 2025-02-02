/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:31:33 by jcologne          #+#    #+#             */
/*   Updated: 2025/02/02 02:55:13 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//LIBS de teste
# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				position;
	int				tophalf;
	int				price;
	int				isbest;
	struct s_node	*prev;
	struct s_node	*next;
	struct s_node	*target;
}	t_node;

//stack_utils
t_node	*return_last_node(t_node *stack);
void	free_stack(t_node **stack);
void	set_position(t_node *stack);
int		stack_len(t_node *stack);
t_node	*return_low(t_node *stack);

//utils
long		ft_atol(char *n);
int		is_sorted(t_node *stack);

//fill_stack
int		isnumber(char *s);
int		repeats(t_node *stack, int n);
void	error_exit(t_node **stack);
void	insert_node(t_node **stack, int num);

//push commands
void	pa(t_node **a, t_node **b);
void	pb(t_node **b, t_node **a);

//rotate commands
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);

//reverse rotate commands
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

//swap commands
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);

//push_swap
void	push_swap(t_node **a, t_node **b);

//special_cases
void	sort_three(t_node **stack);

//update
void	update_values(t_node *a, t_node *b);
void	price(t_node *a, t_node *b);
t_node	*return_best(t_node *stack);

#endif
