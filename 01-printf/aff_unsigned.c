/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:39:23 by lle-saul          #+#    #+#             */
/*   Updated: 2023/10/09 19:39:25 by lle-saul         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int nb)
{
	unsigned long	nbr;

	nbr = nb;
	if (nbr > 9)
		ft_putnbr_unsigned(nbr / 10);
	ft_putchar(nbr % 10 + 48);
}
