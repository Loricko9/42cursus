/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:39:02 by lle-saul          #+#    #+#             */
/*   Updated: 2023/10/09 19:39:04 by lle-saul         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_printf.h"

void	ft_printpoint(long nb)
{
	if (nb == 0)
		ft_putstr("(nil)");
	else
	{
		ft_putstr("0x");
		ft_putlong_hexa(nb, "0123456789abcdef");
	}
}

void	ft_find(const char c, va_list args)
{
	if (c == 'c')
		ft_putchar((char)va_arg(args, int));
	else if (c == 's')
		ft_putstr((char *)va_arg(args, int *));
	else if (c == 'p')
		ft_printpoint(va_arg(args, long));
	else if (c == 'd')
		ft_putnbr(va_arg(args, int));
	else if (c == 'i')
		ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		ft_putnbr_hexa(va_arg(args, int), "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_hexa(va_arg(args, int), "0123456789ABCDEF");
	else if (c == '%')
		ft_putchar(c);
	else
		return ;
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			ft_putchar(str[i]);
		else
		{
			i++;
			if (str[i] == ' ' || str[i] == '#' || str[i] == '+')
			{
				ft_flags(str + i, args);
				i++;
			}
			ft_find(str[i], args);
		}
		i++;
	}
	va_end(args);
	return (0);
}
