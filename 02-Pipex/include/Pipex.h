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
# include "ft_printf.h"

/*Pipex.c*/


/*Pipex_utils.c*/
char	*ft_get_path(char **path, char *cmd);
void	ft_free_tab(char **tab);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_free_var(char **cmd, char **env_path, char *path);

/*ft_split.c*/
char	**ft_split(char const *s, char c);
size_t	ft_strlen_split(const char *s);

#endif

