/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srvorkap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 00:52:54 by srvorkap          #+#    #+#             */
/*   Updated: 2019/11/17 00:53:31 by srvorkap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <fcntl.h>

#include "libft/libft.h"

# define BUFF_SIZE2 546
# define MAX_TETRIMINO 26
# define MAX_GRID 4

typedef struct  s_tetrimino
{
    char        letter;
    int         x[MAX_GRID];
    int         y[MAX_GRID];
}               t_tetrimino;

#endif