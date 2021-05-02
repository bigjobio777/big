#include "Libft/libft.h"
#include "cub3d.h"

void		init_flags(t_list *big)
{
	int		i;

	i = 0;
	big->r_x = 0;
	big->r_y = 0;
	big->path_to_north = NULL;
	big->path_to_west = NULL;
	big->path_to_south = NULL;
	big->path_to_east = NULL;
	big->path_to_sprite = NULL;
	big->floor_red = -1;
	big->floor_green = 0;
	big->floor_blue = 0;
	big->ceiling_red = -1;
	big->ceiling_green = 0;
	big->ceiling_blue = 0;
	big->max_map = 0;
	big->help_mas = 0;
	big->bil_1 = 0;
	big->playes_location = 0;
	big->karta = NULL;
	big->pos_x = 15;
	big->pos_y = 15;
	big->pos_angle = 1;
	big->FOV = (M_PI / 3);
	big->max_x = 0;
	big->max_y = 0;
	big->focus = 0.25;
	big->sprites = (double *)malloc(sizeof(double) * (1));
	big->sprites[0] = -1;
	while (i < 127)
	{
		big->key_pressed[i] = 0;
		i++;
	}
}