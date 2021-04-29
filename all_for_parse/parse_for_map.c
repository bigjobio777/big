#include "../Libft/libft.h"
#include "../cub3d.h"

void	check_all(t_list *list)
{
	if (list->r_x == 0 || list->path_to_south == NULL || list->path_to_north == NULL ||
	list->path_to_west == NULL || list->path_to_east == NULL || list->path_to_sprite == NULL ||
	list->floor_red == (-1) || list->ceiling_red == (-1) || list->karta == NULL || list->playes_location == 0)
		print_error(-47);
}
void	parse_r(t_list *list, char **big)
{
	int	 i;
	int	 j;

	j = 0;
	i = 1;
	if (list->r_x != 0)
		print_error(-13);
	if (big[3] != NULL)
		print_error(-14);
	if (big[1] == NULL || big[2] == NULL)
		print_error(-39);
	while (i < 3)
	{
		j = 0;
		while (big[i][j])
		{
			if (!(ft_isdigit(big[i][j])))
				print_error(-4);
			j++;
		}
		if (i == 1)
			list->r_x = ft_atoi(big[i]);
		else if(i == 2)
			list->r_y = ft_atoi(big[i]);
		i++;
	}
}

void	parse_NO_SO(t_list *list, char **big)
{
	if (ft_strcmp(big[0], "NO"))
	{
	if (big[2] != NULL)
		print_error(-20);
	if (big[1] == NULL)
		print_error(-34);
	if (list->path_to_north != NULL)
		print_error(-15);
	list->path_to_north = ft_strdup(big[1]);
	}
	else 
	{
		if (big[2] != NULL)
			print_error(-19);
		if (big[1] == NULL)
			print_error(-35);
		if (list->path_to_south != NULL)
			print_error(-16);
		list->path_to_south = ft_strdup(big[1]);
	}
}

void	parse_WE_EA(t_list *list, char **big)
{
	if (ft_strcmp(big[0], "WE"))
	{
	if (big[2] != NULL)
		print_error(-18);
	if (big[1] == NULL)
			print_error(-36);
	if (list->path_to_west != NULL)
		print_error(-17);
	list->path_to_west = ft_strdup(big[1]);
	}
	else
	{
		if (big[2] != NULL)
		print_error(-21);
	if (big[1] == NULL)
			print_error(-37);
	if (list->path_to_east != NULL)
		print_error(-22);
	list->path_to_east = ft_strdup(big[1]);
	}
}

void	parse_S(t_list *list, char **big)
{
	if (big[2] != NULL)
		print_error(-23);
	if (big[1] == NULL)
			print_error(-38);
	if (list->path_to_sprite != NULL)
		print_error(-24);
	list->path_to_sprite = ft_strdup(big[1]);
}