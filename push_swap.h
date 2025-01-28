/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:31:33 by jcologne          #+#    #+#             */
/*   Updated: 2025/01/28 16:12:37 by jcologne         ###   ########.fr       */
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
	struct s_node	*prev;
	struct s_node	*next;
} t_node;

//stack_utils
t_node	*return_last_node(t_node *stack);
void		insert_node(t_node **stack, int num);
void		free_stack(t_node **stack);

//utils
int		ft_atol(const char *n);

//error_check
int	isnumber(char *s);
int	repeats(t_node *stack, int n);
void	error_exit(t_node **stack);

#endif
