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

static void	parse_map(char *path, char ***map)
{
	int		i;
	char	*str;
	char	*line;

	i = open(path, O_RDONLY);
	if (i == -1)
		perror_exit("Error\nCouldn't open map");
	str = NULL;
	line = get_next_line(i);
	if (!line)
		error_exit("Error\nInvalid map");
	while (line)
	{
		if (!str)
			str = ft_strjoin_f2("", line);
		else
			str = ft_strjoin_f12(str, line);
		line = get_next_line(i);
	}
	*map = ft_split(str, '\n');
	if (!*map)
		error_exit("Memory allocation error");
	free(str);
	free(line);
	close(i);
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
	parse_map(path, &map.map);
	parse_map(path, &map.tmpmap);
	return (map);
}
