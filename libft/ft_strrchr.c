/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srvorkap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 14:41:33 by srvorkap          #+#    #+#             */
/*   Updated: 2019/10/06 23:10:41 by srvorkap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurrence;
	int		i;

	last_occurrence = (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			last_occurrence = (char*)&s[i];
		i++;
	}
	if (c == '\0')
		return ((char*)&s[i]);
	return (last_occurrence);
}
