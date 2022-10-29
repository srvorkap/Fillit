/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srvorkap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 21:41:16 by srvorkap          #+#    #+#             */
/*   Updated: 2019/10/03 22:00:56 by srvorkap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*trim;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0' && ft_iswhitespace(s[i]))
		i++;
	j = ft_strlen(&s[i]) - 1;
	while (s[i] != '\0' && ft_iswhitespace(s[j + i]))
		j--;
	if (!(trim = ft_strnew(j + 1)))
		return (NULL);
	ft_strncpy(trim, (s + i), (j + 1));
	return (trim);
}
