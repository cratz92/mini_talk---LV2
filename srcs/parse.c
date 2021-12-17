/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:46:59 by cbrito-l          #+#    #+#             */
/*   Updated: 2021/12/17 20:23:15 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	parse_args(int argc, char **argv, t_args *args)
{
	if ((argc != 3) || (!check_pid(argv[1])) || (!args))
	{
		return (0);
	}
	args->pid = ft_atoi(argv[1]);
	if (!(args->pid))
		return (0);
	args->str = whitespace(argv[2]);
	if (!args->str)
	{
		free(args->str);
		return (0);
	}
	return (1);
}

int	check_pid(const char *str)
{
	size_t	i;
	bool	ans;

	ans = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		else
			ans = 1;
		i++;
	}
	return (ans);
}
