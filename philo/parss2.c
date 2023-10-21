/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parss2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:25:52 by azgaoua           #+#    #+#             */
/*   Updated: 2023/10/18 20:01:51 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (0 == 0)
	{
		if (s[i] == (char)c)
			return ((char *) s + i);
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return (0);
}

size_t	lignes(const char *s, char c)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			i++;
			l++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (l + 1);
}

char	**freeme(char **s, size_t i)
{
	while (i >= 0 && s[i] != NULL)
	{
		free(s[i]);
		i--;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**sp;

	i = 0;
	if (!s)
		return (NULL);
	sp = malloc(8 * lignes(s, c));
	if (!sp)
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		j = 0;
		while (s[j] && s[j] != c)
			j++;
		if (j != 0)
			sp[i++] = ft_substr(s, 0, j);
		if (j != 0 && !sp[i - 1])
			return (freeme(sp, i - 1));
		s += j;
	}
	sp[i] = NULL;
	return (sp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	if (!s)
		return ((void *)0);
	if (start >= ft_strlen(s))
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	p = malloc(len + 1);
	if (!p)
		return (0);
	i = 0;
	while (i < len)
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}
