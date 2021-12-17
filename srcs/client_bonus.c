/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:07:01 by cbrito-l          #+#    #+#             */
/*   Updated: 2021/12/17 21:11:31 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

int	flag;

/* send a character or a bit to the address PID */

void	ft_send_chr(int pid, char c)
{
	int	current_bit;

	current_bit = 0;
	while (current_bit < 8)
	{
		if (c & (1 << current_bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(DELAY_IN_MS);
		current_bit++;
	}
}

void	ft_send_message(t_args *args)
{
	size_t	i;

	i = 0;
	if (!args)
		return ;
	while (args->str[i])
	{
		ft_send_chr(args->pid, args->str[i]);
		i++;
	}
	ft_send_chr(args->pid, '\n');
}

/* handle return confirmation */

void	returning_confirmation(int sig)
{
	int	*a;

	(void)sig;
	a = &flag;
	if (!*a)
	{
		write(STDOUT_FILENO, "SENT\n", 5);
		(*a)+= 1;
	}
}

int	main(int argc, char **argv)
{
	t_args	args;
	int		*a;

	a = &flag;
	signal(SIGUSR1, returning_confirmation);
	if (!parse_args(argc, argv, &args))
	{
		ft_putendl_fd("ERROR", 2);
		return (1);
	}
	ft_send_message(&args);
	*a = 0;
	free((&args)->str);
	return (0);
}
