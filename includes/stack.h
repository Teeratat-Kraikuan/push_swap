/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:07:13 by tkraikua          #+#    #+#             */
/*   Updated: 2022/04/07 21:07:13 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				val;
	struct s_node	*link;
}	t_node;

typedef struct s_stacks
{
	struct s_node	*a;
	struct s_node	*b;
}	t_stacks;

int			is_empty(t_node *top);
int			is_only_one(t_node *top);
int			peek(t_stacks *stks, t_node *top);
void		push(t_stacks *stks, t_node **top, int val);
void		pop(t_stacks *stks, t_node **top);

t_stacks	*init_stack(int argc, char **argv);
void		free_stacks(t_stacks *stks);
void		print_stacks(t_stacks *stks);
void		stack_error(t_stacks *stks);

void		sa(t_stacks *stks);
void		sb(t_stacks *stks);
void		ss(t_stacks *stks);
void		pa(t_stacks *stks);
void		pb(t_stacks *stks);
void		ra(t_stacks *stks);
void		rb(t_stacks *stks);
void		rr(t_stacks *stks);
void		rra(t_stacks *stks);
void		rrb(t_stacks *stks);
void		rrr(t_stacks *stks);

#endif