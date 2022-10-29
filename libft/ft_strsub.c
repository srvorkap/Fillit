/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srvorkap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 09:05:40 by srvorkap          #+#    #+#             */
/*   Updated: 2019/10/05 19:10:53 by srvorkap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	else if (!(sub = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	else
	{
		sub[len] = '\0';
		while (len > 0)
		{
			sub[len - 1] = s[start + len - 1];
			len--;
		}
		return (sub);
	}
}
