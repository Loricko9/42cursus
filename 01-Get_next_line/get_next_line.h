/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:30:08 by lle-saul          #+#    #+#             */
/*   Updated: 2023/10/12 17:30:08 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_line(char *stock, int *size);
char	*ft_read(int fd, char *stock, int *size);
char	*ft_clear_stock(char *stock, int *size);
char	*ft_calloc(size_t nmemb);
char	*ft_strcat(char *buff, char *stock, int size, int re);
char	*ft_strcpy(char *dest, char *src);
int		ft_find(char *stock, int size);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

#endif
