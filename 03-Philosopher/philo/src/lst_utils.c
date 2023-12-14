/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:15:43 by lle-saul          #+#    #+#             */
/*   Updated: 2023/12/14 19:13:18 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_lstnew(int n_philo, int n_victory, t_data *ptr_data)
{
	t_philo	*list;

	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->nb_philo = n_philo;
	pthread_mutex_init(&list->mutex_fork, NULL);
	pthread_mutex_init(&list->eat.mutex_eat, NULL);
	list->eat.last_eat = 0;
	pthread_mutex_init(&list->victory.mutex_vict, NULL);
	list->victory.victory = n_victory;
	list->live = 0;
	list->data = ptr_data;
	list->next = NULL;
	return (list);
}

void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*last;

	if (new)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

t_philo	*ft_lstlast(t_philo *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
			lst = lst->next;
		return (lst);
	}
	return (0);
}

int	ft_lstsize(t_philo *lst)
{
	int		i;
	t_philo	*first;

	i = 1;
	first = lst;
	if (lst->next == NULL)
		return (1);
	lst = lst->next;
	while (first != lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	ft_free(t_philo *lst, t_data *data)
{
	int		size;
	t_philo	*temp;

	size = ft_lstsize(lst);
	while (size > 0)
	{
		temp = lst->next;
		pthread_mutex_destroy(&lst->eat.mutex_eat);
		pthread_mutex_destroy(&lst->mutex_fork);
		pthread_mutex_destroy(&lst->victory.mutex_vict);
		free(lst);
		lst = NULL;
		lst = temp;
		size--;
	}
	if (data)
		pthread_mutex_destroy(&data->state.mutex_state);
}
