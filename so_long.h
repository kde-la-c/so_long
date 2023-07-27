/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:09:31 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/07/09 17:09:33 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdarg.h>
# include <mlx.h>
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include "libft/libft.h"
# include "macros.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_map
{
	char	**map;
	char	**tmpmap;
	t_cords	player;
	t_cords	exit;
	int		nbcollec;
	t_cords	dimensions;
}	t_map;

/* typedef struct	s_cell
{
	void	*content;
	t_cords	cords;
	t_cell	up;
	t_cell	right;
	t_cell	down;
	t_cell	left;
}				t_cell; */

// input handling
t_map	read_args(t_args args);

// map checking
void	check_map(t_map *map);

// output handling
int		print_error(char *err);

#endif
