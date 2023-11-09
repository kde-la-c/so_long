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
	t_args	args;
	t_map	map;

	args.argc = argc;
	args.argv = argv;
	map = read_args(args);
	check_map(&map);
	// printf("cords: %i %i\n", map.player.r, map.player.c);
	start_game(&map);
	return (0);
}
