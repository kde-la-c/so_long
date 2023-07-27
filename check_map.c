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

//TODO flood changing everything to players and reducing number of required elements when you touch them
// i can check all P that have at least one neighbouring !P
// if i havent reached all C and E before the end or have reached a limit at any time the map is wrong
/* void	find_path(char **map)
{
	t_count	c;
	char	**expmap;

	c = ft_initcount(0);
	
}

void	check_neighbours(char **map)
{
	
} */

void	check_req(t_map *map)
{
	t_count	c;

	ft_bzero((void *)&c, sizeof(t_count));
	while ((*map).map[c.i] && (*map).map[c.i][c.j])
	{
		if ()
	}
}

void	check_map(t_map *map)
{
	check_req(&(*map));
}
