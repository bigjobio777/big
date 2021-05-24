/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_karta_helps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfines <tfines>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:30:36 by bigjobio          #+#    #+#             */
/*   Updated: 2021/05/21 23:30:21 by tfines           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../cub3d.h"

void	karta_helpik(t_list *list, int *length_x, int *length_y)
{
	*(length_y) = 0;
	*(length_x) = ft_strlen(list->karta[0]);
	while (list->karta[*(length_y)])
		(*length_y)++;
}

void	mem_killer(t_list *list)
{
	int		d;

	d = 0;
	while (list->karta[d])
	{
		free(list->karta[d]);
		d++;
	}
	free(list->karta);
	list->karta = NULL;
}

void	mem_uni_killer(char **src)
{
	int		d;

	d = 0;
	while (src[d])
	{
		free(src[d]);
		d++;
	}
	free(src);
	src = NULL;
}

void	make_r_x_y(t_list *list, char **src, int i)
{
	if (i == 1)
	{
		list->r_x = ft_atoi(src[i]);
		if (list->r_x == 0)
			print_error(-4);
		if (list->r_x < 0 || list->r_x > 100000)
			list->r_x = 99999;
	}
	else if (i == 2)
	{
		list->r_y = ft_atoi(src[i]);
		if (list->r_y == 0)
			print_error(-4);
		if (list->r_y < 0 || list->r_y > 100000)
			list->r_y = 99999;
	}
}

void	checker_mapik(t_list *list, char *line)
{
	if (list->bil_1 == 1 && (line[0] == ' '
			|| line[0] == '1') && !list->lastline[0])
		print_error(-76);
}
