/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srvorkap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 10:29:16 by srvorkap          #+#    #+#             */
/*   Updated: 2019/11/08 23:09:06 by srvorkap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concatenation;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	concatenation = ft_strnew(len);
	if (concatenation == NULL)
		return (NULL);
	ft_strcpy(concatenation, s1);
	ft_strcat(concatenation, s2);
	return (concatenation);
}
