/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:54:12 by lle-saul          #+#    #+#             */
/*   Updated: 2023/10/08 11:54:12 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
#include <stdio.h>
void	ft_find(const char c, va_list args)
{
	if (c == 'c')
		ft_putchar((char)va_arg(args, int));
	else if (c == 's')
		ft_putstr((char *)va_arg(args, int *));
	else if (c == 'p')
		printf("non\n");
	else if (c == 'd')
		printf("non\n");
	else if (c == 'i')
		ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		printf("non\n");
	else if (c == 'x')
		ft_putnbr_hexa(va_arg(args, int), "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_hexa(va_arg(args, int), "0123456789ABCDEF");
	else if (c == '%')
		ft_putchar(c);
	else
		return ;
}
