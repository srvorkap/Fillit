/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srvorkap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 19:53:28 by srvorkap          #+#    #+#             */
/*   Updated: 2019/11/23 01:21:01 by srvorkap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>


int     check_tetrinimo(char **tetrinimo);

int     main(int ac, char **av)
{
    int     fd;
    char    buf[20];
    char    **tetrinimo;
    int     x;

    if (ac != 2)
        write(1, "Put only one file\n", 18);
    fd = open (av[1], O_RDONLY);
    read(fd, buf, 19);
    buf[19] = '\0';
    tetrinimo = ft_strsplit(buf, '\n');
    x = check_tetrinimo(tetrinimo);
    printf("%d\n", x);
    return (0);
}
