/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:11:21 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/14 21:51:56 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h> // write getpid pause sleep usleep
# include <signal.h> // signal sigemptyset sigaction kill
# include <stdlib.h> // malloc free exit

// ** My defined header files.
# include "../libft/libft.h"

// ** CLIENT FUNC
void	coder(int server_pid, char c);

// ** SERVER FUNC
void	decoder(int sig, siginfo_t *info, void *context);

#endif