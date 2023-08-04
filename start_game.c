/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 04:41:54 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/08/04 04:41:57 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_map *map)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;

	(void) map;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, map->dimensions.c * 32, map->dimensions.r * 32, "Hello world!");

	img.img = mlx_new_image(mlx, map->dimensions.c * 30, map->dimensions.r * 30);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	mlx_loop(mlx);
}
