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

void	create_mlx(t_map *map, t_mlxptr *ret, t_count *c)
{
	c->i = map->dimensions.c * 32;
	c->j = map->dimensions.r * 32;
	ret->mlx = mlx_init();
	ret->win = mlx_new_window(ret->mlx, c->i, c->j, "so_long");
}

void	start_game(t_map *map)
{
	t_count		c;
	t_img		img;
	t_mlxptr	mlx;

	create_mlx(map, &mlx, &c);
	img.path = "./sprites/heisenbergx64.xpm";
	img.dim.c = 64;
	img.dim.r = 64;
	img.img = mlx_xpm_file_to_image(mlx.mlx, img.path, &img.dim.c, &img.dim.r);
	if (!img.img)
		perror_exit(img.path);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_hook(mlx.win, 17, 1L << 5, on_destroy, &mlx);
	mlx_key_hook(mlx.win, on_key, &mlx);
	mlx_loop(mlx.mlx);
}
