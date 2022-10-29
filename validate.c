/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srvorkap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:58:11 by srvorkap          #+#    #+#             */
/*   Updated: 2019/11/24 23:48:53 by srvorkap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    write_error_and_exit(void)
{
    ft_putstr("error\n");
    exit (0);
}

int		check_newline(char *line)
{
    if (line[0] == '\n')
        return (1);
    else
        return (0);
}

int     check_tetrinimo(char **tetrinimo)
{
	int     i;
	int     j;
	int     number_of_blocks;
	
	i = 0;
	j = 0;
	number_of_blocks = 0;
	while (j < MAX_GRID)
	{
		while (tetrinimo[j][i] != '\0')
		{
			if (tetrinimo[j][i] != '.' && tetrinimo[j][i] != '#')
				return (0);
			else if (tetrinimo[j][i] == '#')
				number_of_blocks++;
			i++;
		}
		if (i != MAX_GRID)
			return (0);
		i = 0;
		j++;
	}
	if (j != MAX_GRID)
		return (0);
	else if (number_of_blocks != MAX_GRID)
		return (0);
	return (1);
}

int		add_count(char **tetrinimo, int i, int j)
{
	int		count;

	count = 0;
	if (j < 3)
	{
		if (tetrinimo[j + 1][i] == '#')
			count++;
	}
	if (j > 0)
	{
		if (tetrinimo[j - 1][i] == '#')
			count++;
	}
	if (i < 3)
	{
		if (tetrinimo[j][i + 1] == '#')
			count++;
	}
	if (i > 0)
	{
		if (tetrinimo[j][i - 1] == '#')
			count++;
	}
	return (count);
}

int		check_adjacencies(char **tetrinimo)
{
	int		i;
	int		j;
	int		number_of_adjacencies;

	i = 0;
	j = 0;
	number_of_adjacencies = 0;
	while (j < MAX_GRID)
	{
		while (tetrinimo[j][i] != '\0')
		{
			if (tetrinimo[j][i] == '#')
				number_of_adjacencies += add_count(tetrinimo, i, j);
			i++;
		}
		i = 0;
		j++;
	}
	if (number_of_adjacencies == 6 || number_of_adjacencies == 8)
		return (1);
	else
		return (0);
}
