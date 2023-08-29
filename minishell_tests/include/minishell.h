/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:36:27 by gacalaza          #+#    #+#             */
/*   Updated: 2023/08/28 20:47:15 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>     // printf
# include <stdlib.h>    // malloc, free, exit
# include <unistd.h>    // write, access, close, fork, execve, dup, dup2, pipe
# include <signal.h>    // signal, sigaction, sigemptyset, sigaddset, kill
# include <sys/types.h> // definitions of data, like pid_t, gid_t
# include <sys/wait.h>  // wait, waitpid, wait3, wait4
# include <sys/stat.h>  // stat, lstat, fstat
# include <fcntl.h>     // open
# include <string.h>    // strerror
# include <errno.h>     // perror
# include <dirent.h>    // opendir, readdir, closedir
# include <termios.h>   // tcsetattr, tcgetattr
// # include <curses.h>
# include <termcap.h>   // tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs

# include <readline/readline.h>     // readline
# include <readline/history.h>      // rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history
# include <sys/stat.h>             // stat, lstat, fstat
# include <unistd.h>                // getcwd, chdir, unlink, isatty, ttyname, ttyslot, ioctl
# include <sys/types.h>            // getcwd
# include <unistd.h>                // access
# include <sys/types.h>            // kill
# include <stdlib.h>               // exit
# include <sys/types.h>            // fork
# include <sys/wait.h>             // wait, waitpid, wait3, wait4
# include <signal.h>               // signal, sigaction, sigemptyset, sigaddset
# include <unistd.h>               // execve, dup, dup2, pipe
# include <dirent.h>               // opendir, readdir, closedir
# include <string.h>               // strerror
# include <stdio.h>                // perror
# include <unistd.h>               // isatty
# include <stdlib.h>               // getenv
# include <termios.h>              // tcsetattr, tcgetattr
# include <termcap.h>              // tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs




#endif