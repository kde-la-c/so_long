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
void	find_path(char **map)
{
	t_count	c;
	char	**expmap;

	c.i = 0;
	c.j = 0;
	
}

/* int	check_walls(char **map, long len)
{
	t_count	c;
	long	*pos;

	c.i = 0;
	c.j = 0;
	c.k = 0;
	pos = (long *)ft_calloc(len + 1, sizeof(long));
	while (map[c.i])
	{
		while (map[c.i][c.j])
			if (map[c.i][c.j] == '1')
				pos[c.k++] = c.j;
		
	}
} */

void	check_map(char **map)
{
	t_count	c;

	(!map[0]) && print_error("Invalid map");
	c.i = 0;
	c.j = -1;
	c.k = 0;
	c.l = 0;
	c.m = 0;
	while (map[c.i] && map[c.i][++c.j])
		if (ft_strlen(map[c.i]) != ft_strlen(map[0])
			|| !strchr("01CEP\n", map[c.i][c.j]))
			print_error("Invalid map");
	else if (map[c.i][c.j] == 'P')
		c.k++;
	else if (map[c.i][c.j] == 'E')
		c.l++;
	else if (map[c.i][c.j] == 'C')
		c.m++;
	else if (map[c.i][c.j] == '\n')
	{
		c.j = -1;
		c.i++;
	}
	if (c.i < 3 || c.k != 1 || c.l != 1 || !c.m)
		print_error("Invalid map");
}
