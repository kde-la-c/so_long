/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:43:09 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/11/05 23:43:12 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_char(t_map map, char ch, t_cords *ret)
{
	t_count	c;

	ft_bzero((void *)&c, sizeof(t_count));
	while (map.map[c.i])
	{
		c.j = 0;
		while (map.map[c.i][c.j])
		{
			if (map.map[c.i][c.j] == ch)
			{
				ret->r = c.i;
				ret->c = c.j;
				break ;
			}
			c.j++;
		}
		c.i++;
	}
	if (!map.map[c.i])
		ret = NULL;
}

void	move(t_mlxptr *mlx, t_map *map, int direction) //dir: 1=up 2=left 3=down 4=right
{
	t_cords	dest;
	(void)dest;
	(void)mlx;

	printf("cords : %i %i\n", map->player.r, map->player.c);
	if (direction == 1 && map->map[map->player.r - 1][map->player.c] != CH_WALL)
		dest = setcords(map->player.r - 1, map->player.c);
	else if (direction == 2 && map->map[map->player.r][map->player.c - 1] != CH_WALL)
		dest = setcords(map->player.r, map->player.c - 1);
	else if (direction == 3 && map->map[map->player.r + 1][map->player.c] != CH_WALL)
		dest = setcords(map->player.r + 1, map->player.c);
	else if (direction == 4 && map->map[map->player.r][map->player.c + 1] != CH_WALL)
		dest = setcords(map->player.r, map->player.c + 1);
	else
		return ;
	printf("move ok\n");
}

