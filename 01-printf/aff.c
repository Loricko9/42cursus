/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:34:18 by lle-saul          #+#    #+#             */
/*   Updated: 2023/10/08 11:34:18 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + 48);
}

void	ft_putlong_hexa(long nb, char *base)
{
	long long	nbr;

	nbr = nb;
	if (nbr > 15)
		ft_putlong_hexa(nbr / 16, base);
	ft_putchar(base[nbr % 16]);
}

void	ft_putnbr_hexa(unsigned int nb, char *base)
{
	unsigned long	nbr;

	nbr = nb;
	if (nbr > 15)
		ft_putnbr_hexa(nbr / 16, base);
	ft_putchar(base[nbr % 16]);
}
