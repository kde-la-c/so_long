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
# include "structs.h"

// input handling
t_map	read_args(t_args args);

// map checking
void	check_map(t_map *map);

// output handling
int		print_error(char *err);
int		perror_exit(char *err);
int		print_output(char *msg);

// mlx
void	start_game(t_mlxptr	mlx);

// hooks
int		on_destroy(void);
int		on_key(int key, void *mlx);

// utils
t_cords	setcords(int r, int c);

int		draw_map(t_mlxptr mlx);

void	draw_sprite(t_mlxptr mlx, t_img img, t_cords tile);
void	move(t_mlxptr mlx, int direction);

#endif
