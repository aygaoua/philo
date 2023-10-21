/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:45:48 by azgaoua           #+#    #+#             */
/*   Updated: 2023/10/21 21:35:01 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_eat(t_philos *group)
{
	usleep((unsigned long long )group->args->t_eat * 994);
}

void	ft_sleep(t_philos *group)
{
	usleep((unsigned long long )group->args->t_sleep * 994);
}

void	ft_print(t_philos *group, char *s)
{
	pthread_mutex_lock(&group->args->mtx_print);
	printf("%lld %d %s\n", get_time_in_ms() - group->args->tita0, group->id, s);
	pthread_mutex_unlock(&group->args->mtx_print);
}

void	ft_check_and_unlock(t_philos **group)
{
	(*group)->philo_done++;
	if ((*group)->philo_done == (*group)->args->nbr_eats)
	{
		pthread_mutex_lock(&(*group)->args->mtx_flag);
		(*group)->args->flag++;
		pthread_mutex_unlock(&(*group)->args->mtx_flag);
	}
	pthread_mutex_unlock(&(*group)->fork);
	pthread_mutex_unlock(&(*group)->next->fork);
}
