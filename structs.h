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

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_map
{
	char	**map;
	char	**tmpmap;
	t_cords	player;
	t_cords	exit;
	int		nbcollec;
	t_cords	dimensions;
	int		path;
}	t_map;

typedef struct s_mlxptr
{
	void	*mlx;
	void	*win;
}	t_mlxptr;

typedef struct s_img
{
	void	*img;
	char	*path;
	t_cords	dim;
}	t_img;

#endif
