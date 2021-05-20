#include "Libft/libft.h"
#include "cub3d.h"

void	check_size(t_list *list)
{
	if (list->r_x > list->max_xx)
		list->r_x = list->max_xx;
	if (list->r_y > list->max_yy)
		list->r_y = list->max_yy;
}

double	*map_sprites(t_list *list, double distance)
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

double	*map_texturecolumn(t_list *list, double distance
				, double b, double tempo)
{
	double		*tempos;
	int			i;

	i = 0;
	if (list->texturecolumn[0] == -1)
	{
		tempos = (double *)malloc(sizeof(double) * 2);
		tempos[i++] = distance * tan(tempo - b);
		tempos[i] = -1;
		free(list->texturecolumn);
	}
	else
	{
		while (list->texturecolumn[i] != -1)
			i++;
		tempos = (double *)malloc(sizeof(double) * (i + 2));
		i = -1;
		while (list->texturecolumn[++i] != -1)
			tempos[i] = list->texturecolumn[i];
		tempos[i++] = distance * tan(tempo - b);
		tempos[i] = -1;
		free(list->texturecolumn);
	}
	list->max_sprite = i - 1;
	return (tempos);
}

double	*sprites(t_list *list, double x, double y, double tempo)
{
	double	distance;
	double	b;

	distance = sqrt(((x - list->pos_x) * (x - list->pos_x))
			+ ((y - list->pos_y) * (y - list->pos_y)));
	b = asin((y - list->pos_y) / distance);
	if (list->pos_x > x)
		b = -b;
	b += M_PI;
	list->texturecolumn = map_texturecolumn(list, distance, b, tempo);
	list->sprites = map_sprites(list, distance);
	return (NULL);
}
