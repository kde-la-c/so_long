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

t_cords	setcords(int r, int c)
{
	t_cords	ret;

	ret.r = r;
	ret.c = c;
	return (ret);
}

int	main(int argc, char **argv)
{
	t_mlxptr	mlx;
	t_args		args;

	args.argc = argc;
	args.argv = argv;
	mlx.map = read_args(args);
	check_map(&mlx.map);
	start_game(&mlx);
	return (0);
}
