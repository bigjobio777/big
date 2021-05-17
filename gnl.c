#include "Libft/libft.h"
#include "cub3d.h"

void	parse_line_help(char *line, t_list *list)
{
	if (list->bil_1 == 1 && line[0] != ' ' && line[0] != '1' && line[0])
		print_error(-43);
	else if (list->bil_1 == 1 && line[0] == '\0')
		print_error(-48);
}

int	parse_line(char *line, t_list *list)
{
	if (line[0] == '\0')
		return (0);
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
		print_error(-46);
	return (0);
}

void	gnl_help(t_list *list, char *line)
{
	parse_line(line, list);
	last_line_map(line);
	free(line);
	check_all(list);
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

	errors(argc, argv);
	errors2(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == (-1))
	{
		printf("%s", strerror(errno));
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
	return (0);
}
