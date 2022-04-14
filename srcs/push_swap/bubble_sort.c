/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:06:14 by tkraikua          #+#    #+#             */
/*   Updated: 2022/04/14 13:06:14 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort_b(t_stacks *stks,int *len)
{
	int t_len;

	t_len = *len;
	while (--t_len)
	{
		if (stks->b->val < stks->b->link->val)
			sb(stks);
		pa(stks);
	}
	(*len)--;
}

static void sort_a(t_stacks *stks,int *len)
{
	int t_len;

	t_len = *len;
	while (--t_len)
	{
		if (stks->a->val > stks->a->link->val)
			sa(stks);
		pb(stks);
	}
	(*len)--;
}

void bubble_sort(t_stacks *stks)
{
	int	len;
	t_node	*temp;

	len = 0;
	temp = stks->a;
	while (temp)
	{
		temp = temp->link;
		len++;
	}
	while (len > 1)
	{
		sort_a(stks, &len);
		sort_b(stks, &len);
	}
	while (!is_empty(stks->b))
		pa(stks);
}