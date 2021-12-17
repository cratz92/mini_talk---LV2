/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:31:09 by cbrito-l          #+#    #+#             */
/*   Updated: 2021/12/17 21:12:15 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

char	*whitespace(char *argv)
{
	int		i;
	char	*str;

	i = -1;
	if (!argv || !*argv)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(argv) + 1));
	if (!str)
		return (NULL);
	while (argv[++i])
	{
		if (argv[i] == '\f' || argv[i] == '\n' || argv[i] == '\r'
			|| argv[i] == '\t' || argv[i] == '\v')
			str[i] = ' ';
		else
			str[i] = argv[i];
	}
	str[i] = '\0';
	return (str);
}
