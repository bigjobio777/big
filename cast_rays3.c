#include "cub3d.h"

void	first_quatre(t_list *list, double tempo, int i)
{
	double	first;
	double	second;

	first = cast_ray_x_1(list, tempo);
	second = cast_ray_y_1(list, tempo);
	if (first < second)
		stolbec(list, i, first * cos(tempo - list->pos_angle),
			list->wall_distancex, east);
	else
		stolbec(list, i, second * cos(tempo - list->pos_angle),
			list->wall_distancey, north);
}

void	second_quatre(t_list *list, double tempo, int i)
{
	double	first;
	double	second;

	first = cast_ray_x_2(list, tempo);
	second = cast_ray_y_2(list, tempo);
	if (first < second)
		stolbec(list, i, first * cos(tempo - list->pos_angle),
			list->wall_distancex, west);
	else
		stolbec(list, i, second * cos(tempo - list->pos_angle),
			list->wall_distancey, north);
}

void	third_quatre(t_list *list, double tempo, int i)
{
	double	first;
	double	second;

	first = cast_ray_x_3(list, tempo);
	second = cast_ray_y_3(list, tempo);
	if (first < second)
		stolbec(list, i, first * cos(tempo - list->pos_angle),
			list->wall_distancex, west);
	else
		stolbec(list, i, second * cos(tempo - list->pos_angle),
			list->wall_distancey, south);
}
