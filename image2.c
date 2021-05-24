/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfines <tfines>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 23:22:52 by bigjobio          #+#    #+#             */
/*   Updated: 2021/05/24 17:13:12 by tfines           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	draw_ceiling(t_list *list, int stolbec, double dist)
{
	list->k = 0;
	while (list->i < list->r_y)
	{
		my_mlx_pixel_put(list, stolbec, list->i, list->floor);
		list->i++;
	}
	list->i = 0;
	stolbec_help(list, stolbec, dist);
}

void	draw_sprite2(t_list *list, double *visota, int *i)
{
	*(visota) = ((list->focus / (list->sprites[*(i)])) * list->r_x);
	list->sprite_k = 0;
	if (*(visota) > list->r_y)
		list->sprite_k = (*(visota) - list->r_y) / 2;
	list->sprite_j = fmax((list->r_y - *(visota)) / 2, 0);
}

void	draw_sprite(t_list *list, double visota, int stolbec, int i)
{
	char	*col;

	col = (char *)list->tsprite.addr + (int)(list->sprite_k * list->tsprite.y
			/ visota) *list->tsprite.line_length
		+ (int)((0.5 - list->texturecolumn[i])
			* list->tsprite.x) *(list->tnorth.bits_per_pixel / 8);
	if (*(unsigned int *)col != 4278190080 && *(unsigned int *)col != 0)
		my_mlx_pixel_put(list, stolbec, list->sprite_j,
			*(unsigned int *)col);
}
