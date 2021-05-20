#include "libft.h"
#include "cub3d.h"

void	col_north(t_list *list, double visota, double walld, int stolbec)
{
	char	*col;

	col = (char *)list->tnorth.addr + (int)(list->k / visota * list->tnorth.y)
		* list->tnorth.line_length
		+ (int)(walld * (list->tnorth.x))
		* (list->tnorth.bits_per_pixel / 8);
	my_mlx_pixel_put(list, stolbec, list->i, *(unsigned int *)col);
	list->i++;
	list->k++;
}

void	col_south(t_list *list, double visota, double walld, int stolbec)
{
	char	*col;

	col = (char *)list->tsouth.addr + (int)(list->k / visota * list->tsouth.y)
			* list->tsouth.line_length
			+ (int)(walld * list->tsouth.x)
			* (list->tsouth.bits_per_pixel / 8);
	my_mlx_pixel_put(list, stolbec, list->i, *(unsigned int *)col);
	list->i++;
	list->k++;
}

void	col_west(t_list *list, double visota, double walld, int stolbec)
{
	char	*col;

	col = (char *)list->twest.addr
				+ (int)(list->k / visota * list->twest.y)
				* list->twest.line_length
				+ (int)(walld * list->twest.x)
				* (list->twest.bits_per_pixel / 8);
	my_mlx_pixel_put(list, stolbec, list->i, *(unsigned int *)col);
	list->i++;
	list->k++;
}

void	col_east(t_list *list, double visota, double walld, int stolbec)
{
	char	*col;

	col = (char *)list->teast.addr
				+ (int)(list->k / visota * list->teast.y)
				* list->teast.line_length + (int)(walld * list->teast.x)
				* (list->teast.bits_per_pixel / 8);
	my_mlx_pixel_put(list, stolbec, list->i, *(unsigned int *)col);
	list->i++;
	list->k++;
}