/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:50:51 by sarherna          #+#    #+#             */
/*   Updated: 2024/09/24 12:32:23 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putnbr(int n);
void	ft_putstr(char *str);
int		ft_atoi(const char *str);
void	send_char(int pid, char c);
void	handle_confirmation(int signum);
void	handle_signal(int signum, siginfo_t *info, void *context);

#endif