/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 03:02:40 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/08/05 03:02:44 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_mlxptr *vars)
{
	(void)vars;
	print_output("window closed");
	return (0);
}

int	on_key(int key, t_mlxptr *vars)
{
	if (key == KEY_ESC)
		on_destroy(vars);
	// else if (key == KEY_UP || key == KEY_W)
	// 	move(1);
	// else if (key == KEY_LEFT || key == KEY_A)
	// 	move(2);
	// else if (key == KEY_DOWN || key == KEY_S)
	// 	move(3);
	// else if (key == KEY_RIGHT || key == KEY_D)
	// 	move(4);
	ft_printf("key :%i\n", key);
	return (0);
}
