/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:04:58 by tkraikua          #+#    #+#             */
/*   Updated: 2022/04/12 11:04:58 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(t_stacks *stks)
{
	while (!is_empty(stks->a))
	{
		if (is_empty(stks->b) || peek(stks, stks->a) >= peek(stks, stks->b))
			pb(stks);
		else
		{
			pa(stks);
			sa(stks);
		}
	}
	while (!is_empty(stks->b))
		pa(stks);
}
