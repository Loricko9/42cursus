/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:07:29 by lle-saul          #+#    #+#             */
/*   Updated: 2023/09/08 15:07:29 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest || !src)
		return (0);
	if (dest > src)
	{
		i = n - 1;
		while (i >= 0)
		{
			*(unsigned char*)(dest + i) = *(unsigned char*)(src + i);
			i--;
		}
	}
	else 
	{
		i = 0;
		while (i < n)
		{
			*(unsigned char*)(dest + i) = *(unsigned char*)(src + i);
			i++;
		}
	}
	return (dest);
}
