/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 02:02:21 by tkraikua          #+#    #+#             */
/*   Updated: 2022/04/10 02:02:21 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stks)
{
	if (is_empty(stks->a) || is_only_one(stks->a))
		return ;
	swap(&stks->a->val, &stks->a->link->val);
	write(1, "sa\n", 3);
}

void	sb(t_stacks *stks)
{
	if (is_empty(stks->b) || is_only_one(stks->b))
		return ;
	swap(&stks->b->val, &stks->b->link->val);
	write(1, "sb\n", 3);
}

void	ss(t_stacks *stks)
{
	sa(stks);
	sb(stks);
}

void	pa(t_stacks *stks)
{
	if (is_empty(stks->b))
		return ;
	push(stks, &stks->a, peek(stks, stks->b));
	pop(stks, &stks->b);
	write(1, "pa\n", 3);
}

void	pb(t_stacks *stks)
{
	if (is_empty(stks->a))
		return ;
	push(stks, &stks->b, peek(stks, stks->a));
	pop(stks, &stks->a);
	write(1, "pb\n", 3);
}
