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

t_cords	setcords(int x, int y)
{
	t_cords	ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

int	main(int argc, char **argv)
{
	t_count	c;
	t_args	args;
	t_map	map;

	c.i = 0;
	args.argc = argc;
	args.argv = argv;
	map = read_args(args);
	check_map(&map);
	while (map.map[c.i])
	{
		ft_printf("%s", map.map[c.i]);
		c.i++;
	}
	return (0);
}
