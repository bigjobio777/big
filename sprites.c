#include "Libft/libft.h"
#include "cub3d.h"

double		*map_sprites(t_list *list, double distance)
{
	double		*tempo;
	int			i;

	i = 0;
	if (list->sprites[0] == -1)
	{
		tempo = (double *)malloc(sizeof(double) * 2);
		tempo[0] = distance;
		tempo[1] = -1;
		free(list->sprites);
	}
	else
	{
		while (list->sprites[i] != -1)
			i++;
		tempo = (double *)malloc(sizeof(double) * (i + 1));
		i = 0;
		while (list->sprites[i] != -1)
		{
			tempo[i] = list->sprites[i];
			i++;
		}
		tempo[i] = -1;
		free(list->sprites);
	}
	return (tempo);
}

double		*sprites_1(t_list *list, int x, int y)
{
	double	distance;

	distance = sqrt(((x + 0.5 - list->pos_x) * (x + 0.5 - list->pos_x)) + ((y + 0.5 - list->pos_y) * (y + 0.5 - list->pos_y)));
	list->sprites = map_sprites(list, distance);
	return (NULL);
}

double		*sprites_2(t_list *list, int x, int y)
{
	double	distance;

	distance = sqrt(((list->pos_x - x - 0.5) * (list->pos_x - x - 0.5)) + ((y + 0.5 - list->pos_y) * (y + 0.5 - list->pos_y)));
	list->sprites = map_sprites(list, distance);
	return (NULL);
}

double		*sprites_3(t_list *list, int x, int y)
{
	double	distance;

	distance = sqrt(((list->pos_x - x - 0.5) * (list->pos_x - x - 0.5)) + ((list->pos_y - y + 0.5) * ((list->pos_y - y + 0.5))));
	list->sprites = map_sprites(list, distance);
	return (NULL);
}

double		*sprites_4(t_list *list, int x, int y)
{
	double	distance;

	distance = sqrt(((x + 0.5 - list->pos_x) * (x + 0.5 - list->pos_x)) + ((list->pos_y - y + 0.5) * (list->pos_y - y + 0.5)));
	list->sprites = map_sprites(list, distance);
	return (NULL);
}


