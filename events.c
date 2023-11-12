/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 03:02:40 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/08/05 03:02:44 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(void)
{
	print_output("window closed");
	return (0);
}

int	on_key(int key, void *arg)
{
	t_mlxptr	mlx;
	static int	moves = 0;

	mlx = *(t_mlxptr *)arg;
	printf("%i %i\n", mlx.i_floor.dim.r, mlx.i_floor.dim.c);
	if (key == KEY_ESC)
		on_destroy();
	else if (!mlx.map.nbcollec)
		draw_sprite(mlx, mlx.i_open, mlx.map.exit);
	else if ((key == KEY_UP || key == KEY_W) && ++moves)
		move(mlx, 1);
	else if ((key == KEY_LEFT || key == KEY_A) && ++moves)
		move(mlx, 2);
	else if ((key == KEY_DOWN || key == KEY_S) && ++moves)
		move(mlx, 3);
	else if ((key == KEY_RIGHT || key == KEY_D) && ++moves)
		move(mlx, 4);
	ft_printf("%i moves (%i)\n", moves, key);
	return (0);
}
