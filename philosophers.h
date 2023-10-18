/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:28:27 by azgaoua           #+#    #+#             */
/*   Updated: 2023/10/18 20:34:57 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

//-----------------------------MANDATORY_PARSSING--------------------------//
int				ft_error(int argc, char **argv);
int				ft_isdigit(char c);
long			ft_atoi(const char *str);
int				ft_errors(int ac, char **av);
char			*ft_trance(int ac, char **av);
long			ft_max(char **av);
char			*ft_strchr(const char *s, int c);
size_t			lignes(const char *s, char c);
char			**freeme(char **s, size_t i);
char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_empty_arg(char *c);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
char			*ft_strjoin(char *s1, char const *s2);
size_t			ft_strlen(const char *str);
int				ft_nbr_arg(char **av);
//------------------------------MANDATORY---------------------------------//
void ft_philo();


#endif