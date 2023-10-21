/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:47:24 by lle-saul          #+#    #+#             */
/*   Updated: 2023/10/20 13:47:24 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
char	*ft_line(t_list *lst, t_list *first);
char	*ft_strcat(t_list *lst);
int		ft_find(t_list *lst);
int		ft_strchr(char *str);
t_list	*ft_read(int fd, t_list *lst);
t_list	*ft_lstnew(char *str, int re);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#endif
