/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfines <tfines>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 23:22:39 by bigjobio          #+#    #+#             */
/*   Updated: 2021/05/25 22:57:14 by tfines           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "cub3d.h"

void	clash_royale(t_list *list, char *line)
{
	int		d;

	d = 0;
	while (list->tempo[d])
	{
		free(list->tempo[d]);
		d++;
	}
	free(list->tempo);
	list->tempo = 0;
	free(list->lastline);
	list->lastline = NULL;
	list->lastline = ft_strdup(line);
}

void	parse_line_help(char *line, t_list *list)
{
	if (list->bil_1 == 1 && line[0] != ' ' && line[0] != '1' && line[0])
		print_error(list, -43);
	else if (list->bil_1 == 1 && line[0] == '\0')
		print_error(list, -48);
}

int	parse_line(char *line, t_list *list)
{
	if (line[0] == '\0')
		return (clash(list, line));
	list->tempo = ft_split(line, ' ');
	if (line[0] == ' ' || line[0] == '1')
		parse_1(line, list);
	else if (!(ft_strcmp(list->tempo[0], "R")))
		parse_r(list, list->tempo);
	else if (!(ft_strcmp(list->tempo[0], "NO")))
		parse_NO_SO(list, list->tempo);
	else if (!(ft_strcmp(list->tempo[0], "SO")))
		parse_NO_SO(list, list->tempo);
	else if (!(ft_strcmp(list->tempo[0], "WE")))
		parse_WE_EA(list, list->tempo);
	else if (!(ft_strcmp(list->tempo[0], "EA")))
		parse_WE_EA(list, list->tempo);
	else if (!(ft_strcmp(list->tempo[0], "S")))
		parse_S(list, list->tempo);
	else if (!(ft_strcmp(list->tempo[0], "F")))
		parse_F(line, list);
	else if (!(ft_strcmp(list->tempo[0], "C")))
		parse_C(line, list);
	else
		print_error(list, -46);
	clash_royale(list, line);
	return (0);
}

void	gnl_help(t_list *list, char *line)
{
	parse_line(line, list);
	last_line_map(list, line);
	free(line);
	check_all(list);
	free(list->tempo);
	list->tempo = 0;
	list->karta = check_map(list);
	clean_tempo(list);
	check_karta(list);
	check_karta2(list);
	check_karta3(list);
	check_karta4(list);
	list->karta = make_karta(list);
	angle_maker(list);
	floor_ceiling(list);
}

int	gnl(int argc, char **argv, t_list *list)
{
	int		fd;
	char	*line;
	int		test;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	list->second_fd = fd;
	if (fd == (-1))
	{
		mem_free_list(list);
		printf("%s\n", strerror(errno));
		exit(1);
	}
	test = get_next_line(fd, &line);
	while (test > 0)
	{
		parse_line(line, list);
		free(line);
		test = get_next_line(fd, &line);
	}
	gnl_help(list, line);
	close(fd);
	return (0);
}
