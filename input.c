/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:37:07 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/07/20 21:37:29 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**parse_map(char *path, t_cords *dimensions)
{
	t_count	c;
	char	**map;

	c.j = 0;
	c.i = open(path, O_RDONLY);
	if (c.i == -1)
		error_exit("Error\nCouldn't open map");
	map = (char **)ft_calloc(ft_countlines(c.i) + 1, sizeof(char *));
	if (!map)
		error_exit("Memory allocation error");
	close(c.i);
	c.i = open(path, O_RDONLY);
	if (c.i == -1)
		error_exit("Error\nCouldn't open map");
	map[c.j] = get_next_line(c.i);
	while (map[c.j])
		map[++c.j] = get_next_line(c.i);
	if (dimensions && c.j)
	{
		dimensions->r = (int)c.j;
		dimensions->c = (int)ft_strlen(map[0]) - 1;
	}
	return (map);
}

t_map	read_args(t_args args)
{
	char	*path;
	t_map	map;

	if (args.argc != 2)
		error_exit("Error\nInvalid number of arguments");
	path = args.argv[1];
	if (ft_strncmp(&path[ft_strlen(path) - 4], ".ber", 5))
		error_exit("Error\nInvalid map name");
	ft_bzero((void *)&map, sizeof(t_map));
	map.map = parse_map(path, &map.dimensions);
	map.tmpmap = parse_map(path, NULL);
	return (map);
}
