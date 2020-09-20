/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <sdagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:06:32 by sdagger           #+#    #+#             */
/*   Updated: 2020/09/20 20:06:32 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_fill	*new_fill()
{
	t_fill		*fill;

	fill = malloc(sizeof(fill));
	if (!fill)
		ft_error_t("malloc new fill");
	else
	{
		fill->player = undefined;
		return (fill);
	}
}

void	free_fill(t_fill *fill)
{
	if (fill)
	{

		free(fill);
	}
}