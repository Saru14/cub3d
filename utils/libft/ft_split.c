/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvanher <thvanher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 10:50:01 by thvanher          #+#    #+#             */
/*   Updated: 2020/09/12 19:18:49 by jbodson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_mots(char *str, char c)
{
	int i;
	int mots;

	i = 0;
	mots = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			mots++;
		while (str[i] && (!(str[i] == c)))
			i++;
	}
	return (mots);
}

static int	nb_char(char *str, int i, char c)
{
	int res;

	res = 0;
	while (str[i] && !(str[i] == c))
	{
		res++;
		i++;
	}
	return (res);
}

static char	*copie_mots(char *str, int *i, int nb_car, char c)
{
	char	*res;
	int		j;

	j = 0;
	res = 0;
	if (!(res = (char *)malloc(sizeof(char) * (nb_car + 1))))
		return (0);
	while (str[*i] && !(str[*i] == c))
	{
		res[j] = str[*i];
		(*i)++;
		j++;
	}
	res[nb_car] = '\0';
	return (res);
}

void		free_all(char **res, int j)
{
	while (j >= 0)
	{
		free(res[j]);
		j--;
	}
	free(res);
}

char		**ft_split(char const *str, char c)
{
	int		i;
	int		mots;
	int		nb_car;
	char	**res;
	int		j;

	j = 0;
	if (!str)
		return (0);
	mots = nb_mots((char *)str, c);
	if (!(res = (char **)malloc(sizeof(char *) * (mots + 1))))
		return (0);
	i = 0;
	while (j < mots)
	{
		while (str[i] == c)
			i++;
		nb_car = nb_char((char *)str, i, c);
		if (!(res[j] = copie_mots((char *)str, &i, nb_car, c)))
			free_all(res, j - 1);
		j++;
	}
	res[mots] = 0;
	return (res);
}
