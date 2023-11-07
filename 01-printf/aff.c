/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:00:23 by lle-saul          #+#    #+#             */
/*   Updated: 2023/10/10 18:00:23 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(const char c, int *count)
{
	*count = *count + write(1, &c, 1);
}

void	ft_putstr(const char *str, int *count)
{
	int	i;

	if (!str)
	{
		ft_putstr("(null)", count);
		return ;
	}
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i], count);
		i++;
	}
}

void	ft_putnbr(int nb, int *count)
{
	long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-', count);
		nbr = nbr * -1;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10, count);
	ft_putchar(nbr % 10 + 48, count);
}

void	ft_putlong_hexa(unsigned long long nb, char *base, int *count)
{
	if (nb > 15)
		ft_putlong_hexa(nb / 16, base, count);
	ft_putchar(base[nb % 16], count);
}

void	ft_putnbr_hexa(unsigned int nb, char *base, int *count)
{
	unsigned long	nbr;

	nbr = nb;
	if (nbr > 15)
		ft_putnbr_hexa(nbr / 16, base, count);
	ft_putchar(base[nbr % 16], count);
}
