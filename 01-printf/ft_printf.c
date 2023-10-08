/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:10:23 by lle-saul          #+#    #+#             */
/*   Updated: 2023/10/08 11:10:23 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
#include <stdio.h>
int ft_printf(const char *str, ...)
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
			ft_find(str[i], args);
		}
		i++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	ft_printf("%x\n%x\n%x\n%X\n%X\n%X\n\n", -16, 15, -1, 27, 1, -89875);
	printf("%x\n%x\n%x\n%X\n%X\n%X\n", -16, 15, -1, 27, 1, -89875);
}
