/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 01:52:09 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/07/21 01:52:29 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void	check_path(char **map)
{

}

void	check_walls(char **map)
{
	
} */

void	check_map(char **map)
{
	t_count	c;

	(!map[0]) && print_error("Invalid map");
	c.i = 0;
	c.j = ft_strlen(map[0]);
	c.k = 0;
	c.l = 0;
	c.m = 0;
	while (map[++c.i])
	{
		if (ft_strlen(map[c.i]) != (size_t)c.j)
			print_error("Invalid map");
		if (ft_strchr(map[c.i], 'P'))
			c.k++;
		if (ft_strchr(map[c.i], 'E'))
			c.l++;
		if (ft_strchr(map[c.i], 'C'))
			c.m++;
	}
	if (c.i < 3 || c.k != 1 || c.l != 1 || !c.m)
		print_error("Invalid map");
}
