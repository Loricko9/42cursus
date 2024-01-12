/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:20:11 by lle-saul          #+#    #+#             */
/*   Updated: 2024/01/09 18:20:11 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "get_next_line.h"
# include "Pipex.h"

int		Pipex(int ac, char **av, char **env);

/*utils.c*/
void	init_signal(void);
void	exec_signal(int signum);
int		ft_strcmp_shell(const char *s1, const char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);


/*utils2.c*/
int		ft_tablen(char **tab);
char	**dup_tab(char **tab);
int		ft_check_quote(char *line);

/*print.c*/
void	print_tab(char **tab);

/*exec.c*/
void	fork_exec(char **env, char *line, int (*function)(char **, char **));
int		ft_exec_prog(char **cmd, char **env);

/*get_fd.c*/
void	get_input(int *fd_in, char *line);
void	get_output(int *fd_out, char *line);


#endif

