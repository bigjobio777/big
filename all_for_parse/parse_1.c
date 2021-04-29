#include "../Libft/libft.h"
#include "../cub3d.h"

int	 max_line(t_list *list)
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
	int	 i = 0;
	int	 j = 0;
	int	 length;
	char	**big;

	big = NULL;
	length = max_line(list);
	while (list->karta[i])
		i++;
	list->max_y = i;
	big = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (list->karta[i])
	{
		big[i] = (char *)malloc(sizeof(char) * (length + 1));
		while ((j < length))
		{
			if (list->karta[i][j])
			{
				big[i][j] = list->karta[i][j];
				j++;
			}
			else 
				while ((j < length))
				{
					big[i][j] = ' ';
					j++;
				}
		}
		big[i][j] = '\0';
		j = 0;
		i++;
	}
	big[i] = NULL;
	return (big);
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
void	all_line(char *line)
{
	int	 i;
	int	 length;

	i = 0;
	length = ft_strlen(line);
	if (line[0] != ' ' && line[0] != '1')
		print_error(-50);
	if (length > 1 && line[length-1] != ' ' && line[length-1] != '1')
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
	int	 i;
	int	 j;
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