/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:36:39 by lle-saul          #+#    #+#             */
/*   Updated: 2023/10/09 19:38:37 by lle-saul         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_printf.h"

void	ft_flags(const char *str, va_list args)
{
	va_list	args_copy;

	va_copy(args_copy, args);
	if (str == '#')
	{
		if (*(str + 1) == 'x')
			ft_putstr("0x");
		if (*(str + 1) == 'X')
			ft_putstr("0X");
	}
	else if (str == ' ' || str == '+')
	{
		if (*(str + 1) == 'd' || *(str + 1) == 'i')
		{
			if (va_arg(args_copy, int) >= 0 && str == ' ')
				ft_putchar(' ');
			if (va_arg(args_copy, int) >= 0 && str == '+')
				ft_putchar('+');
		}
	}
	va_end(args_copy);
}
