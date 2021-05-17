#include "../Libft/libft.h"
#include "../cub3d.h"

void	floor_ceiling(t_list *list)
{
	list->floor = list->floor_red * 65536 + list->floor_green * 256 + list->floor_blue;
	list->ceiling = list->ceiling_red * 65536 + list->ceiling_green * 256 + list->ceiling_blue;
}