/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:36:27 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/21 16:10:02 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>     // printf
# include <stdlib.h>    // malloc, free, exit
# include <unistd.h>    // write, access, close, fork, execve, dup, dup2, pipe
# include <signal.h>    // signal,sultant discovere sigaction, sigemptyset, sigaddset, kill
# include <sys/types.h> // definitions of data, like pid_t, gid_t, fork, getcwd
# include <sys/wait.h>  // wait, waitpid, wait3, wait4
# include <sys/stat.h>  // stat, lstat, fstat
# include <fcntl.h>     // open
# include <string.h>    // strerror
# include <errno.h>     // perror
# include <dirent.h>    // opendir, readdir, closedir
# include <termios.h>   // tcsetattr, tcgetattr
# include <termcap.h>   // tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
# include <readline/readline.h>     // readline
# include <readline/history.h>      // rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history
# include "../libft/libft.h"

typedef struct s_data
{
	char			**cmd; // aqui comando e flags
	char			**cmd_args; // aqui str
	char			**heredoc; // heredoc e seu delimitador/palavra
	struct s_rdct	**rdct; // lista redirect e seu arquivo
	char			**env;
	struct s_data	*next;
}			t_data;

typedef struct s_rdct
{
	char			*redirect;
	char			*file;
	struct s_rdct	*next;
}				t_rdct;

typedef struct s_token
{
	char			*name;
	char			*type;
	struct s_token	*next;
}				t_token;

typedef struct s_prompt
{
	char			*prompt_input;
}				t_prompt;


void	prompt(void);
int		is_builtins(char *check);

#endif