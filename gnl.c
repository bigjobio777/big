#include "Libft/libft.h"
#include "cub3d.h"

int	 parse_line(char *line, t_list *list)
{
	char	**big;

	if (list->bil_1 == 1 && line[0] != ' ' && line[0] != '1' && line[0])
		print_error(-43);
	else if (list->bil_1 == 1 && line[0] == '\0')
		print_error(-48);
	if (line[0] == '\0')
		return (0);
	big = ft_split(line, ' ');
	if (line[0] == ' ' || line[0] == '1')
		parse_1(line, list);
	else if (!(ft_strcmp(big[0], "R")))
		parse_r(list, big);
	else if (!(ft_strcmp(big[0], "NO")))
		parse_NO_SO(list, big);
	else if (!(ft_strcmp(big[0], "SO")))
		parse_NO_SO(list, big);
	else if (!(ft_strcmp(big[0], "WE")))
		parse_WE_EA(list, big);
	else if (!(ft_strcmp(big[0], "EA")))
		parse_WE_EA(list, big);
	else if (!(ft_strcmp(big[0], "S")))
		parse_S(list, big);
	else if (!(ft_strcmp(big[0], "F")))
		parse_F(line, list);
	else if (!(ft_strcmp(big[0], "C")))
		parse_C(line, list);
	else
		print_error(-46);
	return (0);
}
int	gnl(int  argc, char **argv, t_list *list)
{
	int	 fd;
	char	*line;
	int	 test;

	errors(argc, argv);
	errors2(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == (-1))
	{
		printf("%s", strerror(errno));
		exit(1);	
	}
	while ((test = get_next_line(fd, &line)) > 0)
		{
			parse_line(line, list);
			free(line);
		}
	parse_line(line, list);
	last_line_map(line);
	free(line);
	check_all(list);
	list->karta = check_map(list);
	check_karta(list);
	check_karta2(list);
	check_karta3(list);
	check_karta4(list);
	list->karta = make_karta(list);
	angle_maker(list);
	
	return (0);
}