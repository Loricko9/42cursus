/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:40:26 by lle-saul          #+#    #+#             */
/*   Updated: 2023/12/19 16:17:25 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	routine_1phil(t_data *data)
{
	free(data->pid);
	print_phil(get_time() - data->start, data->process, "take fork", data);
	ft_sleep(data->t_die, data, get_time());
	printf("%ld\t%d \033[31mdead\033[0m\n", get_time() - data->start,
		data->process);
	free_sem(data);
	exit(1);
}

void	routine(t_data *data)
{
	pthread_t	thread;

	free(data->pid);
	wait_philo(data);
	data->last_eat = get_time();
	if (pthread_create(&thread, NULL, check_philo, data) != 0)
		exit(1);
	pthread_detach(thread);
	while (data->state == 1)
	{
		take_fork(data);
		if (data->state != 1)
			break ;
		print_phil(get_time() - data->start, data->process, "sleep", data);
		ft_sleep(data->t_sleep, data, get_time());
		if (data->state != 1)
			break ;
		print_phil(get_time() - data->start, data->process, "thinking", data);
	}
	free_sem(data);
	if (data->state == 0)
		exit(0);
	else
		exit(1);
}

int	ft_fill_data(t_data *data, char **av)
{
	int	nb_victory;

	data->size = ft_atoi(av[1]);
	if (data->size <= 0)
		return (1);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (av[5] != NULL)
		nb_victory = ft_atoi(av[5]);
	else
		nb_victory = -1;
	data->victory = nb_victory;
	data->pid = malloc(sizeof(pid_t) * data->size);
	if (!data->pid)
		return (1);
	sem_unlink("/fork");
	sem_unlink("/write");
	sem_unlink("/finish");
	data->fork = sem_open("/fork", O_CREAT, 0644, data->size);
	data->write = sem_open("/write", O_CREAT, 0644, 1);
	data->finish = sem_open("/finish", O_CREAT, 0644, 1);
	data->state = 1;
	return (0);
}

int	ft_create(t_data *data)
{
	int	i;

	i = 0;
	data->start = get_time();
	if (data->size == 1)
	{
		data->pid[i] = fork();
		data->process = i + 1;
		if (data->pid[i] == 0)
			routine_1phil(data);
		else if (data->pid[i] == -1)
			return (kill_proc(data->pid, 0, i), 1);
		return (0);
	}
	while (i < data->size)
	{
		data->pid[i] = fork();
		data->process = i + 1;
		if (data->pid[i] == 0)
			routine(data);
		else if (data->pid[i] == -1)
			return (kill_proc(data->pid, 0, i), 1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
		return (printf("Error : missing arg\n"));
	if (check_char(av) == 1)
		return (printf("Error : invalid char\n"), 1);
	if (check_int(av) == 1)
		return (printf("Error : wrong nb\n"), 1);
	if (ft_fill_data(&data, av) == 1)
		return (printf("Error : malloc or create semaphore\n"), 1);
	sem_wait(data.finish);
	if (ft_create(&data) == 1)
		return (1);
	first_pid_end(data.pid, data.size, &data);
	free_sem(&data);
	free(data.pid);
}
