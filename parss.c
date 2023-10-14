/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:24:28 by azgaoua           #+#    #+#             */
/*   Updated: 2023/10/08 16:48:22 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

char	*ft_trance(int ac, char **av)
{
	int		i;
	char	*res;

	res = malloc(1);
	i = 1;
	while (i < ac)
	{
		res = ft_strjoin(res, av[i]);
		i++;
		if (i < ac)
			res = ft_strjoin(res, " ");
	}
	return (res);
}

int	ft_empty_arg(char *c)
{
	int	k;
	int	j;

	j = 0;
	k = 0;
	while (c[j] != '\0')
	{
		if (ft_isdigit(c[j]))
			k++;
		j++;
	}
	return (k);
}

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
