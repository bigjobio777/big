#include "cub3d.h"
#include <math.h>

double	cast_ray_x_1(t_list *list, double tempo)
{
	double	length_x;
	double	length_y;
	double	dot_y;
	double	length_for_wall;
	int		x;

	x = (int)(list->pos_x + 1);
	length_x = x - list->pos_x;
	length_y = length_x * tan(tempo);
	dot_y = length_y + list->pos_y;
	while (((int)dot_y < list->max_y && (int)dot_y >= 0)
		&& (x >= 0 && x < list->max_x) && list->karta[(int)(dot_y)][x] != '1')
	{
		if (list->karta[(int)(dot_y)][x] == '2')
			sprites_1(list, x + 0.5, (int)dot_y + 0.5, tempo);
		x++;
		length_x = x - list->pos_x;
		length_y = length_x * tan(tempo);
		dot_y = length_y + list->pos_y;
	}
	length_for_wall = fabs(length_y / sin(tempo));
	list->wall_distancex = 1 - (dot_y - (int)dot_y);
	return (length_for_wall);
}

double	cast_ray_y_1(t_list *list, double tempo)
{
	double	length_x;
	double	length_y;
	double	dot_x;
	double	length_for_wall;
	int		y;

	y = (int)(list->pos_y + 1);
	length_y = y - list->pos_y;
	length_x = length_y / tan(tempo);
	dot_x = length_x + list->pos_x;
	while ((y < list->max_y && y >= 0) && (dot_x >= 0 && dot_x < list->max_x)
		&& list->karta[y][((int)(dot_x))] != '1')
	{
		if (list->karta[y][(int)dot_x] == '2')
			sprites_1(list, (int)dot_x + 0.5, y + 0.5, tempo);
		y++;
		length_y = y - list->pos_y;
		length_x = length_y / tan(tempo);
		dot_x = length_x + list->pos_x;
	}
	length_for_wall = fabs(length_y / sin(tempo));
	list->wall_distancey = dot_x - (int)dot_x;
	return (length_for_wall);
}

double	cast_ray_x_2(t_list *list, double tempo)
{
	double	length_x;
	double	length_y;
	double	dot_y;
	double	length_for_wall;
	int		x;

	x = (int)(list->pos_x);
	length_x = x - list->pos_x;
	length_y = length_x * tan(tempo);
	dot_y = length_y + list->pos_y;
	while (((int)dot_y < list->max_y && (int)dot_y >= 0)
		&& (x - 1 >= 0 && x - 1 < list->max_x)
		&& list->karta[(int)(dot_y)][x - 1] != '1')
	{
		if (list->karta[(int)(dot_y)][x - 1] == '2')
			sprites_1(list, x - 1 + 0.5, (int)dot_y + 0.5, tempo);
		x--;
		length_x = x - list->pos_x;
		length_y = length_x * tan(tempo);
		dot_y = length_y + list->pos_y;
	}
	list->wall_distancex = dot_y - (int)dot_y;
	length_for_wall = fabs(length_x / cos(tempo));
	return (length_for_wall);
}

double	cast_ray_y_2(t_list *list, double tempo)
{
	double	length_x;
	double	length_y;
	double	dot_x;
	double	length_for_wall;
	int		y;

	y = (int)(list->pos_y + 1);
	length_y = y - list->pos_y;
	length_x = length_y / tan(tempo);
	dot_x = list->pos_x + length_x;
	while ((y < list->max_y && y >= 0) && (dot_x >= 0 && dot_x < list->max_x)
		&& list->karta[y][((int)(dot_x))] != '1')
	{
		if (list->karta[y][(int)dot_x] == '2')
			sprites_1(list, (int)dot_x + 0.5, y + 0.5, tempo);
		y++;
		length_y = y - list->pos_y;
		length_x = length_y / tan(tempo);
		dot_x = list->pos_x + length_x;
	}
	list->wall_distancey = dot_x - (int)dot_x;
	length_for_wall = fabs(length_y / sin(tempo));
	return (length_for_wall);
}

void	cast_rays(t_list *list)
{
	double	increment_FOV;
	double	tempo;
	int		i;

	i = 0;
	tempo = list->pos_angle + list->FOV / 2;
	increment_FOV = list->FOV / list->r_x;
	while ((tempo >= (list->pos_angle - list->FOV / 2)) && (i < list->r_x))
	{
		if ((tempo >= 0 && tempo < (M_PI / 2))
			|| (tempo >= 2 * M_PI && tempo <= 5 * M_PI_2))
			first_quatre(list, tempo, i);
		else if (tempo >= (M_PI_2) && tempo < M_PI)
			second_quatre(list, tempo, i);
		else if (tempo >= M_PI && tempo < (3 * (M_PI_2)))
			third_quatre(list, tempo, i);
		else if ((tempo >= (3 * (M_PI / 2)) && tempo < (2 * M_PI))
			|| (tempo >= -M_PI_2 && tempo <= 0))
			fouth_quatre(list, tempo, i);
		i++;
		tempo -= increment_FOV;
		list->sprites[0] = -1;
		list->texturecolumn[0] = -1;
		list->max_sprite = 0;
	}
}
