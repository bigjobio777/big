/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfines <tfines>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 23:03:16 by tfines            #+#    #+#             */
/*   Updated: 2021/05/24 23:38:57 by tfines           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "cub3d.h"

void	mem_free_list(t_list *list)
{
	int		i;

	i = 0;
	if (list->karta)
	{
		while (list->karta[i])
			free(list->karta[i++]);
		free(list->karta);
	}
	if (list->sprites)
		free(list->sprites);
	if (list->texturecolumn)
		free(list->texturecolumn);
	i = 0;
	if (list->tempo)
	{
		while (list->tempo[i])
			free(list->tempo[i++]);
		free(list->tempo);
	}
	if (list->lastline)
		free(list->lastline);
}

void	mem_clean_mlx(t_list *list)
{
	if (list->tnorth.img)
		mlx_destroy_image(list->mlx.mlx, list->tnorth.img);
	if (list->tsouth.img)
		mlx_destroy_image(list->mlx.mlx, list->tsouth.img);
	if (list->teast.img)
		mlx_destroy_image(list->mlx.mlx, list->teast.img);
	if (list->twest.img)
		mlx_destroy_image(list->mlx.mlx, list->twest.img);
}
