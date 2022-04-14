/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:39:00 by tkraikua          #+#    #+#             */
/*   Updated: 2022/04/07 23:39:00 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	swap(int *a, int *b);
int		ft_atoi(const char *str);

void	check_arg(int argc, char **argv);

#endif