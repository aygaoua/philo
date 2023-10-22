/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:45:48 by azgaoua           #+#    #+#             */
/*   Updated: 2023/10/22 16:31:19 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_eat(t_philos *group)
{
	unsigned long long	deff;

	deff = get_time_in_ms();
	while (get_time_in_ms() - deff <= (unsigned long long )group->args->t_eat)
	{
		usleep(100);
	}
}

void	ft_sleep(t_philos *group)
{
	unsigned long long	deff;

	deff = get_time_in_ms();
	while (get_time_in_ms() - deff <= (unsigned long long )group->args->t_sleep)
	{
		usleep(100);
	}
}

void	ft_print(t_philos *group, char *s)
{
	pthread_mutex_lock(&group->args->mtx_print);
	printf("%lld %d %s\n", get_time_in_ms() - group->args->tita0, group->id, s);
	pthread_mutex_unlock(&group->args->mtx_print);
}

void	ft_check(t_philos **group)
{
	pthread_mutex_unlock(&(*group)->fork);
	pthread_mutex_unlock(&(*group)->next->fork);
	(*group)->philo_done++;
	if ((*group)->philo_done == (*group)->args->nbr_eats)
	{
		pthread_mutex_lock(&(*group)->args->mtx_flag);
		(*group)->args->flag++;
		pthread_mutex_unlock(&(*group)->args->mtx_flag);
	}
}

void	ft_update_last_eat(t_philos **group)
{
	pthread_mutex_lock(&(*group)->args->mtx_vars1);
	(*group)->last_eat = get_time_in_ms();
	pthread_mutex_unlock(&(*group)->args->mtx_vars1);
}
