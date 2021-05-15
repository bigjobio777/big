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
		tempo = (double *)malloc(sizeof(double) * (i + 2));
		i = -1;
		while (list->sprites[++i] != -1)
			tempo[i] = list->sprites[i];
		tempo[i++] = distance;
		tempo[i] = -1;
		free(list->sprites);
	}
	return (tempo);
}

double		*sprites_1(t_list *list, double x, double y, double tempo)
{
	double	distance;
	distance = sqrt(((x - list->pos_x) * (x - list->pos_x)) + ((y - list->pos_y) * (y - list->pos_y)));
	double b = asin((y - list->pos_y)/ distance);
	if (list->pos_x > x)
		b = -b;
	b += M_PI;
	list->texturecolumn[0] = distance * tan(tempo - b);
	list->sprites = map_sprites(list, distance);
	return (NULL);
}
