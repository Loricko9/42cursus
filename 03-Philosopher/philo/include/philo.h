/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:56:24 by lle-saul          #+#    #+#             */
/*   Updated: 2023/12/14 19:12:48 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_victory
{
	pthread_mutex_t	mutex_vict;
	int				victory;
}	t_victory;

typedef struct s_state
{
	pthread_mutex_t	mutex_state;
	int				state;
}	t_state;

typedef struct s_eat
{
	pthread_mutex_t	mutex_eat;
	long			last_eat;
}	t_eat;

typedef struct s_data
{
	pthread_mutex_t	writing;
	long			start;
	int				size;
	int				t_die;
	int				t_sleep;
	int				t_eat;
	t_state			state;
}	t_data;

typedef struct s_philo
{
	int				nb_philo;
	pthread_t		thread;
	pthread_mutex_t	mutex_fork;
	t_eat			eat;
	t_victory		victory;
	int				live;
	t_data			*data;
	struct s_philo	*next;
}	t_philo;

/*main.c*/
void	*routine(void *src);
void	*routine_1phil(void *src);
void	finish_th(t_philo *lst);
int		ft_create(t_data *data, t_philo *lst);

/*utils.c*/
void	print_mutx(int philo, long tps, t_data *data, char *str);
long	ft_atoi(const char *nptr);
int		ft_fill_data(t_data *data, char **av, t_philo **lst);
int		create_lst(t_philo **lst, int nbr_philo, int nb_victory, t_data *data);
int		check_state(t_data *data);

/*lst_utils.c*/
t_philo	*ft_lstnew(int n_philo, int n_victory, t_data *ptr_data);
t_philo	*ft_lstlast(t_philo *lst);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
void	ft_free(t_philo *lst, t_data *data);
int		ft_lstsize(t_philo *lst);

/*check.c*/
void	check_death(t_philo *lst, t_data *data);
void	check_philo(t_philo *lst, t_data *data);
int		check_int(char **av);
int		check_char(char **av);
int		check_victory(t_philo *lst);

/*act_philo.c*/
void	take_fork2(t_philo *lst, t_philo *next, t_data *data);
void	ft_sleep(int t_ms, t_data *data, long start);
void	wait_philo(t_philo *lst, t_data *data);
void	take_fork(t_philo *lst, t_data *data);
long	get_time(void);

#endif
