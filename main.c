#include "Libft/libft.h"
#include "cub3d.h"
#include "mlx/mlx.h"

void	mlx_starter2(t_list *list)
{
	list->teast.addr = mlx_error(mlx_get_data_addr(list->teast.img,
				&list->teast.bits_per_pixel, &list->teast.line_length,
				&list->teast.endian));
	list->twest.img = mlx_error(mlx_xpm_file_to_image(list->mlx.mlx,
				list->twest.file, &list->twest.x, &list->twest.y));
	list->twest.addr = mlx_error(mlx_get_data_addr(list->twest.img,
				&list->twest.bits_per_pixel, &list->twest.line_length,
				&list->twest.endian));
	list->tsprite.img = mlx_error(mlx_xpm_file_to_image(list->mlx.mlx,
				list->tsprite.file, &list->tsprite.x, &list->tsprite.y));
	list->tsprite.addr = mlx_error(mlx_get_data_addr(list->tsprite.img,
				&list->tsprite.bits_per_pixel, &list->tsprite.line_length,
				&list->tsprite.endian));
	list->data.img = mlx_error(mlx_new_image(list->mlx.mlx, list->r_x,
				list->r_y));
	list->data.addr = mlx_error(mlx_get_data_addr(list->data.img,
				&list->data.bits_per_pixel, &list->data.line_length,
				&list->data.endian));
}

void	write_func(t_list *list, int fd)
{
	write(fd, &(unsigned short){0x4d42}, 2);
	write(fd, &(unsigned int){54 + list->r_x * list->r_y * 4}, 4);
	write(fd, &(unsigned short){0}, 2);
	write(fd, &(unsigned short){0}, 2);
	write(fd, &(unsigned int){54}, 4);
	write(fd, &(unsigned int){40}, 4);
	write(fd, &list->r_x, 4);
	write(fd, &list->r_y, 4);
	write(fd, &(unsigned short){1}, 2);
	write(fd, &(unsigned short){32}, 2);
	write(fd, &(unsigned int){0}, 4);
	write(fd, &(unsigned int){0}, 4);
	write(fd, &(unsigned int){0}, 4);
	write(fd, &(unsigned int){0}, 4);
	write(fd, &(unsigned int){0}, 4);
	write(fd, &(unsigned int){0}, 4);
	write(fd, &(unsigned int){0}, 4);
}

int	save_bmp(t_list *list)
{
	int		fd;
	int		i;
	int		j;

	fd = open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC, 444);
	write_func(list, fd);
	i = list->r_y - 1;
	cast_rays(list);
	while (i >= 0)
	{
		j = 0;
		while (j < list->r_x)
		{
			write(fd, list->data.addr
				+ (i * list->data.line_length)
				+ (int)(j * list->data.bits_per_pixel / 8), 4);
			j++;
		}
		i--;
	}
	close(fd);
	mlx_destroy_image(list->mlx.mlx, list->data.img);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list		list;

	init_flags(&list);
	gnl(argc, argv, &list);
	mlx_starter(&list);
	if (argc == 3)
	{
		save_bmp(&list);
		exit(0);
	}
	list.mlx.mlx_win = mlx_new_window(list.mlx.mlx,
			list.r_x, list.r_y, "Cub3D");
	mlx_hook(list.mlx.mlx_win, 02, (1L << 0), key_hook, &list);
	mlx_hook(list.mlx.mlx_win, 17, (1L << 17), key_hook_exit, &list);
	mlx_hook(list.mlx.mlx_win, 03, (1L << 1), key_hook_stop, &list);
	mlx_loop_hook(list.mlx.mlx, drawimage, &list);
	mlx_loop(list.mlx.mlx);
	return (0);
}
