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

typedef struct s_eat
{
	pthread_mutex_t	mutex_eat;
	long			last_eat;
}	t_eat;

typedef struct s_data
{
	pthread_mutex_t	writing;
	long	start;
	int		size;
	int		t_die;
	int		t_sleep;
	int		t_eat;
	int		state;
}	t_data;

typedef struct s_philo
{
	int				nb_philo;
	pthread_t		thread;
	pthread_mutex_t	mutex_fork;
	t_eat			eat;
	int				victory;
	int				live;
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
int	check_philo(t_philo *lst, t_data *data);
int		check_victory(t_philo *lst);

/*act_philo.c*/
long	get_time(void);
void	print_mutx(int philo, long tps, t_data *data, char *str);
void	ft_sleep(int t_ms, t_data *data, long start);
void	wait_philo(t_philo *lst, t_data *data);
void	take_fork(t_philo *lst, t_data *data);

#endif
