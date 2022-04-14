/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:00:50 by tkraikua          #+#    #+#             */
/*   Updated: 2022/04/07 21:00:50 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stks;

	check_arg(argc, argv);
	stks = init_stack(argc, argv);
	if (stks == NULL)
		return (1);
	quick_sort(stks);
	free_stacks(stks);
	return (0);
}
