#include "../Libft/libft.h"
#include "../cub3d.h"

void	clean_tempo(t_list *list)
{
	list->i = 0;
	list->j = 0;
	list->tempo = NULL;
	list->length = 0;
	free(list->tempo);
}

void	last_line_map(char *line)
{
	int	 i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1')
			print_error(-51);
		i++;
	}
}

char	**make_karta(t_list *list)
{
	int	 	i;
	int	 	j;
	int	 	length_y;
	int	 	length_x;
	char	**karta;

	i = 0;
	j = -1;
	length_x = 0;
	length_y = 0;
	while (list->karta[length_y])
		length_y++;
	karta = (char **)malloc(sizeof(char *) * (length_y + 2));
	length_x = max_line(list);
	while (--length_y >= 0)
	{
		karta[i] = (char *)malloc(sizeof(char) * (length_x + 1));
		while ((++j < length_x))
			karta[i][j] = list->karta[length_y][j];
		karta[i++][j] = '\0';
		j = -1;
	}
	karta[i] = NULL;
	int  d = 0;
	while (list->karta[d])
	{
		free(list->karta[d]);
		d++;
	}
	free(list->karta);
	return (karta);
}

void	check_karta4(t_list *list)
{
	int	 i;
	int	 length_x;
	int	 length_y;

	length_y = 0;
	length_x = (ft_strlen(list->karta[0]) - 1);
	while (list->karta[length_y])
		length_y++;
	i = length_y - 1;
	length_y--;
	while (length_x >= 0)
	{
		while (length_y >= 0)
		{
			if (list->karta[length_y][length_x] == '1')
				length_y = (-1);
			else if (list->karta[length_y][length_x] != ' '
					&& list->karta[length_y][length_x])
				print_error(-52);
			length_y--;
		}
		length_y = i;
		length_x--;
	}
}

void	check_karta3(t_list *list)
{
	int	 i;
	int	 j;
	int	 length_x;
	int	 length_y;

	i = 0;
	j = 0;
	length_y = 0;
	length_x = 0;
	length_x = ft_strlen(list->karta[0]);
	while (list->karta[length_y])
		length_y++;
	while (i < (length_x -1))
	{
		while (j < (length_y - 1))
		{
			if (list->karta[j][i] == '1' || list->karta[j][i] == ' ')
				list->h = 1;
			if (list->karta[j][i] == '1')
				j = length_y;
			else if (list->karta[j][i] != ' ' && list->karta[j][i])
				print_error(-52);
			j++;
		}
		j = 0;
		i++;
	}
}
