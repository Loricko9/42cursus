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

typedef struct s_fork
{
	pthread_mutex_t	mutex_fork;
	int				fork;
}	t_fork;

typedef struct s_death
{
	struct timeval	last_act;
	float			death;
}	t_death;

typedef struct s_data
{
	struct		timeval start;
	int			t_die;
	int			t_sleep;
	int			t_eat;
	int			state;
}	t_data;

typedef struct s_philo
{
	int				nb_philo;
	pthread_t		thread;
	t_fork			fork;
	t_death			death;
	t_victory		victory;
	t_data			*data;
	struct s_philo	*next;
}	t_philo;

void	print_lst(t_philo *lst);

/*utils.c*/
long	ft_atoi(const char *nptr);

/*lst_utils.c*/
t_philo	*ft_lstnew(int n_philo, int n_victory, t_data *ptr_data);
t_philo	*ft_lstlast(t_philo *lst);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
void	ft_lst_free(t_philo *lst);
int		ft_lstsize(t_philo *lst);

/*check.c*/
int		check_int(char **av);
int		check_char(char **av);
int		check_arg(char **av);
int		verif_victory(t_philo *lst);

/*act_philo.c*/
float	time_diff(struct timeval *start, struct timeval *end);
void	act_death(t_philo *lst);
void	act_death2(t_philo *lst);

#endif
