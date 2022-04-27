/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:10:01 by tkraikua          #+#    #+#             */
/*   Updated: 2022/04/13 17:10:01 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	quick_sort_a(t_stacks *stks, int len);
static void	quick_sort_b(t_stacks *stks, int len);

static int	small_case_b(t_stacks *stks, int len)
{
	if (len == 2)
	{
		if (stks->b->val < stks->b->link->val)
			sb(stks);
	}
	else if (len == 3)
	{
		if (stks->b->val < stks->b->link->val)
			sb(stks);
		if (stks->b->link->val < stks->b->link->link->val)
		{
			pa(stks);
			sb(stks);
			pb(stks);
		}
		if (stks->b->val < stks->b->link->val)
			sb(stks);
	}
	while (len--)
		pa(stks);
	return (1);
}

static void	quick_sort_b(t_stacks *stks, int len)
{
	int	a_len;
	int	pivot;
	int	go_back;

	if (is_sorted(stks->b, len, DESCENDING))
		while (len--)
			pa(stks);
	if (len == -1 || (len <= 3 && small_case_b(stks, len)))
		return ;
	a_len = 0;
	go_back = 0;
	pivot = get_median(stks, stks->b, len);
	while (a_len != len / 2 + len % 2 - 1)
	{
		if (stks->b->val > pivot && ++a_len)
			pa(stks);
		else if (++go_back)
			rb(stks);
	}
	while (go_back--)
		rrb(stks);
	quick_sort_a(stks, a_len);
	quick_sort_b(stks, len - a_len);
}

static int	small_case_a(t_stacks *stks, int len)
{
	if (len == 2)
	{
		if (stks->a->val > stks->a->link->val)
			sa(stks);
	}
	else if (len == 3)
	{
		if (stks->a->val > stks->a->link->val)
			sa(stks);
		if (stks->a->link->val > stks->a->link->link->val)
		{
			pb(stks);
			sa(stks);
			pa(stks);
		}
		if (stks->a->val > stks->a->link->val)
			sa(stks);
	}
	return (1);
}

static void	quick_sort_a(t_stacks *stks, int len)
{
	int	b_len;
	int	pivot;
	int	go_back;

	if (is_sorted(stks->a, len, ASCENDING))
		return ;
	if (len <= 3 && small_case_a(stks, len))
		return ;
	b_len = 0;
	go_back = 0;
	pivot = get_median(stks, stks->a, len);
	while (b_len != len / 2)
	{
		if (stks->a->val < pivot && ++b_len)
			pb(stks);
		else if (++go_back)
			ra(stks);
	}
	while (go_back--)
		rra(stks);
	quick_sort_a(stks, len - b_len);
	quick_sort_b(stks, b_len);
}

void	quick_sort(t_stacks *stks)
{
	int		len;
	t_node	*temp;

	len = 0;
	temp = stks->a;
	while (temp)
	{
		temp = temp->link;
		len++;
	}
	if (is_sorted(stks->a, len, ASCENDING))
		return ;
	if (len <= 5)
		simple_sort(stks, len);
	quick_sort_a(stks, len);
}
