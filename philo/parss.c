/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:24:28 by azgaoua           #+#    #+#             */
/*   Updated: 2023/10/21 21:54:38 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	ft_max(char **av)
{
	int	j;

	j = 0;
	while (av[j])
	{
		if (ft_atoi(av[j]) == 4294967296)
			return (4294967296);
		j++;
	}
	return (1);
}

void	ft_philo(t_philos **group, t_args *args)
{
	int			i;
	t_philos	*copy;

	i = 1;
	while (i <= args->nbr_of_philos)
	{
		ft_lstadd_back(&(*group), ft_lstnew((long )i, args));
		i++;
	}
	copy = *group;
	while (copy->next)
	{
		pthread_create(&copy->thread, NULL, ft_routine, (void *)copy);
		pthread_detach(copy->thread);
		copy = copy->next;
	}
	copy->next = (*group);
	pthread_create(&copy->thread, NULL, ft_routine, (void *)copy);
	pthread_detach(copy->thread);
	ft_die_check(*group);
}

void	ft_die_check(t_philos *group)
{
	while (group)
	{
		pthread_mutex_lock(&group->args->mtx_vars1);
		if (get_time_in_ms() - group->last_eat > \
			(unsigned long long )group->args->t_die)
		{
			ft_print_exit(group);
			break ;
		}
		pthread_mutex_unlock(&group->args->mtx_vars1);
		pthread_mutex_lock(&group->args->mtx_vars2);
		if (ft_last_arg(group))
			break ;
		pthread_mutex_unlock(&group->args->mtx_vars2);
		group = group->next;
		usleep(100);
	}
	pthread_mutex_destroy(&group->args->mtx_vars1);
	pthread_mutex_destroy(&group->args->mtx_print);
	pthread_mutex_destroy(&group->args->mtx_flag);
	while (group->args->nbr_of_philos-- > 0)
	{
		pthread_mutex_destroy(&group->fork);
		group = group->next;
	}
}

void	ft_print_exit(t_philos *group)
{
	pthread_mutex_lock(&group->args->mtx_print);
	printf("%lld %d died\n", get_time_in_ms() - group->args->tita0, group->id);
}

int	ft_last_arg(t_philos *group)
{
	if (group->args->nbr_eats != -1 || group->args->nbr_eats == 0)
	{
		pthread_mutex_lock(&group->args->mtx_flag);
		if (group->args->flag == group->args->nbr_of_philos)
		{
			pthread_mutex_lock(&group->args->mtx_print);
			return (1);
		}
		else if (group->args->nbr_eats == 0)
		{
			pthread_mutex_lock(&group->args->mtx_print);
			return (1);
		}
		pthread_mutex_unlock(&group->args->mtx_flag);
	}
	return (0);
}
