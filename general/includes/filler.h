/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <sdagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:34:23 by sdagger           #+#    #+#             */
/*   Updated: 2020/09/20 20:11:35 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H
#include "libft.h"

typedef			enum
{
	undefined,
	player1,
	player2
}				t_player;

typedef struct	s_fill
{
	t_player	player;
	int			height;
	int			width;
}				t_fill;

/*
** filler structure functions
*/

t_fill			*new_fill();
void			free_fill(t_fill *fill);

/*
** service functions
*/

t_fill	*error_f(char *errortext, int init);

#endif
