/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 03:05:25 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/08/05 03:05:27 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "libft/libft.h"

typedef struct s_img
{
	void	*img;
	char	*path;
	t_cords	dim;
}	t_img;

typedef struct s_map
{
	char	**map;
	char	**tmpmap;
	t_cords	player;
	t_cords	exit;
	int		nbcollec;
	t_cords	dimensions;
	int		path;
	t_img	floor;
	t_img	wall;
	t_img	character;
	t_img	collectible;
}	t_map;

typedef struct s_mlxptr
{
	void	*mlx;
	void	*win;
}	t_mlxptr;

#endif
