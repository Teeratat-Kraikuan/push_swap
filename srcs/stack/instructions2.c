/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 02:02:15 by tkraikua          #+#    #+#             */
/*   Updated: 2022/04/10 02:02:15 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks *stks)
{
	t_node	*tmp;
	t_node	*iter;

	tmp = stks->a;
	iter = stks->a;
	stks->a = stks->a->link;
	while (!is_empty(iter->link))
		iter = iter->link;
	iter->link = tmp;
	tmp->link = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stacks *stks)
{
	t_node	*tmp;
	t_node	*iter;

	tmp = stks->b;
	iter = stks->b;
	stks->b = stks->b->link;
	while (!is_empty(iter->link))
		iter = iter->link;
	iter->link = tmp;
	tmp->link = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_stacks *stks)
{
	ra(stks);
	rb(stks);
}

void	rra(t_stacks *stks)
{
	t_node	*last;
	t_node	*p_last;

	last = stks->a;
	while (!is_empty(last->link))
	{
		p_last = last;
		last = last->link;
	}
	last->link = stks->a;
	stks->a = last;
	p_last->link = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_stacks *stks)
{
	t_node	*last;
	t_node	*p_last;

	last = stks->b;
	while (!is_empty(last->link))
	{
		p_last = last;
		last = last->link;
	}
	last->link = stks->b;
	stks->b = last;
	p_last->link = NULL;
	write(1, "rrb\n", 4);
}
