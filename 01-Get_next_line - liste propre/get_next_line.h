/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:50:05 by lle-saul          #+#    #+#             */
/*   Updated: 2023/10/21 16:50:05 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
char	*ft_line(t_list *stock);
void	ft_read(int fd, t_list **stock, int *size);
void	ft_add(t_list **stock, char *buff, int size);
void	ft_free_stock(t_list *stock);
void	ft_clear_stock(t_list **stock);
int		ft_strlen(char *str);
int		ft_get_size(t_list *stock);
int		ft_find(t_list *stock);
t_list	*ft_lstlast(t_list *stock);

#endif
