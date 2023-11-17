/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:13:30 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/16 15:24:51 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_find(const char c, va_list args, int *count);
void	ft_printpoint(unsigned long long nb, int *count);
void	ft_putchar(const char c, int *count);
void	ft_putstr(const char *str, int *count);
void	ft_putnbr(int nb, int *count);
void	ft_putlong_hexa(unsigned long long nb, char *base, int *count);
void	ft_putnbr_hexa(unsigned int nb, char *base, int *count);
void	ft_putnbr_unsigned(unsigned int nb, int *count);

#endif
