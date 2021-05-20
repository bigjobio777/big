#include "libft.h"
#include "cub3d.h"

int	key_hook(int keycode, t_list *list)
{
	if (keycode == LEFT)
		list->key_pressed[LEFT] = 1;
	else if (keycode == RIGHT)
		list->key_pressed[RIGHT] = 1;
	else if (keycode == ESC)
		exit(1);
	else if (keycode == W)
		list->key_pressed[W] = 1;
	else if (keycode == S)
		list->key_pressed[S] = 1;
	else if (keycode == A)
		list->key_pressed[A] = 1;
	else if (keycode == D)
		list->key_pressed[D] = 1;
	return (0);
}

int	key_hook_exit(int keycode, t_list *list)
{
	list->unused = keycode;
	exit(0);
}

int	key_hook_stop(int keycode, t_list *list)
{
	if (keycode == LEFT)
		list->key_pressed[LEFT] = 0;
	else if (keycode == RIGHT)
		list->key_pressed[RIGHT] = 0;
	else if (keycode == W)
		list->key_pressed[W] = 0;
	else if (keycode == S)
		list->key_pressed[S] = 0;
	else if (keycode == A)
		list->key_pressed[A] = 0;
	else if (keycode == D)
		list->key_pressed[D] = 0;
	return (0);
}

void	stolbec_help(t_list *list, int stolbec, double dist)
{
	int		i;
	int		color;
	double	visota;

	(void)color;
	i = list->max_sprite;
	while (i >= 0)
	{
		if (list->sprites[i] < dist)
		{
			draw_sprite2(list, &visota, &i);
			while (list->sprite_j < (list->r_y + visota) / 2
				&& list->sprite_j < list->r_y)
			{	
				if (list->sprite_j >= 0 && (list->texturecolumn[i] < 0.5
						&& list->texturecolumn[i] > -0.5))
					draw_sprite(list, visota, stolbec, i);
				list->sprite_j++;
				list->sprite_k++;
			}
		}
		i--;
	}
}

void	stolbec(t_list *list, int stolbec, double walldistance, int color)
{
	double	visota;

	visota = (list->focus / list->dist) * list->r_x;
	list->sprites = (list->sprites);
	sort(list);
	while (list->i <= (list->r_y - visota) / 2 && list->i < list->r_y)
	{
		my_mlx_pixel_put(list, stolbec, list->i, list->ceiling);
		list->i++;
	}
	if (visota > list->r_y)
		list->k = (visota - list->r_y) / 2;
	while (list->i <= (list->r_y + visota) / 2 && list->i < list->r_y)
	{
		if (color == NORTH)
			col_north(list, visota, walldistance, stolbec);
		else if (color == SOUTH)
			col_south(list, visota, walldistance, stolbec);
		else if (color == WEST)
			col_west(list, visota, walldistance, stolbec);
		else if (color == EAST)
			col_east(list, visota, walldistance, stolbec);
	}
	draw_ceiling(list, stolbec, list->dist);
}
