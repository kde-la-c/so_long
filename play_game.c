/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:40:17 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/10/29 20:40:19 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	create_img(t_mlxptr mlx, char *path, int dim)
{
	t_img	ret;

	ret.path = path;
	ret.dim.c = dim;
	ret.dim.r = dim;
	ret.img = mlx_xpm_file_to_image(mlx.mlx, ret.path, &ret.dim.c, &ret.dim.r);
	if (!ret.img)
		perror_exit(ret.path);
	return (ret);
}

void	draw_sprite(t_mlxptr mlx, t_img img, t_cords tile)
{
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img,
		img.dim.c * tile.c, img.dim.r * tile.r);
}

void	draw_sprites(t_mlxptr mlx, t_img img, int ch)
{
	t_count	c;

	ft_bzero((void *)&c, sizeof(t_count));
	while (c.i < mlx.map.dimensions.r)
	{
		c.j = 0;
		while (c.j < mlx.map.dimensions.c)
		{
			if (mlx.map.map[c.i][c.j] == ch || !ch)
				draw_sprite(mlx, img, setcords((int)c.i, (int)c.j));
			c.j++;
		}
		c.i++;
	}
}

int	draw_map(t_mlxptr *mlx)
{
	mlx->i_floor = create_img(*mlx, "./sprites/floorx32.xpm", 32);
	mlx->i_wall = create_img(*mlx, "./sprites/wallx32.xpm", 32);
	mlx->i_character = create_img(*mlx, "./sprites/heisenbergx32.xpm", 32);
	mlx->i_collectible = create_img(*mlx, "./sprites/crystalx32.xpm", 32);
	mlx->i_open = create_img(*mlx, "./sprites/opendoorx32.xpm", 32);
	mlx->i_closed = create_img(*mlx, "./sprites/closedoorx32.xpm", 32);
	draw_sprites(*mlx, mlx->i_floor, 0);
	draw_sprites(*mlx, mlx->i_wall, CH_WALL);
	draw_sprites(*mlx, mlx->i_collectible, CH_COLLEC);
	if (mlx->map.nbcollec)
		draw_sprite(*mlx, mlx->i_closed, mlx->map.exit);
	else
		draw_sprite(*mlx, mlx->i_open, mlx->map.exit);
	draw_sprites(*mlx, mlx->i_character, CH_PLAYER);
	return (1);
}
