/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:44:49 by lle-saul          #+#    #+#             */
/*   Updated: 2023/12/15 15:44:49 by lle-saul         ###   ########.fr       */
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

typedef struct s_data
{
	pid_t	*pid;
	long	start;
	long	last_act_death;
	int		process;
	int		size;
	int		t_die;
	int		t_sleep;
	int		t_eat;
	int		state;
}	t_data;

/*act_philo.c*/
long	get_time(void);
void	ft_sleep(int t_ms, t_data *data, long start);
void	wait_philo(t_philo *lst, t_data *data);
void	take_fork(t_philo *lst, t_data *data);
void	take_fork2(t_philo *lst, t_philo *next, t_data *data);

/*check.c*/
void	*check_death(void *src);
void	check_philo(t_philo *lst, t_data *data);
int		check_int(char **av);
int		check_char(char **av);
int		check_victory(t_philo *lst);

/*process.c*/
pid_t	first_pid_end();
void	kill_proc(pid_t *pid, pid_t pid_dead, int nb_proc);

#endif

