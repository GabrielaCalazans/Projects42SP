/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:36:27 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/23 22:02:58 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <dirent.h>
# include <termios.h>
# include <termcap.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

// # define REDIRECT_IN	1
// # define REDIRECT_OUT	2
// # define PIPE			3
// # define FLAG			4
// # define SLASH			5
// # define QUESTION		6
// # define DOLLAR			7
// # define QUOTE_DOUBLE	8
// # define QUOTE_SINGLE	9
// # define SPACE			11
// # define APPEND			12
// # define HEREDOC			13

// **cmd; // aqui comando e flags
// **cmd_args; // aqui str
// **heredoc; // heredoc e seu delimitador/palavra
// **rdct; // lista redirect e seu arquivo
typedef struct s_data
{
	char			**cmd;
	char			**cmd_args;
	char			**heredoc;
	struct s_rdct	**rdct;
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
	char			*token;
	char			*type;
	struct s_token	*next;
}				t_token;

typedef struct s_prompt
{
	char			*prompt_input;
}				t_prompt;

void	prompt(void);
int		is_builtins(char *check);
//void	call_builtins(t_data *ptr);

// TOKENS
int		is_redirect(char c);
int		is_pipe(char c);
int		is_flag(char c);
int		is_slash(char c);
int		is_questionmark(char c);
int		is_dollar(char c);
int		is_quote(char c);
int		is_space(char c);
int		is_heredoc(char *str, int check);
int		find_type(char *str);
void	find_token(char *str);
int		is_redirect(char c);
int		find_type(char *str);


#endif