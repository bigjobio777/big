#include "libft.h"
#include "cub3d.h"

int	 key_hook(int keycode, t_list *list)
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
	printf("UGOL == %f\n", list->pos_angle);
	printf("Position po x == %f, Position po y = %f\n", list->pos_x, list->pos_y);
	return (0);
}

int		key_hook_exit(int	keycode, t_list *list)
{
	list->unused = keycode;
	exit(0);
}

int		key_hook_stop(int keycode, t_list *list)
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

void	stolbec_help(t_list *list, int stolbec, double walldistance)
{
	int		i;
	int		j;
	double	visota;

	i = 0;
	j = 0;
	while (list->sprites[i] != -1)
	{
		visota = ((list->focus / (list->sprites[i])) * list->r_x);
		j = (list->r_y - visota) / 2;
		while(j < (list->r_y + visota) / 2 && j < list->r_y)
		{	
			// col = (char*)list->tnorth.addr + (int)(k * list->tnorth.y / visota )* list->tnorth.line_length + (int)(walldistance * list->tnorth.x) * (list->tnorth.bits_per_pixel / 8);
			if (j >= 0 && (i + j) % 3 == 0)
			{
				my_mlx_pixel_put(list, stolbec, j, (i % 2 == 0) ? 0xAA66BB : 0);
			}
			j++;
		}
		i++;
	}
}
void	stolbec(t_list *list, int stolbec, double dist, double walldistance, int color)
{
	int	 i;
	double	visota;

	i = 0;
	visota = (list->focus / dist) * list->r_x;
	list->sprites = (list->sprites);
	sort(list->sprites);
	while (i <= (list->r_y - visota) / 2 && i < list->r_y)
	{
		my_mlx_pixel_put(list, stolbec, i, 0x115120);
		i++;
	}

	int k = 0;
	char	*col;
	if (visota > list->r_y)
	{
		k = (visota - list->r_y) / 2;
	}

	while (i <= (list->r_y + visota) / 2 && i < list->r_y)
	{
		if (color == north)
			col = (char*)list->tnorth.addr + (int)(k * list->tnorth.y / visota )* list->tnorth.line_length + (int)(walldistance * list->tnorth.x) * (list->tnorth.bits_per_pixel / 8);
		else if (color == south)
			col = (char*)list->tsouth.addr + (int)(k * list->tsouth.y / visota )* list->tsouth.line_length + (int)(walldistance * list->tsouth.x) * (list->tsouth.bits_per_pixel / 8);
		else if (color == west)
			col = (char*)list->twest.addr + (int)(k * list->twest.y / visota )* list->twest.line_length + (int)(walldistance * list->twest.x) * (list->twest.bits_per_pixel / 8);
		else if (color == east)
			col = (char*)list->teast.addr + (int)(k * list->teast.y / visota )* list->teast.line_length + (int)(walldistance * list->teast.x) * (list->teast.bits_per_pixel / 8);
		my_mlx_pixel_put(list, stolbec, i, *(unsigned int*)col);
		i++;
		k++;
	}
	while (i < list->r_y)
	{
		my_mlx_pixel_put(list, stolbec, i, 0x0000FF);
		i++;
	}
	stolbec_help(list, stolbec, walldistance);
}
