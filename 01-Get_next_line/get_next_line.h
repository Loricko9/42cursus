/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:30:08 by lle-saul          #+#    #+#             */
/*   Updated: 2023/10/18 17:17:31 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_line(char *stock);
char	*ft_read(int fd, char *stock);
char	*ft_clear_stock(char *stock);
char	*ft_calloc(size_t nmemb);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src, int size);
int		ft_find(char *stock);
int		ft_strlen(char *str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

#endif