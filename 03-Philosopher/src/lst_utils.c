/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:15:43 by lle-saul          #+#    #+#             */
/*   Updated: 2023/12/03 14:15:43 by lle-saul         ###   ########.fr       */
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
	list->fork.fork = 1;
	pthread_mutex_init(&list->fork.mutex_fork, NULL);
	list->victory.nb_victory = n_victory;
	pthread_mutex_init(&list->victory.mutex_victory, NULL);
	list->death.death = ptr_data->t_die;
	list->death.last_act.tv_sec = 0;
	list->death.last_act.tv_usec = 0;
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
	int	i;
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

void	ft_lst_free(t_philo *lst)
{
	int		size;
	t_philo	*temp;

	size = ft_lstsize(lst);
	while (size > 0)
	{
		temp = lst->next;
		free(lst);
		lst = NULL;
		lst = temp;
		size--;
	}
}
