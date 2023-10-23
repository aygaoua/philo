/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:27:53 by azgaoua           #+#    #+#             */
/*   Updated: 2023/10/22 22:15:52 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_error(int argc, char **argv)
{
	int	j;
	int	i;

	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 1 || argv[i][j] == ' ')
				j++;
			else if ((argv[i][j] == '-' || argv[i][j] == '+') && (j > 0 \
						&& argv[i][j - 1] != ' '))
				return (0);
			else if ((argv[i][j] == '-' || argv[i][j] == '+') \
					&& ((argv[i][j + 1] && ft_isdigit(argv[i][j + 1]) == 1)))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	retu;

	i = 0;
	retu = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	if (ft_isdigit(str[i]) == 0)
		return (4294967296);
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		retu = (retu * 10) + str[i] - 48;
		if (retu > 2147483647)
			return (4294967296);
		else if (retu < -2147483648)
			return (4294967296);
		i++;
	}
	return (retu);
}

int	main(int ac, char **av)
{
	t_philos	*group;
	t_args		*args;

	args = NULL;
	group = NULL;
	if (ac - 1 == 4 || ac - 1 == 5)
	{
		if (ft_error(ac, av) == 0 || ft_max(++av) == 4294967296)
			return (write(2, "Error\n", 6), 1);
		args = (t_args *)malloc(sizeof(t_args));
		if (!args)
			return (0);
		ft_init_args(&args, ac, av);
		if (args->nbr_of_philos == 0 || args->nbr_of_philos >= 250)
			return (printf("the number of philos is not supported!!\n"), \
					free(args), 0);
		ft_philo(&group, args);
	}
	else
		return (printf("please enter 4 or 5 args!!\n"), 0);
	return (0);
}
