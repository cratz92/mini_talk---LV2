/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:07:07 by cbrito-l          #+#    #+#             */
/*   Updated: 2021/12/17 21:35:07 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdbool.h>
# include "../_libft/libft.h"

# define DELAY_IN_MS 200

typedef struct s_args
{
	int		pid;
	char	*str;
}	t_args;

typedef struct s_char
{
	char	character;
	int		current_bit;
}	t_char;

/* CLIENT */

void	ft_send_chr(int pid, char c);
void	ft_send_messages(t_args *args);
void	returning_confirmation(int sig);

/* PARSE */

int		parse_args(int argc, char **argv, t_args *args);
int		check_pid(const char *str);

/* SERVER */

void	ft_print_pid(void);
void	ft_handle_message(int sig, siginfo_t *info, void *ucontext);
void	ft_handle_exit(int sig);

/* UTILITIES */

char	*whitespace(char *argv);

#endif 