/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:26:10 by lle-saul          #+#    #+#             */
/*   Updated: 2023/12/18 20:11:47 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	first_pid_end(pid_t *pid_tab, int nb_proc)
{
	pid_t	pid;
	int		status;

	while (1)
	{
		pid = waitpid(-1, &status, WNOHANG);
		if (pid == 0)
			usleep(20);
		else if (pid > 0)
		{
			if (WEXITSTATUS(status) == 1)
				return (kill_proc(pid_tab, pid, nb_proc), 1);
			else
				continue ;
		}
		else
			break ;
	}
	return (0);
}

void	kill_proc(pid_t *pid, pid_t pid_dead, int nb_proc)
{
	int	i;

	i = 0;
	while (i < nb_proc)
	{
		if (pid[i] != pid_dead)
			kill(pid[i], SIGTERM);
		i++;
	}
}

long	ft_atoi(const char *nptr)
{
	int		i;
	long	nb;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + nptr[i] - 48;
		i++;
	}
	return (nb * sign);
}

void	free_sem(t_data *data)
{
	sem_close(data->fork);
	sem_close(data->write);
	sem_unlink("/fork");
	sem_unlink("/write");
}
