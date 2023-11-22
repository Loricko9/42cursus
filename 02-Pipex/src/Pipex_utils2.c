/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:06:51 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/20 11:06:51 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i], fd);
		i++;
	}
}

int check_file2(char *file2)
{
	if (access(file2, F_OK) == 0)
	{
		if (access(file2, W_OK) == -1)
			return (perror("pipex"), 1);
		else
			return (unlink(file2), 0);
	}
	else
		return (0);
}

int	ft_strcmp(char *src, char *dest)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] != dest[i])
			return (1);
		i++;
	}
	return (0);
}
