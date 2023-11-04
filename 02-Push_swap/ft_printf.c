/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:12:50 by lle-saul          #+#    #+#             */
/*   Updated: 2023/10/10 18:12:50 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int nb, int *count)
{
	unsigned long	nbr;

	nbr = nb;
	if (nbr > 9)
		ft_putnbr_unsigned(nbr / 10, count);
	ft_putchar(nbr % 10 + 48, count);
}

void	ft_printpoint(unsigned long long nb, int *count)
{
	if (nb == 0)
		ft_putstr("(nil)", count);
	else
	{
		ft_putstr("0x", count);
		ft_putlong_hexa(nb, "0123456789abcdef", count);
	}
}

void	ft_find(const char c, va_list args, int *count)
{
	if (c == 'c')
		ft_putchar((char)va_arg(args, int), count);
	else if (c == 's')
		ft_putstr((char *)va_arg(args, int *), count);
	else if (c == 'p')
		ft_printpoint(va_arg(args, unsigned long long), count);
	else if (c == 'd')
		ft_putnbr(va_arg(args, int), count);
	else if (c == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), count);
	else if (c == 'x')
		ft_putnbr_hexa(va_arg(args, int), "0123456789abcdef", count);
	else if (c == 'X')
		ft_putnbr_hexa(va_arg(args, int), "0123456789ABCDEF", count);
	else if (c == '%')
		ft_putchar(c, count);
	else
		return ;
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			ft_putchar(str[i], &count);
		else
		{
			i++;
			ft_find(str[i], args, &count);
		}
		i++;
	}
	va_end(args);
	return (count);
}
