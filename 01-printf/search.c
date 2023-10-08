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
		printf("non\n");
	else if (c == 'u')
		printf("non\n");
	else if (c == 'x')
		printf("non\n");
	else if (c == 'X')
		printf("non\n");
	else if (c == '%')
		ft_putchar(c);
	else
		return ;
}
