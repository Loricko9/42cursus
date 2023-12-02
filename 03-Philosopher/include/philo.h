/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:56:24 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/27 15:56:24 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_victory
{
	pthread_mutex_t	mutex_victory;
	int				nb_victory;
}	t_victory;

typedef struct s_data
{
	pthread_t	*th;
	struct		timeval start;
	struct		timeval end;
	int			nb_philo;
	int			t_die;
	int			t_sleep;
	int			t_eat;
	t_victory	victory;
}	t_data;

/*utils.c*/
long	ft_atoi(const char *nptr);

/*check.c*/
int		check_arg(char **av);

#endif

