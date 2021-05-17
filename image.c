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
	int		j;
	int		k;
	int		color;
	double	visota;

	(void)color;
	i = list->max_sprite;
	j = 0;
	while (i >= 0)
	{
		if (list->sprites[i] < dist)
		{
			visota = ((list->focus / (list->sprites[i])) * list->r_x);
			k = 0;
			if (visota > list->r_y)
				k = (visota - list->r_y) / 2;
			j = fmax((list->r_y - visota) / 2, 0);
			while (j < (list->r_y + visota) / 2 && j < list->r_y)
			{	
				if (j >= 0 && (list->texturecolumn[i] < 0.5
						&& list->texturecolumn[i] > -0.5))
				{
					char *col = (char *)list->tsprite.addr
						+ (int)(k * list->tsprite.y
						/ visota) * list->tsprite.line_length
						+ (int)((0.5 - list->texturecolumn[i])
						* list->tsprite.x)
						* (list->tnorth.bits_per_pixel / 8);
					if (*(unsigned int *)col != 0)
						my_mlx_pixel_put(list, stolbec, j,
							*(unsigned int *)col);
				}
				j++;
				k++;
			}
		}
		i--;
	}
}

void	stolbec(t_list *list, int stolbec, double dist, double walldistance, int color)
{
	int		i;
	double	visota;
	char	*col;
	int		k;

	i = 0;
	k = 0;
	visota = (list->focus / dist) * list->r_x;
	list->sprites = (list->sprites);
	sort(list->sprites);
	while (i <= (list->r_y - visota) / 2 && i < list->r_y)
	{
		my_mlx_pixel_put(list, stolbec, i, list->ceiling);
		i++;
	}
	if (visota > list->r_y)
	{
		k = (visota - list->r_y) / 2;
	}
	while (i <= (list->r_y + visota) / 2 && i < list->r_y)
	{
		if (color == NORTH)
			col = (char *)list->tnorth.addr + (int)(k * list->tnorth.y
					/ visota) * list->tnorth.line_length
					+ (int)(walldistance * list->tnorth.x)
					* (list->tnorth.bits_per_pixel / 8);
		else if (color == SOUTH)
			col = (char *)list->tsouth.addr + (int)(k * list->tsouth.y
				/ visota) * list->tsouth.line_length
				+ (int)(walldistance * list->tsouth.x)
				* (list->tsouth.bits_per_pixel / 8);
		else if (color == WEST)
			col = (char *)list->twest.addr
				+ (int)(k * list->twest.y / visota)
				* list->twest.line_length
				+ (int)(walldistance * list->twest.x)
				* (list->twest.bits_per_pixel / 8);
		else if (color == EAST)
			col = (char *)list->teast.addr
				+ (int)(k * list->teast.y / visota)
				* list->teast.line_length + (int)(walldistance * list->teast.x)
				* (list->teast.bits_per_pixel / 8);
		my_mlx_pixel_put(list, stolbec, i, *(unsigned int *)col);
		i++;
		k++;
	}
	while (i < list->r_y)
	{
		my_mlx_pixel_put(list, stolbec, i, list->floor);
		i++;
	}
	stolbec_help(list, stolbec, dist);
}
