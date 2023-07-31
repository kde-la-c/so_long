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
/* int	find_path(t_map *map, t_cords cords)
{
	int	ret;

	if ((*map).tmpmap[cords.x][cords.y] != CH_PLAYER)
		return (0);
	else
	{
		ret = check_cell(&(*map), setcords(cords.x, cords.y - 1));
		ret += check_cell(&(*map), setcords(cords.x + 1, cords.y));
		ret += check_cell(&(*map), setcords(cords.x, cords.y + 1));
		ret += check_cell(&(*map), setcords(cords.x - 1, cords.y));
	}
	return (ret);
}

int	check_cell(t_map *map, t_cords cords)
{
	if ((*map).tmpmap[cords.x][cords.y] == CH_PLAYER
		|| ((*map).tmpmap[cords.x][cords.y] == CH_SPACE 
			&& (cords.x != 0 && (*map).tmpmap[cords.x + 1][cords.y] != '\n'
				&&)))
} */

int	check_req(t_map *map)
{
	t_count	c;

	ft_bzero((void *)&c, sizeof(t_count));
	while ((*map).map[c.i] && (*map).map[c.i][c.j])
	{
		if (!c.j && ft_strlen((*map).map[0]) != ft_strlen((*map).map[c.i]))
			return (0);
		else if (!ft_strchr(CH_SET, (*map).map[c.i][c.j]))	
			return (0);
		else if ((*map).map[c.i][c.j] == CH_COLLEC)
			(*map).nbcollec++;
		else if ((*map).map[c.i][c.j] == CH_PLAYER && ++c.k)
			(*map).player = setcords((int)c.i, (int)c.j);
		else if ((*map).map[c.i][c.j] == CH_EXIT && ++c.l)
			(*map).exit = setcords((int)c.i, (int)c.j);
		c.j++;
		if ((*map).map[c.i][c.j] == '\n')
		{
			c.i++;
			c.j = 0;
		}
	}
	return ((c.k == 1 && c.l == 1 && (*map).nbcollec));
}

void	check_map(t_map *map)
{
	if (!check_req(&(*map)))
		print_error("Invalid map");
}
