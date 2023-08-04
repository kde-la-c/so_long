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

void	check_cell(t_map *map, t_cords cords);

void	find_path(t_map *map, t_cords cords)
{
	check_cell(&(*map), setcords(cords.r - 1, cords.c));
	check_cell(&(*map), setcords(cords.r, cords.c + 1));
	check_cell(&(*map), setcords(cords.r + 1, cords.c));
	check_cell(&(*map), setcords(cords.r, cords.c - 1));
}

void	check_cell(t_map *map, t_cords cords)
{
	if (map->tmpmap[cords.r][cords.c] != CH_WALL
		&& (cords.r == 0 || cords.r == map->dimensions.r
			|| cords.c == 0 || cords.c == map->dimensions.c))
		print_error("Invalid path");
	else if (map->tmpmap[cords.r][cords.c] == CH_WALL
		|| map->tmpmap[cords.r][cords.c] == CH_PLAYER)
		return ;
	if (map->tmpmap[cords.r][cords.c] == CH_COLLEC)
		map->nbcollec--;
	if (map->tmpmap[cords.r][cords.c] == CH_EXIT)
		map->path = 1;
	map->tmpmap[cords.r][cords.c] = CH_PLAYER;
	find_path(&(*map), cords);
}

int	check_req(t_map *map)
{
	t_count	c;

	ft_bzero((void *)&c, sizeof(t_count));
	while (map->map[c.i] && map->map[c.i][c.j])
	{
		if (!c.j && (map->dimensions.c + 1)
			!= (int)ft_strlen(map->map[c.i]) + (c.i + 1 == map->dimensions.r))
			return (0);
		else if (!ft_strchr(CH_SET, map->map[c.i][c.j]))
			return (0);
		else if (map->map[c.i][c.j] == CH_COLLEC)
			map->nbcollec++;
		else if (map->map[c.i][c.j] == CH_PLAYER && ++c.k)
			map->player = setcords((int)c.i, (int)c.j);
		else if (map->map[c.i][c.j] == CH_EXIT && ++c.l)
			map->exit = setcords((int)c.i, (int)c.j);
		c.j++;
		if (map->map[c.i][c.j] == '\n')
		{
			c.i++;
			c.j = 0;
		}
	}
	return ((c.k == 1 && c.l == 1 && map->nbcollec));
}

void	check_map(t_map *map)
{
	if (!check_req(&(*map)))
		print_error("Invalid map");
	if (map->player.c != map->dimensions.c && map->player.c != 0
		&& map->player.r != map->dimensions.r && map->player.r != 0)
		find_path(map, map->player);
	else
		print_error("Invalid path");
	if (!map->path || map->nbcollec)
		print_error("Invalid path");
}
