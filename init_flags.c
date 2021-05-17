#include "Libft/libft.h"
#include "cub3d.h"

void	init_flags2(t_list *big)
{
	int		i;

	i = 0;
	big->focus = 1;
	big->sprites = (double *)malloc(sizeof(double) * (1));
	big->sprites[0] = -1;
	big->texturecolumn = (double *)malloc(sizeof(double) * (1));
	big->texturecolumn[0] = -1;
	while (i < 127)
	{
		big->key_pressed[i] = 0;
		i++;
	}
	big->i = 0;
	big->j = 0;
	big->length = 0;
	big->tempo = NULL;
	big->unused = 0;
	big->max_sprite = 0;
}

void	init_flags(t_list *big)
{
	big->r_x = 0;
	big->r_y = 0;
	big->tnorth.file = NULL;
	big->twest.file = NULL;
	big->tsouth.file = NULL;
	big->teast.file = NULL;
	big->tsprite.file = NULL;
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
	init_flags2(big);
}

void	my_mlx_pixel_put(t_list *list, int x, int y, long color)
{
	char	*dst;

	dst = (char *)list->data.addr + (y * list->data.line_length
			+ x * (list->data.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	sort(t_list * list)
{
	int		i;
	int		j;
	double	tempo;

	i = 0;
	j = 1;
	if (list->sprites[0] == -1)
		return (0);
	while (list->sprites[i] != -1)
	{
		while (list->sprites[j] != -1)
		{
			if (list->sprites[j] < list->sprites[i])
			{
				tempo = list->sprites[i];
				list->sprites[i] = list->sprites[j];
				list->sprites[j] = tempo;
				tempo = list->texturecolumn[i];
				list->texturecolumn[i] = list->texturecolumn[j];
				list->texturecolumn[j] = tempo;
				i = 0;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}
