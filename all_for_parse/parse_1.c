#include "../Libft/libft.h"
#include "../cub3d.h"

int	max_line(t_list *list)
{
	int	 i;
	int	 max;
	int	 j;

	i = 0;
	j = 0;
	max = 0;
	while (list->karta[i])
	{
		while (list->karta[i][j])
			j++;
		if (max < j)
			max = j;
		j = 0;
		i++;
	}
	list->max_x = max;
	return (max);
}

char	**check_map(t_list *list)
{
	list->length = max_line(list);
	while (list->karta[list->i])
		list->i++;
	help_parse1(list);
	while (list->karta[list->i])
	{
		list->tempo[list->i] = (char *)malloc(sizeof(char)
				* (list->length + 1));
		while ((list->j < list->length))
		{
			if (list->karta[list->i][list->j])
			{
				list->tempo[list->i][list->j] = list->karta[list->i][list->j];
				list->j++;
			}
			else
				while ((list->j < list->length))
					list->tempo[list->i][list->j++] = ' ';
		}
		list->tempo[list->i++][list->j] = '\0';
		list->j = 0;
	}
	list->tempo[list->i] = NULL;
	free(list->karta);
	return (list->tempo);
}

void	all_line(char *line)
{
	int	 i;
	int	 length;

	i = 0;
	length = ft_strlen(line);
	if (line[0] != ' ' && line[0] != '1')
		print_error(-50);
	if (length > 1 && line[length - 1] != ' ' && line[length - 1] != '1')
		print_error(-50);
}

void	first_line(char *line, t_list *list)
{
	int	 i;

	i = 0;
	if (list->bil_1 == 0)
	{
		while (line[i])
		{
			if (line[i] != ' ' && line[i] != '1')
				print_error(-49);
			i++;
		}
	}
}

void	parse_1(char *line, t_list *list)
{
	int		i;
	int		j;
	char	*testline;

	i = 0;
	j = 0;
	testline = ft_strjoin("", "");
	if ((line[i] == ' ' || line[i] == '1') && line[i])
	{
		first_line(line, list);
		all_line(line);
		list->bil_1 = 1;
		while ((availeble_simvol(line[i])) && line[i])
		{
			check_player(line[i], list);
			testline = ft_strjoinchr(testline, line[i]);
			i++;
		}
		if (line[i] == '\0')
			list->karta = big_massiv(list->karta, testline);
		else
			print_error(-45);
	}
}
