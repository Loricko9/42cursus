/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_philo2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:04:38 by lle-saul          #+#    #+#             */
/*   Updated: 2023/12/11 18:04:38 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	act_vitcory(t_philo *lst)
{
	pthread_mutex_lock(&lst->victory.mutex_victory);
	if (lst->victory.nb_victory > 0)
		lst->victory.nb_victory = lst->victory.nb_victory - 1;
	pthread_mutex_unlock(&lst->victory.mutex_victory);
}
