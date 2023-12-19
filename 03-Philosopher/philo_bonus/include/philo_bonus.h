/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:44:49 by lle-saul          #+#    #+#             */
/*   Updated: 2023/12/19 15:54:50 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <pthread.h>
# include <signal.h>
# include <fcntl.h>

typedef struct s_data
{
	sem_t	*fork;
	sem_t	*write;
	sem_t	*finish;
	int		finish_state;
	pid_t	*pid;
	long	start;
	long	last_eat;
	int		victory;
	int		process;
	int		size;
	int		t_die;
	int		t_sleep;
	int		t_eat;
	int		state;
}	t_data;

/*main.c*/
void	routine_1phil(t_data *data);
void	routine(t_data *data);
int		ft_fill_data(t_data *data, char **av);
int		ft_create(t_data *data);

/*act_philo.c*/
void	print_phil(long time, int philo, char *str, t_data *data);
long	get_time(void);
void	ft_sleep(int t_ms, t_data *data, long start);
void	wait_philo(t_data *data);
void	take_fork(t_data *data);

/*check.c*/
void	*check_philo(void *src);
int		check_int(char **av);
int		check_char(char **av);

/*process.c*/
int		first_pid_end(pid_t *pid_tab, int nb_proc, t_data *data);
void	kill_proc(pid_t *pid, pid_t pid_dead, int nb_proc);
long	ft_atoi(const char *nptr);
void	free_sem(t_data *data);

#endif
