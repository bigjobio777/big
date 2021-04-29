#include "../Libft/libft.h"
#include "../cub3d.h"

void		check_karta4(t_list *list)
{
	int	 i;
	int	 j;
	int	 length_x;
	int	 length_y;

	i = 0;
	j = 0;
	length_y = 0;
	length_x = 0;
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
			else if (list->karta[length_y][length_x] != ' ' && list->karta[length_y][length_x])
				print_error(-52);
			length_y--;
		}
		length_y = i;
		length_x--;
	}
}

void		check_karta3(t_list *list)
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

void		check_karta2(t_list *list)
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
	while (j < (length_y -1))
	{
		while (i < (length_x - 1))
		{
			if (list->karta[j][i] == '1')
				i = length_x;
			else if (list->karta[j][i] != ' ' && list->karta[j][i])
				print_error(-52);
			i++;
		}
		i = 0;
		j++;
	}
}

void		check_karta(t_list *list)
{
	int	 i;
	int	 j;
	int	 length_x;
	int	 length_y;

	i = 1;
	j = 1;
	length_x = 0;
	length_y = 0;
	while (list->karta[length_y])
		length_y++;
	length_x = ft_strlen(list->karta[0]);
	while (j <= (length_y-2))
	{
		while (i <= (length_x-2))
		{
			if ((list->karta[j][i] == ' ' && (list->karta[j - 1][i] != ' ' && list->karta[j - 1][i] != '1')))
				print_error(-52);
			if ((list->karta[j][i] == ' ' && (list->karta[j + 1][i] != ' ' && list->karta[j + 1][i] != '1')))
				print_error(-52);
			if ((list->karta[j][i] == ' ' && (list->karta[j][i + 1] != ' ' && list->karta[j][i + 1] != '1')))
				print_error(-52);
			if ((list->karta[j][i] == ' ' && (list->karta[j][i - 1] != ' ' && list->karta[j][i - 1] != '1')))
				print_error(-52);
			i++;
		}
		i = 1;
		j++;
	}
}
void	 check_player(char c, t_list *list)
{
	if (c == 'E' || c == 'S' || c == 'N' || c == 'W')
	{
		if (list->playes_location == 0)
			list->playes_location = c;
		else
			print_error(-44);
	}
}

int	 availeble_simvol(char c)
{
	if (c == ' ' || c == '1' || c == '2' || c == '0' || c == 'S' || c == 'N' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

char	**big_massiv2(char **karta, char *testline)
{
	char	**big;
	int	 i = 0;

	big = NULL;
	while(karta[i])
		i++;
	big = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (karta[i])
	{
		big[i] = ft_strdup(karta[i]);
		i++;
	}
	big[i] = ft_strdup(testline);
	i++;
	big[i] = NULL;
	return (big);
}

char	**big_massiv(char **karta, char *testline)
{
	int	 i;
	int	 j;
	int	 itog;
	char	**big;

	i = 0;
	j = 0;
	itog = 0;
	big = NULL;
	if (karta == NULL)
	{
		big = (char **)malloc(sizeof(char  *) * (2));
		big[i] = (char *)malloc(sizeof(char) * (ft_strlen(testline) + 1));
		big[i] = testline;
		big[i + 1] = NULL;
	}
	else
	{
		big = big_massiv2(karta, testline);
	}
	return (big);
}

