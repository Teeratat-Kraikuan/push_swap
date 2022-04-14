/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:20:22 by tkraikua          #+#    #+#             */
/*   Updated: 2022/04/07 23:20:22 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_node *top)
{
	if (top == NULL)
		return (1);
	return (0);
}

int	is_only_one(t_node *top)
{
	if (top != NULL && top->link == NULL)
		return (1);
	return (0);
}

int	peek(t_stacks *stks, t_node *top)
{
	if (is_empty(top))
		stack_error(stks);
	return (top->val);
}

void	push(t_stacks *stks, t_node **top, int val)
{
	t_node	*temp;

	temp = malloc(sizeof(t_node));
	if (temp == NULL)
		stack_error(stks);
	temp->val = val;
	temp->link = *top;
	*top = temp;
}

void	pop(t_stacks *stks, t_node **top)
{
	t_node	*temp;

	if (is_empty(*top))
		stack_error(stks);
	temp = *top;
	*top = (*top)->link;
	free(temp);
}
