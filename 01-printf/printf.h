/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:11:55 by lle-saul          #+#    #+#             */
/*   Updated: 2023/10/08 11:11:55 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_find(const char c, va_list args);
void	ft_putchar(const char c);
void	ft_putstr(const char *str);
void	ft_putnbr(int nb);
void	ft_putnbr_hexa(unsigned int nb, char *base);
void	ft_putlong_hexa(long nb, char *base);
void	ft_printpoint(long nb);

#endif
