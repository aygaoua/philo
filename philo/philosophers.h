/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:28:27 by azgaoua           #+#    #+#             */
/*   Updated: 2023/10/23 00:05:02 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <libc.h>
# include <stdbool.h>
# include <pthread.h>

//------------------------------MANDATORY_STRUCT---------------------------//
typedef struct s_args
{
	int						nbr_of_philos;
	int						t_die;
	int						t_eat;
	int						t_sleep;
	int						nbr_eats;
	int						flag;
	pthread_mutex_t			mtx_print;
	pthread_mutex_t			mtx_last_eat;
	pthread_mutex_t			mtx_philo_done;
	pthread_mutex_t			mtx_flag;
	unsigned long long		tita0;
}							t_args;

typedef struct s_philos
{
	int						id;
	int						philo_done;
	unsigned long long		last_eat;
	pthread_t				thread;
	pthread_mutex_t			fork;
	t_args					*args;
	struct s_philos			*next;
}							t_philos;

//-----------------------------MANDATORY_PARSSING--------------------------//
int					ft_error(int argc, char **argv);
int					ft_isdigit(char c);
long				ft_atoi(const char *str);
long				ft_max(char **av);

//------------------------------MANDATORY---------------------------------//
void				ft_philo(t_philos **group, t_args *args);
void				ft_lstadd_back(t_philos **lst, t_philos *new);
void				ft_eat(t_philos *group);
void				ft_sleep(t_philos *group);
void				*ft_routine(void *lst);
void				ft_print(t_philos *group, char *s);
void				ft_print_exit(t_philos *group);
void				ft_die_check(t_philos *group);
void				ft_init_args(t_args **args, int ac, char **av);
void				ft_check(t_philos **group);
void				ft_update_last_eat(t_philos **group);
int					ft_last_arg(t_philos *group);
t_philos			*ft_lstnew(long value, t_args *args);
unsigned long long	get_time_in_ms(void);

#endif