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

static void	edit_map(t_mlxptr *mlx, t_cords dest, t_cords player)
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
		&& dest.r == mlx->map.exit.r)
		output_exit("YOU WON!");
}

static void	draw_changes(t_mlxptr *mlx, t_cords dest, t_cords player)
{
	draw_sprite(*mlx, mlx->i_floor, player);
	draw_sprite(*mlx, mlx->i_floor, dest);
	if (!mlx->map.nbcollec)
		draw_sprite(*mlx, mlx->i_open, mlx->map.exit);
	else if ((dest.r == mlx->map.exit.r && dest.c == mlx->map.exit.c)
		|| (player.r == mlx->map.exit.r && player.c == mlx->map.exit.c))
		draw_sprite(*mlx, mlx->i_closed, mlx->map.exit);
	draw_sprite(*mlx, mlx->i_character, dest);
}

void	move(t_mlxptr *mlx, int direction)
{
	static int	nbmoves = 0;
	t_cords		dest;
	t_cords		pl;

	pl = mlx->map.player;
	if (direction == 1 && mlx->map.map[pl.r - 1][pl.c] != CH_WALL)
		dest = ft_setcords(pl.r - 1, pl.c);
	else if (direction == 2 && mlx->map.map[pl.r][pl.c - 1] != CH_WALL)
		dest = ft_setcords(pl.r, pl.c - 1);
	else if (direction == 3 && mlx->map.map[pl.r + 1][pl.c] != CH_WALL)
		dest = ft_setcords(pl.r + 1, pl.c);
	else if (direction == 4 && mlx->map.map[pl.r][pl.c + 1] != CH_WALL)
		dest = ft_setcords(pl.r, pl.c + 1);
	else
		return ;
	ft_printf("%i moves\n", ++nbmoves);
	edit_map(mlx, dest, pl);
	draw_changes(mlx, dest, pl);
}
