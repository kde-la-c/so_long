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
	if (key == 53)
		on_destroy(vars);
	ft_printf("key :%i\n", key);
	return (0);
}
