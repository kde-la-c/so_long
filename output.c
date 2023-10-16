/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:50:10 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/07/19 16:50:31 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_error(char *err)
{
	write(2, &err[0], ft_strlen(err));
	write(2, "\n", 1);
	exit(1);
}

int	perror_exit(char *err)
{
	perror(err);
	exit(1);
}

int	print_output(char *msg)
{
	write(2, &msg[0], ft_strlen(msg));
	write(2, "\n", 1);
	exit(0);
}
