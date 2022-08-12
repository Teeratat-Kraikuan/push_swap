/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 01:22:37 by tkraikua          #+#    #+#             */
/*   Updated: 2022/08/12 13:44:28 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi_ll(const char *str)
{
	size_t			i;
	long long		check_neg;
	long long		res;

	i = 0;
	check_neg = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			check_neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * check_neg);
}

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
	int			i;
	int			j;
	long long	tmp;

	if (argc == 1)
		exit(0);
	i = 1;
	while (i < argc)
	{
		tmp = ft_atoi_ll(argv[i]);
		if (!is_nbr(argv[i]))
			error();
		if (tmp > 2147483647)
			error();
		if (tmp < -2147483648)
			error();
		j = i + 1;
		while (j < argc)
		{
			if (tmp == ft_atoi_ll(argv[j]))
				error();
			j++;
		}
		i++;
	}
}
