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

void	print_map(t_mlxptr mlx)
{
	t_count	c;
	char	**map;

	map = mlx.map.map;
	c.i = 0;
	while (map[c.i])
	{
		ft_printf("%i: %s", c.i, map[c.i]);
		c.i++;
	}
	ft_printf("\n");
}

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
	printf("--%i %i\n", mlx.map.player.c, mlx.map.player.r);
	start_game(&mlx);
	return (0);
}
