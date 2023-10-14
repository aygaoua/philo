/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:27:53 by azgaoua           #+#    #+#             */
/*   Updated: 2023/10/08 17:14:44 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int ft_isdigit(char c)
{
	return(c >= '0' && c <= '9');
}

int	ft_error(int argc, char **argv)
{
	int	j;
	int	i;

	i = 1;
	if (argc < 2)
		exit(0);
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
	int		s;

	s = 1;
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
		if (retu * s > 2147483647)
			return (4294967296);
		else if (retu * s < -2147483648)
			return (4294967296);
		i++;
	}
	return ((int )(retu * s));
}

int	ft_errors(int ac, char **av)
{
	int	k;

	k = 1;
	while (av[k] != NULL && k < ac)
	{
		if (ft_empty_arg(av[k]) == 0)
			return (1);
		k++;
	}
	return (0);
}

int main (int ac, char **av)
{
	int		i;
	char	*string;
	char	**arrtwo;

	i = 0;
	if (ft_error(ac, av) == 0 || ft_errors(ac, av) == 1)
		return (write(2, "Error\n", 6), 1);
	string = ft_trance(ac, av);
	arrtwo = ft_split(string, ' ');
	free(string);
	string = NULL;
	if (ft_max(arrtwo) == 4294967296)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (ft_nbr_arg(arrtwo) == 5 || ft_nbr_arg(arrtwo) == 6)
	{
		while (arrtwo[i])
		{
			printf("%ld ", ft_atoi(arrtwo[i]));
			i++;
		}
		printf("\n");
	}
	else
		printf("the number of args is fauls !!\n");
	return (0);
}
