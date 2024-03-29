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

static void	check_cell(t_map *map, t_cords cords);

static void	find_path(t_map *map, t_cords cords)
{
	check_cell(map, ft_setcords(cords.r - 1, cords.c));
	check_cell(map, ft_setcords(cords.r, cords.c + 1));
	check_cell(map, ft_setcords(cords.r + 1, cords.c));
	check_cell(map, ft_setcords(cords.r, cords.c - 1));
}

static void	check_cell(t_map *map, t_cords cords)
{
	if (map->tmpmap[cords.r][cords.c] != CH_WALL
		&& (cords.r == 0 || cords.r == map->dimensions.r
			|| cords.c == 0 || cords.c == map->dimensions.c))
		error_exit("Error\nInvalid path");
	else if (map->tmpmap[cords.r][cords.c] == CH_WALL
		|| map->tmpmap[cords.r][cords.c] == CH_PLAYER)
		return ;
	if (map->tmpmap[cords.r][cords.c] == CH_COLLEC)
		map->nbcollec--;
	if (map->tmpmap[cords.r][cords.c] == CH_EXIT)
		map->path = 1;
	map->tmpmap[cords.r][cords.c] = CH_PLAYER;
	find_path(map, cords);
}

static int	check_req(t_map *map)
{
	t_count	c;

	ft_bzero((void *)&c, sizeof(t_count));
	while (map->map[c.i] && map->map[c.i][c.j])
	{
		if (!c.j && map->dimensions.c != (int)ft_strlen(map->map[c.i]))
			return (0);
		else if (!ft_strchr(CH_SET, map->map[c.i][c.j]))
			return (0);
		else if (map->map[c.i][c.j] == CH_COLLEC)
			map->nbcollec += 1;
		else if (map->map[c.i][c.j] == CH_PLAYER && ++c.k)
			map->player = ft_setcords((int)c.i, (int)c.j);
		else if (map->map[c.i][c.j] == CH_EXIT && ++c.l)
			map->exit = ft_setcords((int)c.i, (int)c.j);
		c.j++;
		if (!map->map[c.i][c.j])
		{
			c.i++;
			c.j = 0;
		}
	}
	return ((c.k == 1 && c.l == 1 && map->nbcollec
			&& map->dimensions.r <= 40 && map->dimensions.c <= 80));
}

static int	check_borders(t_map map)
{
	t_count	c;

	ft_bzero((void *)&c, sizeof(t_count));
	c.j = map.dimensions.r - 1;
	c.k = map.dimensions.c - 1;
	while (map.map[0][c.i] && map.map[c.j][c.i])
	{
		if (map.map[0][c.i] != CH_WALL || map.map[c.j][c.i] != CH_WALL)
			return (0);
		c.i++;
	}
	c.i = 1;
	while (map.map[c.i + 1])
	{
		if (map.map[c.i][0] != CH_WALL || map.map[c.i][c.k] != CH_WALL)
			return (0);
		c.i++;
	}
	return (1);
}

void	check_map(t_map *map)
{
	int	i;
	int	tmp;

	i = 0;
	while (map->map[i])
		i++;
	map->dimensions.r = i;
	map->dimensions.c = ft_strlen(map->map[0]);
	if (i)
		map->dimensions.c = ft_strlen(map->map[0]);
	if (!check_req(map) || !check_borders(*map))
		error_exit("Error\nInvalid map");
	tmp = map->nbcollec;
	find_path(map, map->player);
	if (!map->path || map->nbcollec)
		error_exit("Error\nInvalid path");
	map->nbcollec = tmp;
}
