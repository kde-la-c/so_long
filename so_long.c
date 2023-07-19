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

int	main(int argc, char **argv)
{
	char	**map;
	char	*path;

	map = NULL;
	if (argc != 2)
		print_error("Invalid number of arguments");
	path = argv[1];
	if (ft_strncmp(&path[ft_strlen(path) - 4], ".ber", 5))
		print_error("Invalid map name");
	check_map(open(argv[1], O_RDONLY), &map);
	return (0);
}