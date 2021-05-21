/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigjobio <bigjobio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 23:21:21 by bigjobio          #+#    #+#             */
/*   Updated: 2021/05/20 23:21:24 by bigjobio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	first_quatre(t_list *list, double tempo, int i)
{
	double	first;
	double	second;

	first = cast_ray_x_1(list, tempo);
	second = cast_ray_y_1(list, tempo);
	if (first < second)
	{
		list->dist = first * cos(tempo - list->pos_angle);
		stolbec(list, i, list->wall_distancex, EAST);
	}
	else
	{
		list->dist = second * cos(tempo - list->pos_angle);
		stolbec(list, i, list->wall_distancey, NORTH);
	}
}

void	second_quatre(t_list *list, double tempo, int i)
{
	double	first;
	double	second;

	first = cast_ray_x_2(list, tempo);
	second = cast_ray_y_2(list, tempo);
	if (first < second)
	{
		list->dist = first * cos(tempo - list->pos_angle);
		stolbec(list, i, list->wall_distancex, WEST);
	}
	else
	{
		list->dist = second * cos(tempo - list->pos_angle);
		stolbec(list, i, list->wall_distancey, NORTH);
	}
}

void	third_quatre(t_list *list, double tempo, int i)
{
	double	first;
	double	second;

	first = cast_ray_x_3(list, tempo);
	second = cast_ray_y_3(list, tempo);
	if (first < second)
	{
		list->dist = first * cos(tempo - list->pos_angle);
		stolbec(list, i, list->wall_distancex, WEST);
	}
	else
	{
		list->dist = second * cos(tempo - list->pos_angle);
		stolbec(list, i, list->wall_distancey, SOUTH);
	}
}

void	fouth_quatre(t_list *list, double tempo, int i)
{
	double	first;
	double	second;

	first = cast_ray_x_4(list, tempo);
	second = cast_ray_y_4(list, tempo);
	if (first < second)
	{
		list->dist = first * cos(tempo - list->pos_angle);
		stolbec(list, i, list->wall_distancex, EAST);
	}
	else
	{
		list->dist = second * cos(tempo - list->pos_angle);
		stolbec(list, i, list->wall_distancey, SOUTH);
	}
}
