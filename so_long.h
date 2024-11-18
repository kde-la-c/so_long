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
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "macros.h"
# include "structs.h"

// parsing
t_map	read_args(t_args args);

// map checking
void	check_map(t_map *map);

// output handling
int		error_exit(char *err);
int		perror_exit(char *err);
int		output_exit(char *msg);

// mlx
void	start_game(t_mlxptr	*mlx);
int		draw_map(t_mlxptr *mlx);
void	draw_sprite(t_mlxptr mlx, t_img img, t_cords tile);

// hooks
int		on_destroy(void);
int		on_key(int key, t_mlxptr *mlx);

// mechanics
void	move(t_mlxptr *mlx, int direction);

#endif
