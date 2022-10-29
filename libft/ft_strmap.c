/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srvorkap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 07:26:20 by srvorkap          #+#    #+#             */
/*   Updated: 2019/10/03 08:42:39 by srvorkap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*map;

	i = 0;
	if (!s || !(map = ft_memalloc(ft_strlen(s) + 1)))
		return (NULL);
	while (((char *)s)[i] != '\0')
	{
		map[i] = f(((char *)s)[i]);
		i++;
	}
	return (map);
}
