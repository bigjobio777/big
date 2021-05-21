/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigjobio <bigjobio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:03:51 by bigjobio          #+#    #+#             */
/*   Updated: 2021/05/21 17:03:54 by bigjobio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../cub3d.h"

void	help_parse_f3(char *line, int i)
{
	while (line[i] == ' ')
		i++;
	if (line[i])
		print_error(-32);
}

void	help_parse_f2(char *line, int i)
{
	while (line[i] == ' ')
		i++;
	if (line[i])
		print_error(-27);
}

void	help_parse_f(char *line, int *i, int *digit)
{
	if (!ft_isdigit(line[*i]))
		print_error(-25);
	else
	{
		(*digit) = ft_atoi(&line[*i]);
		while (ft_isdigit(line[*i]))
			(*i)++;
	}
}

void	help_parse1(t_list *list)
{
	list->max_y = list->i;
	list->tempo = (char **)malloc(sizeof(char *) * (list->i + 2));
	list->i = 0;
}

void	floor_ceiling(t_list *list)
{
	list->floor = list->floor_red * 65536
		+ list->floor_green * 256 + list->floor_blue;
	list->ceiling = list->ceiling_red * 65536
		+ list->ceiling_green * 256 + list->ceiling_blue;
}
