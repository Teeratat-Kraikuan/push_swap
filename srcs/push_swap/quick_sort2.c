/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:01:02 by tkraikua          #+#    #+#             */
/*   Updated: 2022/04/13 22:01:02 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	linear_bubble_sort(int **array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[0][j] > array[0][j + 1])
				swap(&array[0][j], &array[0][j + 1]);
			j++;
		}
		i++;
	}
}

int	get_median(t_stacks *stks, t_node *node, int len)
{
	int	*array;
	int	median;
	int	index;
	int	s_len;

	array = (int *) malloc(sizeof(int) * len);
	if (!array)
		stack_error(stks);
	s_len = len;
	index = 0;
	while (len--)
	{
		array[index] = node->val;
		node = node->link;
		index++;
	}
	linear_bubble_sort(&array, s_len);
	median = array[s_len / 2];
	free(array);
	return (median);
}

int	is_sorted(t_node *node, int len, int mode)
{
	while (--len)
	{
		if (mode == ASCENDING)
		{
			if (node->val > node->link->val)
				return (0);
			node = node->link;
		}
		else if (mode == DESCENDING)
		{
			if (node->val < node->link->val)
				return (0);
			node = node->link;
		}
	}
	return (1);
}