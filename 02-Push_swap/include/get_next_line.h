/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:30:08 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/16 15:24:57 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_lst
{
	char			*str;
	struct s_lst	*next;
}				t_lst;

char	*get_next_line(int fd);
char	*ft_line(t_lst *stock);
void	ft_read(t_lst **stock, int fd, int *size);
void	ft_add(t_lst **stock, char *buff, int size);
void	ft_clear_stock(t_lst **stock);
void	ft_free_stock(t_lst *stock);
t_lst	*ft_lstlast_get_next(t_lst *stock);
int		ft_get_size(t_lst *stock);
int		ft_find_get_next(t_lst *stock);
int		ft_strlen(char *str);

#endif
