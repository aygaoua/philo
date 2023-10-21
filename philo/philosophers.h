/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:28:27 by azgaoua           #+#    #+#             */
/*   Updated: 2023/10/21 21:13:41 by azgaoua          ###   ########.fr       */
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
	pthread_mutex_t			mtx_vars1;
	pthread_mutex_t			mtx_vars2;
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
	bool					died;
	t_args					*args;
	struct s_philos			*next;
}							t_philos;

//-----------------------------MANDATORY_PARSSING--------------------------//
int					ft_error(int argc, char **argv);
int					ft_isdigit(char c);
int					ft_nbr_arg(char **av);
char				*ft_strchr(const char *s, int c);
char				**freeme(char **s, size_t i);
char				**ft_split(char const *s, char c);
char				*ft_strjoin(char *s1, char const *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
long				ft_atoi(const char *str);
long				ft_max(char **av);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
size_t				ft_strlen(const char *str);
size_t				lignes(const char *s, char c);

//------------------------------MANDATORY---------------------------------//
void				ft_philo(t_philos **group, t_args *args);
void				ft_lstadd_back(t_philos **lst, t_philos *new);
void				*ft_routine(void *lst);
void				ft_eat(t_philos *group);
void				ft_sleep(t_philos *group);
void				ft_print(t_philos *group, char *s);
void				ft_print_exit(t_philos *group);
void				ft_die_check(t_philos *group);
void				ft_init_args(t_args **args, int ac, char **av);
void				ft_check_and_unlock(t_philos **group);
int					ft_last_arg(t_philos *group);
t_philos			*ft_lstnew(long value, t_args *args);
unsigned long long	get_time_in_ms(void);

#endif