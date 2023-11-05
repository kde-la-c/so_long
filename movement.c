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

void	move(t_map *map, int direction)
{
	t_cords	player;
	(void)direction;

	find_char(*map, CH_PLAYER, &player);

}
