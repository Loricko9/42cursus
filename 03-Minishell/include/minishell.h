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

char	**get_redirec(char *str);
void	ft_case(char **env, char *line, void (*ft)(char **, char *, int (*fonction)(char **, char **), char **fd));

/*utils.c*/
void	init_signal(void);
void	exec_signal(int signum);
int		ft_strcmp_shell(const char *s1, const char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_find_char_quote(const char *s1, const char c);

/*utils2.c*/
int		ft_tablen(char **tab);
char	**dup_tab(char **tab);
int		ft_check_quote(char *line);
char	*ft_extract_str(char *str, int start, int end);

/*utils3.c*/
int		ft_strcmp(char *src, char *dest);

/*print.c*/
void	print_tab(char **tab);
void	ft_putchar(char c, int fd);
void	ft_putstr(char *str, int fd);

/*exec.c*/
void	fork_exec(char **env, char *line, int (*function)(char **, char **), char **fd);
char	*ft_clean_line(char *str);
int		ft_exec_prog(char **cmd, char **env);
int		ft_exec_cmd(char **cmd, char **env);

/*exec_utils.c*/
int		ft_path_env(char **env);
void	ft_free_var(char **cmd, char **env_path, char *path);
void	ft_free_tab(char **tab);
char	*ft_get_path(char **path, char *cmd);
char	*ft_strjoin(char *s1, char *s2);

/*exec_pipe.c*/
void	redirect_fd_pipe(int *fd_pipe, char **fd, int i);
void	ft_pipe(char **env, char **cmd);

/*get_fd.c*/
int		get_len_quote(char *str);
void	get_input(char **fd_in, char *line);
void	get_output(char **fd_out, char *line);


/*redirect_fd.c*/
void	ft_free_fd(char **fd);
int		ft_open_fd(char *fd_redir, char **fd, int nb_fd);
void	ft_redirect_fd(char *fd_redir, int fd_to, char **fd, int nb_fd);
void	ft_redirect_fd_pipe(int fd_redir, int fd_to, char **fd);


/*pipe.c*/
char	**ft_extract_cmd(char **cmd);

/*ft_split.c*/
char	**ft_split(char *s, char *c);
int		ft_find_char(const char *s1, const char c);

#endif

