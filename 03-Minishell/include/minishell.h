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
char	*ft_substr(char *str, int start);

/*find.c*/
int		find_pipe(char *line);

/*print.c*/
void	print_tab(char **tab);

#endif

