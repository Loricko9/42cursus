/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:48:04 by lle-saul          #+#    #+#             */
/*   Updated: 2023/08/11 17:48:04 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>

int	ft_isalpha(int c);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);

#endif