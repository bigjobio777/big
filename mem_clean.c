/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfines <tfines>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 23:03:16 by tfines            #+#    #+#             */
/*   Updated: 2021/05/26 00:12:07 by tfines           ###   ########.fr       */
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

void	init_3(t_list *big)
{
	big->h = 0;
	big->lastline = NULL;
	big->second_fd = -1;
	big->data.img = NULL;
	big->tnorth.img = NULL;
	big->tsouth.img = NULL;
	big->teast.img = NULL;
	big->twest.img = NULL;
	big->tsprite.img = NULL;
	big->mlx.mlx_win = NULL;
}
