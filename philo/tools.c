/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:09:51 by azgaoua           #+#    #+#             */
/*   Updated: 2023/10/22 16:10:30 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philos	*ft_lstnew(long value, t_args *args)
{
	t_philos	*new;

	new = malloc(sizeof(t_philos));
	if (!new)
		return (0);
	new->id = value;
	new->args = args;
	new->philo_done = 0;
	new->last_eat = args->tita0;
	pthread_mutex_init(&new->fork, NULL);
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_philos **lst, t_philos *new)
{
	t_philos	*last;

	if (!lst)
		return ;
	last = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (last -> next != NULL)
			last = last -> next;
		last -> next = new;
	}
}

void	*ft_routine(void *lst)
{
	t_philos	*group;

	group = (t_philos *)lst;
	if (group->id % 2 == 0)
		usleep(group->args->t_eat * 1000);
	while (0 == 0)
	{
		pthread_mutex_lock(&group->fork);
		ft_print(group, "has taken a fork");
		pthread_mutex_lock(&group->next->fork);
		ft_print(group, "has taken a fork");
		ft_print(group, "is eating");
		ft_update_last_eat(&group);
		ft_eat(group);
		pthread_mutex_lock(&group->args->mtx_vars2);
		ft_check(&group);
		pthread_mutex_unlock(&group->args->mtx_vars2);
		ft_print(group, "is sleeping");
		ft_sleep(group);
		ft_print(group, "is thinking");
		usleep(100);
	}
	return (NULL);
}

unsigned long long	get_time_in_ms(void)
{
	struct timeval		current_time;
	unsigned long long	elapsed_time;

	gettimeofday(&current_time, NULL);
	elapsed_time = (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
	return (elapsed_time);
}

void	ft_init_args(t_args **args, int ac, char **av)
{
	(*args)->nbr_of_philos = (int )ft_atoi(av[0]);
	(*args)->t_die = (int )ft_atoi(av[1]);
	(*args)->t_eat = (int )ft_atoi(av[2]);
	(*args)->t_sleep = (int )ft_atoi(av[3]);
	if (ac - 1 == 5)
		(*args)->nbr_eats = (int )ft_atoi(av[4]);
	else
		(*args)->nbr_eats = -1;
	(*args)->flag = 0;
	(*args)->tita0 = get_time_in_ms();
	pthread_mutex_init(&(*args)->mtx_print, NULL);
	pthread_mutex_init(&(*args)->mtx_vars1, NULL);
	pthread_mutex_init(&(*args)->mtx_vars2, NULL);
	pthread_mutex_init(&(*args)->mtx_flag, NULL);
}
