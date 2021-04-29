#include "Libft/libft.h"
#include "cub3d.h"
#include <math.h>

void	find_pos_x_y(t_list *list)
{
	int	 i;
	int	 j;

	i = 0;
	j = 0;
	while (list->karta[i])
	{
		while (list->karta[i][j])
		{
			if (list->karta[i][j] == 'E' || list->karta[i][j] == 'N')
			{
				list->pos_x = j + 0.5;
				list->pos_y = i + 0.5;
			}
			else if (list->karta[i][j] == 'W' || list->karta[i][j] == 'S')
			{
				list->pos_x = j + 0.5;
				list->pos_y = i + 0.5;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
void	angle_maker(t_list *list)
{
	if (list->playes_location == 'E')
		list->pos_angle = 0;
	else if (list->playes_location == 'N')
		list->pos_angle = M_PI / 2;
	else if (list->playes_location == 'W')
		list->pos_angle = M_PI;
	else if (list->playes_location == 'S')
		list->pos_angle =(3 * M_PI) / 2;
	find_pos_x_y(list);
}