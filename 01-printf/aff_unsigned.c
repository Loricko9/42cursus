/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:00:35 by lle-saul          #+#    #+#             */
/*   Updated: 2023/10/10 18:00:35 by lle-saul         ###   ########.fr       */
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
