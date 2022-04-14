/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:38:15 by tkraikua          #+#    #+#             */
/*   Updated: 2022/04/09 01:38:15 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stack(t_node	*top)
{
	while (top)
	{
		ft_putnbr(top->val);
		write(1, " ", 1);
		top = top->link;
	}
	write(1, "\n", 1);
}

void	print_stacks(t_stacks *stks)
{
	ft_putstr("a: ");
	print_stack(stks->a);
	ft_putstr("b: ");
	print_stack(stks->b);
}

t_stacks	*init_stack(int argc, char **argv)
{
	t_stacks	*stks;

	stks = malloc(sizeof(t_stacks));
	if (stks == NULL)
		return (NULL);
	stks->a = NULL;
	stks->b = NULL;
	while (argc-- > 1)
		push(stks, &stks->a, ft_atoi(argv[argc]));
	return (stks);
}

void	free_stacks(t_stacks *stks)
{
	t_node	*temp;

	if (!stks)
		return ;
	while (stks->a)
	{
		temp = stks->a;
		stks->a = stks->a->link;
		free(temp);
	}
	while (stks->b)
	{
		temp = stks->b;
		stks->b = stks->b->link;
		free(temp);
	}
	free(stks);
}

void	stack_error(t_stacks *stks)
{
	free_stacks(stks);
	write(1, "Stack Error\n", 12);
	exit(1);
}
