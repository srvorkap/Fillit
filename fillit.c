/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srvorkap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 22:43:51 by srvorkap          #+#    #+#             */
/*   Updated: 2019/11/27 22:43:55 by srvorkap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     get_number_of_tetrimino_in_file(char *file_name)
{
    int     fd;
    int     number_of_char;
    char    buf[BUFF_SIZE2 + 1];
    int     number_of_tetrimino;

    fd = open(file_name, O_RDONLY);
    number_of_char = read(fd, buf, BUFF_SIZE2);
    close(fd);
    if (number_of_char == 0)
        return (1);
    else
        number_of_tetrimino = (number_of_char / 21) + 1;
    return (number_of_tetrimino);
}

int     main(int ac, char **av)
{
    int     number_of_tetrimino;


    if (ac != 2)
        write(1, "die\n", 4);
    else
    {
        number_of_tetrimino = get_number_of_tetrimino_in_file(av[1]);
        printf("%d", number_of_tetrimino);
    }
    return (0);
}