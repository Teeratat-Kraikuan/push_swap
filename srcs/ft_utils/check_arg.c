/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 01:22:37 by tkraikua          #+#    #+#             */
/*   Updated: 2022/04/10 01:22:37 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

static int	is_nbr(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

void	check_arg(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		exit(0);
	i = 1;
	while (i < argc)
	{
		if (!is_nbr(argv[i]))
			error();
		i++;
	}
}
