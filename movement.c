/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:43:09 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/11/05 23:43:12 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_char(t_map map, char ch, t_cords *ret)
{
	t_count	c;

	ft_bzero((void *)&c, sizeof(t_count));
	while (map.map[c.i])
	{
		c.j = 0;
		while (map.map[c.i][c.j])
		{
			if (map.map[c.i][c.j] == ch)
			{
				ret->r = c.i;
				ret->c = c.j;
				break ;
			}
			c.j++;
		}
		c.i++;
	}
	if (!map.map[c.i])
		ret = NULL;
}

void	edit_map(t_mlxptr *mlx, t_cords dest, t_cords player)
{
	if (mlx->map.map[dest.r][dest.c] == CH_COLLEC)
	{
		mlx->map.nbcollec -= 1;
		mlx->map.map[dest.r][dest.c] = CH_SPACE;
	}
	if (player.c == mlx->map.exit.c && player.r == mlx->map.exit.r)
	{
		mlx->map.map[player.r][player.c] = CH_EXIT;
		mlx->map.map[dest.r][dest.c] = CH_PLAYER;
	}
	else
	{
		mlx->map.map[player.r][player.c] = CH_SPACE;
		mlx->map.map[dest.r][dest.c] = CH_PLAYER;
	}
	mlx->map.player = dest;
	if (!mlx->map.nbcollec && dest.c == mlx->map.exit.c
		&& player.r == mlx->map.exit.r)
		on_destroy("YOU WON!");
}

void	move(t_mlxptr *mlx, int direction)
{
	t_cords	dest;
	t_cords	pl;

	pl = mlx->map.player;
	// printf("map.pl :%i %i\n", mlx->map.player.r, mlx->map.player.c);
	if (direction == 1 && mlx->map.map[pl.r - 1][pl.c] != CH_WALL)
		dest = setcords(pl.r - 1, pl.c);
	else if (direction == 2 && mlx->map.map[pl.r][pl.c - 1] != CH_WALL)
		dest = setcords(pl.r, pl.c - 1);
	else if (direction == 3 && mlx->map.map[pl.r + 1][pl.c] != CH_WALL)
		dest = setcords(pl.r + 1, pl.c);
	else if (direction == 4 && mlx->map.map[pl.r][pl.c + 1] != CH_WALL)
		dest = setcords(pl.r, pl.c + 1);
	else
		return ;
	edit_map(mlx, dest, pl);
	draw_map(mlx);
}
