/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:08:42 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/07/09 17:08:45 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_image(void *mlx)
{
	t_data	*pt_img = NULL;

	pt_img->img = mlx_new_image(mlx, 720, 480);
	pt_img->addr = mlx_get_data_addr(pt_img->img, &pt_img->bits_per_pixel, &pt_img->line_length, &pt_img->endian);
}

int main()
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "UwU");
	mlx_loop(mlx);

	display_image(mlx);

	return 0;
}