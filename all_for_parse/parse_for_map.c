/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_for_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfines <tfines>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:01:54 by bigjobio          #+#    #+#             */
/*   Updated: 2021/05/25 22:52:39 by tfines           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../cub3d.h"

void	check_all(t_list *list)
{
	if (list->r_x == 0 || list->tsouth.file == NULL
		|| list->tnorth.file == NULL
		|| list->twest.file == NULL || list->teast.file == NULL
		|| list->tsprite.file == NULL
		|| list->floor_red == (-1) || list->ceiling_red == (-1)
		|| list->karta == NULL || list->playes_location == 0)
		print_error(list, -47);
}

void	parse_r(t_list *list, char **big)
{
	int	 i;
	int	 j;

	i = 1;
	if (list->r_x != 0)
		print_error(list, -13);
	if (big[3] != NULL)
		print_error(list, -14);
	if (big[1] == NULL || big[2] == NULL)
		print_error(list, -39);
	while (i < 3)
	{
		j = 0;
		while (big[i][j])
		{
			if (!(ft_isdigit(big[i][j])))
				print_error(list, -4);
			j++;
		}
		if (i == 1)
			make_r_x_y(list, big, 1);
		else if (i == 2)
			make_r_x_y(list, big, 2);
		i++;
	}
}

void	parse_NO_SO(t_list *list, char **big)
{
	if (!ft_strcmp(big[0], "NO"))
	{
		if (big[2] != NULL)
			print_error(list, -20);
		if (big[1] == NULL)
			print_error(list, -34);
		if (list->tnorth.file != NULL)
			print_error(list, -15);
		list->tnorth.file = ft_strdup(big[1]);
	}
	else if (!ft_strcmp(big[0], "SO"))
	{
		if (big[2] != NULL)
			print_error(list, -19);
		if (big[1] == NULL)
			print_error(list, -35);
		if (list->tsouth.file != NULL)
			print_error(list, -16);
		list->tsouth.file = ft_strdup(big[1]);
	}
}

void	parse_WE_EA(t_list *list, char **big)
{
	if (!ft_strcmp(big[0], "WE"))
	{
		if (big[2] != NULL)
			print_error(list, -18);
		if (big[1] == NULL)
			print_error(list, -36);
		if (list->twest.file != NULL)
			print_error(list, -17);
		list->twest.file = ft_strdup(big[1]);
	}
	else if (!ft_strcmp(big[0], "EA"))
	{
		if (big[2] != NULL)
			print_error(list, -21);
		if (big[1] == NULL)
			print_error(list, -37);
		if (list->teast.file != NULL)
			print_error(list, -22);
		list->teast.file = ft_strdup(big[1]);
	}
}

void	parse_S(t_list *list, char **big)
{
	if (big[2] != NULL)
		print_error(list, -23);
	if (big[1] == NULL)
		print_error(list, -38);
	if (list->tsprite.file != NULL)
		print_error(list, -24);
	list->tsprite.file = ft_strdup(big[1]);
}
