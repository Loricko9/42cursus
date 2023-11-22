/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:27:35 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/17 17:27:35 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>

# include "get_next_line.h"

/*Pipex.c*/
int		ft_exec_cmd(char **cmd, char **env);
int		ft_redirect_fd(char *file1, char *file2, int i);
void	ft_pipe_exec(int pid, int *fd, char *cmd, char **env);
void	ft_create_pid(char *cmd, char **env);

/*Pipex_here_doc.c*/
void	ft_reading_here_doc(char *end, int *fd);
void	ft_here_doc(int *a, char *end);

/*Pipex_utils.c*/
int		ft_path_env(char **env);
char	*ft_get_path(char **path, char *cmd);
void	ft_free_tab(char **tab);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_free_var(char **cmd, char **env_path, char *path);

/*Pipex_utils2.c*/
void	ft_putchar(char c, int fd);
void	ft_putstr(char *str, int fd);
int		ft_strcmp(char *src, char *dest);
int		check_file2(char *file2);

/*ft_split.c*/
char	**ft_split(char const *s, char c);
size_t	ft_strlen_split(const char *s);

#endif

