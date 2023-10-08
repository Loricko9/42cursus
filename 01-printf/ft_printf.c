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
			ft_find(str[i], args);
		}
		i++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	int test = 56;
	char *str = "salut";
	long int *i = 0;
	int *n = NULL;

	ft_printf("%p\n%p\n%p\n%p\n\n", &test, str, i, n);
	printf("%p\n%p\n%p\n%p\n", &test, str, i, n);
}
