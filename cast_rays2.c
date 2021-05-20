#include "Libft/libft.h"
#include "cub3d.h"
#include <math.h>

double	cast_ray_x_3(t_list *list, double tempo)
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
			sprites(list, x - 1 + 0.5, (int)dot_y + 0.5, tempo);
		x--;
		length_x = x - list->pos_x;
		length_y = length_x * tan(tempo);
		dot_y = length_y + list->pos_y;
	}
	list->wall_distancex = dot_y - (int)dot_y;
	length_for_wall = fabs(length_x / cos(tempo));
	return (length_for_wall);
}

double	cast_ray_y_3(t_list *list, double tempo)
{
	double	length_x;
	double	length_y;
	double	dot_x;
	double	length_for_wall;
	int		y;

	y = (int)(list->pos_y);
	length_y = y - list->pos_y;
	length_x = length_y / tan(tempo);
	dot_x = length_x + list->pos_x;
	while ((y - 1 < list->max_y && y - 1 >= 0)
		&& (dot_x >= 0 && dot_x < list->max_x)
		&& list->karta[y - 1][(int)dot_x] != '1')
	{
		if (list->karta[y - 1][(int)dot_x] == '2')
			sprites(list, (int)dot_x + 0.5, y - 1 + 0.5, tempo);
		y--;
		length_y = y - list->pos_y;
		length_x = length_y / tan(tempo);
		dot_x = length_x + list->pos_x;
	}
	list->wall_distancey = 1 - (dot_x - (int)dot_x);
	length_for_wall = fabs(length_y / sin(tempo));
	return (length_for_wall);
}

double	cast_ray_x_4(t_list *list, double tempo)
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
			sprites(list, x + 0.5, (int)dot_y + 0.5, tempo);
		x++;
		length_x = x - list->pos_x;
		length_y = length_x * tan(tempo);
		dot_y = length_y + list->pos_y;
	}
	list->wall_distancex = 1 - (dot_y - (int)dot_y);
	length_for_wall = fabs(length_x / cos(tempo));
	return (length_for_wall);
}

double	cast_ray_y_4(t_list *list, double tempo)
{
	double	length_x;
	double	length_y;
	double	dot_x;
	double	length_for_wall;
	int		y;

	y = (int)(list->pos_y);
	length_y = y - list->pos_y;
	length_x = length_y / tan(tempo);
	dot_x = length_x + list->pos_x;
	while ((y - 1 < list->max_y && y - 1 >= 0)
		&& (dot_x >= 0 && dot_x < list->max_x)
		&& list->karta[y - 1][(int)dot_x] != '1')
	{
		if (list->karta[y - 1][(int)dot_x] == '2')
			sprites(list, (int)dot_x + 0.5, y - 1 + 0.5, tempo);
		y--;
		length_y = y - list->pos_y;
		length_x = length_y / tan(tempo);
		dot_x = length_x + list->pos_x;
	}
	list->wall_distancey = 1 - (dot_x - (int)dot_x);
	length_for_wall = fabs(length_y / sin(tempo));
	return (length_for_wall);
}
