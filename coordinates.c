/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srvorkap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 00:25:05 by srvorkap          #+#    #+#             */
/*   Updated: 2019/11/30 00:25:08 by srvorkap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char    **get_next_tetrimino(const int fd)
{
    char    **grid;
    char    *line;
    int     i;

    i = 0;
    if (!(grid = (char **)malloc(sizeof(char *) * MAX_GRID)))
        return (NULL);
    while (i < MAX_GRID)
    {
        if (get_next_line(fd, &line) == 1)
            grid[i++] = strdup(line);
        else
            write_error_and_exit();
        free(line);
    }
    if (get_next_line(fd, &line) == 1)
        if(!check_newline(line))
            write_error_and_exit();
    if (check_tetrimino(grid) == 0)
        write_error_and_exit;
    if (check_adjacencies(grid) == 0)
        write_error_and_exit;
    return (grid);
}

t_tetrimino     get_tetrimino_structure(char **grid)
{
    t_tetrimino     tetrimino_structure;
    int     i;
    int     j;
    int     k;

    i = 0;
    j = 0;
    k = 0;
    while (j < MAX_GRID)
    {
        while (grid[j][i] != '\0')
        {
            if (grid[j][i] == '#')
            {
                tetrimino_structure.x[k] = i;
                tetrimino_structure.y[k] = j;
                k++;
            }
            i++;
        }
        i = 0;
        j++;
    }
    return (tetrimino_structure);
}

t_tetrimino     reset_tetrimino_structure(t_tetrimino tetrimino_structure)
{
    t_tetrimino     changed;
    int             i;
    int             x_temp;
    int             y_temp;

    i = 1;
    x_temp = tetrimino_structure.x[0];
    y_temp = tetrimino_structure.y[0];
    while (i < MAX_GRID)
    {
        changed.x[i] = tetrimino_structure.x[i] - x_temp;
        changed.y[i] = tetrimino_structure.y[i] - y_temp;
        i++;
    }
    changed.x[0] = 0;
    changed.y[0] = 0;
    return (changed);
}