#include "../Libft/libft.h"
#include "../cub3d.h"

char		**make_karta(t_list *list)
{
	int	 i;
	int	 j;
	int	 length_y;
	int	 length_x;
	char	**karta;

	i = 0;
	j = 0;
	length_x = 0;
	length_y = 0;
	while (list->karta[length_y])
		length_y++;
	karta = (char **)malloc(sizeof(char *) * (length_y + 2));
	length_x = max_line(list);
	length_y--;
	while (length_y >= 0)
	{
		karta[i] = (char *)malloc(sizeof(char) * (length_x + 1));
		while ((j < length_x))
		{
			karta[i][j] = list->karta[length_y][j];
			j++;
		}
		karta[i][j] = '\0';
		j = 0;
		length_y--;
		i++;
	}
	karta[i] = NULL;
	return (karta);
}