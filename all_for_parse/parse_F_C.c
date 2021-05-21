/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_F_C.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigjobio <bigjobio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:01:48 by bigjobio          #+#    #+#             */
/*   Updated: 2021/05/21 17:01:50 by bigjobio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../cub3d.h"

int	check_digit(char *line, int *i)
{
	int	 digit;

	digit = 0;
	if (line[0] == 'F')
	{
		help_parse_f(line, i, &digit);
	}
	else
	{
		if (!ft_isdigit(line[*i]))
			print_error(-25);
		else
		{
			digit = ft_atoi(&line[*i]);
			while (ft_isdigit(line[*i]))
				(*i)++;
		}
	}
	return (digit);
}

void	test(char *line, t_list *list)
{
	int	 i;

	i = 0;
	if (list->floor_red != (-1))
		print_error(-28);
	while (line[i] == ' ' && line[0] == ' ')
		i++;
	list->floor_red = check_digit(line, &i);
	while (line[i] == ' ')
		i++;
	if (line[i++] != ',')
		print_error(-26);
	while (line[i] == ' ')
		i++;
	list->floor_green = check_digit(line, &i);
	while (line[i] == ' ')
		i++;
	if (line[i++] != ',')
		print_error(-26);
	while (line[i] == ' ')
		i++;
	list->floor_blue = check_digit(line, &i);
	help_parse_f2(line, i);
}

void	test2(char *line, t_list *list)
{
	int	 i;

	i = 0;
	if (list->ceiling_red != (-1))
		print_error(-30);
	while (line[i] == ' ' && line[0] == ' ')
		i++;
	list->ceiling_red = check_digit(line, &i);
	while (line[i] == ' ')
		i++;
	if (line[i++] != ',')
		print_error(-31);
	while (line[i] == ' ')
		i++;
	list->ceiling_green = check_digit(line, &i);
	while (line[i] == ' ')
		i++;
	if (line[i++] != ',')
		print_error(-31);
	while (line[i] == ' ')
		i++;
	list->ceiling_blue = check_digit(line, &i);
	help_parse_f3(line, i);
}

void	parse_F(char *line, t_list *list)
{
	char	**checker;

	test((line + 1), list);
	checker = ft_split((line + 1), ',');
	if (checker[0] == NULL || checker[1] == NULL || checker[2] == NULL)
		print_error(-40);
	mem_uni_killer(checker);
	if (list->floor_red < 0 || list->floor_red > 255)
		print_error(-29);
	if (list->floor_green < 0 || list->floor_green > 255)
		print_error(-29);
	if (list->floor_blue < 0 || list->floor_blue > 255)
		print_error(-29);
}

void	parse_C(char *line, t_list *list)
{
	char	**checker;

	test2((line + 1), list);
	checker = ft_split((line + 1), ',');
	if (checker[0] == NULL || checker[1] == NULL || checker[2] == NULL)
		print_error(-41);
	mem_uni_killer(checker);
	if (list->ceiling_red < 0 || list->ceiling_red > 255)
		print_error(-29);
	if (list->ceiling_green < 0 || list->ceiling_green > 255)
		print_error(-29);
	if (list->ceiling_blue < 0 || list->ceiling_blue > 255)
		print_error(-29);
}
