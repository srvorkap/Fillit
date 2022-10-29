/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srvorkap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 00:00:02 by srvorkap          #+#    #+#             */
/*   Updated: 2019/10/10 21:00:59 by srvorkap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_of_strings(char const *str, char c)
{
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			nb++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (nb);
}

static char	**memgiver(char const *str, char c)
{
	char	**res;
	int		letters;
	int		i;
	int		j;

	if (!(res = (char **)malloc(sizeof(char*) * (nb_of_strings(str, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		letters = 0;
		while (str[i] != '\0' && str[i] == c)
			i++;
		while (str[i] != '\0' && str[i] != c)
		{
			letters++;
			i++;
		}
		if (letters > 0)
			if (!(res[j++] = (char *)malloc(sizeof(char) * letters + 1)))
				return (NULL);
	}
	res[j] = 0;
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		len;
	int		i;
	int		j;
	int		pos;

	if (s == NULL)
		return (NULL);
	tab = memgiver(s, c);
	len = nb_of_strings(s, c);
	if (tab == NULL)
		return (NULL);
	i = 0;
	pos = 0;
	while (pos < len)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		j = 0;
		while (s[i] != '\0' && s[i] != c)
			tab[pos][j++] = s[i++];
		tab[pos][j] = '\0';
		pos++;
	}
	return (tab);
}
