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

int	on_destroy()
{
	print_output("window closed");
	return (0);
}

int	on_key(int key, t_mlxptr *mlx, t_map *map)
{
	static int	moves = 0;
	(void)mlx;

	if (key == KEY_ESC)
		on_destroy();
	else if ((key == KEY_UP || key == KEY_W) && ++moves)
		move(mlx, map, 1);
	else if ((key == KEY_LEFT || key == KEY_A) && ++moves)
		move(mlx, map, 2);
	else if ((key == KEY_DOWN || key == KEY_S) && ++moves)
		move(mlx, map, 3);
	else if ((key == KEY_RIGHT || key == KEY_D) && ++moves)
		move(mlx, map, 4);
	ft_printf("%i moves (%i)\n", moves, key);
	return (0);
}
