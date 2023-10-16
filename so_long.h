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
void	start_game(t_map *map);

// hooks
int		on_destroy(t_mlxptr *vars);
int		on_key(int key, t_mlxptr *vars);

// utils
t_cords	setcords(int r, int c);

#endif
