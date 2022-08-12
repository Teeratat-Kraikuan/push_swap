/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:11:18 by tkraikua          #+#    #+#             */
/*   Updated: 2022/08/12 13:53:05 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_cnt_nbr(char *str)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		while (str[i] != ' ' && str[i] != '\0')
			i++;
		cnt++;
	}
	return (cnt);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_dup(char *str)
{
	char *s;
	int	i;

	s = malloc(sizeof(char) * ft_strlen(str));
	i = 0;
	while (str[i] != ' ' && str[i] != '\0')
	{
		s[i] = str[i];
		i++;
	}
	return (s);
}

char **ft_split(int argc, char *argv0, char *argv1)
{
	char **str;
	int	i;
	int	j;

	str = malloc(sizeof(char*) * argc + 1);
	i = 1;
	j = 0;
	str[0] = argv0;
	while (argv1[j])
	{
		while (argv1[j] == ' ')
			j++;
		if (argv1[j] != ' ' && argv1[j] != '\0')
		{
			str[i] = ft_dup(&argv1[j]);
			i++;
		}
		while (argv1[j] != ' ' && argv1[j] != '\0')
			j++;
	}
	str[i] = 0;
	return (str);
}

int change_arg(int *argc, char ***argv)
{
	if (*argc != 2)
		return (0);
	*argc = ft_cnt_nbr(argv[0][1]) + 1;
	if (*argc == 1)
		return (0);
	argv[0] = ft_split(*argc, argv[0][0], argv[0][1]);
	return (1);
}