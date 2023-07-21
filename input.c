/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inpput.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:37:07 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/07/20 21:37:29 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**parse_map(char *path)
{
	t_count	c;
	char	**map;

	c.j = 0;
	c.i = open(path, O_RDONLY);
	(c.i == -1) && print_error("Couldn't open map");
	map = (char **)ft_calloc(ft_countlines(c.i) + 1, sizeof(char *));
	(!map) && print_error("Memory allocation error");
	close(c.i);
	c.i = open(path, O_RDONLY);
	(c.i == -1) && print_error("Couldn't open map");
	map[c.j] = get_next_line(c.i);
	while (map[c.j++])
		map[c.j] = get_next_line(c.i);
	return (map);
}

char	**read_args(t_args args)
{
	char	*path;

	if (args.argc != 2)
		print_error("Invalid number of arguments");
	path = args.argv[1];
	if (ft_strncmp(&path[ft_strlen(path) - 4], ".ber", 5))
		print_error("Invalid map name");
	return (parse_map(path));
}