/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:01:04 by tkraikua          #+#    #+#             */
/*   Updated: 2022/04/07 21:01:04 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

# include "ft_utils.h"
# include "stack.h"

# define ASCENDING 0
# define DESCENDING 1

void	insertion_sort(t_stacks *stks);

void	quick_sort(t_stacks *stks);
int		get_median(t_stacks *stks, t_node *node, int len);
int		is_sorted(t_node *node, int len, int mode);

#endif