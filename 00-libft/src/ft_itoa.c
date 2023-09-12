/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:54:50 by lle-saul          #+#    #+#             */
/*   Updated: 2023/09/12 16:54:50 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

int	ft_count(long n)
{
	int	i;

	i = 0;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		i;
	char	*str;

	nb = n;
	i = 2 + ft_count(nb);
	if (nb < 0)
	{
		i++;
		nb = nb * -1;
	}
	str = malloc(i * sizeof(char));
	str[i - 1] = '\0';
	i = i - 2;
	while (nb / 10 != 0)
	{
		str[i] = nb % 10 + 48;
		nb = nb / 10;
		i--;
	}
	str[i] = nb % 10 + 48;
	if (i == 1)
		str[0] = '-';
	return (str);
}
