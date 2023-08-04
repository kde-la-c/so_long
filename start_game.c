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
	void	*img;
	void	*mlx;
	void	*mlx_win;

	(void) map;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img = mlx_new_image(mlx, 1920, 1080);
	mlx_loop(mlx);
	// mlx_get_data_addr()
}