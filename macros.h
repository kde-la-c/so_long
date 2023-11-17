/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:32:37 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/07/27 13:32:44 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define CH_SET		"01CEP\n"
# define CH_WALL	'1'
# define CH_SPACE	'0'
# define CH_PLAYER	'P'
# define CH_COLLEC	'C'
# define CH_EXIT	'E'

# ifdef __APPLE__
#  define KEY_ESC	53 
#  define KEY_W		13
#  define KEY_A		0
#  define KEY_S		1
#  define KEY_D		2
#  define KEY_UP	126
#  define KEY_LEFT	123
#  define KEY_DOWN	125
#  define KEY_RIGHT	124
#  define KEY_TEST	49
# elif __linux__
#  define KEY_ESC	65307
#  define KEY_W		122
#  define KEY_A		113
#  define KEY_S		115
#  define KEY_D		100
#  define KEY_UP	65362
#  define KEY_LEFT	65361
#  define KEY_DOWN	65364
#  define KEY_RIGHT	65363
#  define KEY_TEST	32
# endif

#endif
