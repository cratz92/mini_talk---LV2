/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:06:51 by cbrito-l          #+#    #+#             */
/*   Updated: 2021/12/17 20:02:52 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/* print the PID on screen */

void	ft_print_pid(void)
{
	pid_t	pid;
	char	*tmp;

	pid = getpid();
	tmp = ft_itoa(pid);
	if (!tmp)
	{
		ft_putendl_fd("Error...", 2);
		free(tmp);
		return ;
	}
	ft_putendl_fd(tmp, 1);
	free(tmp);
}

/* handle message  */

void	ft_handle_message(int sig, siginfo_t *info, void *ucontext)
{
	static t_char	chr = {0, 0};

	(void)ucontext;
	if (sig == SIGUSR2)
		chr.character |= 1 << chr.current_bit;
	chr.current_bit++;
	if (chr.current_bit == 8)
	{
		ft_putchar_fd(chr.character, 1);
		chr.character = 0;
		chr.current_bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

/* handle exit or end of message */

void	ft_handle_exit(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\nBYE\n", 6);
	exit (0);
}

int	main(void)
{
	struct sigaction	sa;

	ft_print_pid();
	sa.sa_handler = SIG_DFL;
	sa.sa_sigaction = ft_handle_message;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	signal(SIGINT, ft_handle_exit);
	signal(SIGTERM, ft_handle_exit);
	while (1)
		pause();
}
