#include "Libft/libft.h"
#include "cub3d.h"
#include "mlx/mlx.h"

void	drawimage_help2(t_list *list)
{
	cast_rays(list);
	mlx_do_sync(list->mlx.mlx);
	mlx_put_image_to_window(list->mlx.mlx, list->mlx.mlx_win, list->data.img, 0, 0);
	mlx_do_sync(list->mlx.mlx);
}

void	drawimage_help(t_list *list, double x, double y)
{
	if (list->key_pressed[W] == 1)
	{
		x += (cos(list->pos_angle) * step_player);
		y += (sin(list->pos_angle) * step_player);
	}
	if (list->key_pressed[S] == 1)
	{
		x -= (cos(list->pos_angle) * step_player);
		y -= (sin(list->pos_angle) * step_player);
	}
	if (list->key_pressed[A] == 1)
	{
		x += (step_player * cos(list->pos_angle + (M_PI / 2)));
		y += (step_player * sin(list->pos_angle + (M_PI / 2)));
	}
	if (list->key_pressed[D] == 1)
	{
		x += (step_player * cos(list->pos_angle - (M_PI / 2)));
		y += (step_player * sin(list->pos_angle - (M_PI / 2)));
	}
	if ((y < list->max_y && y >= 0) && (x >= 0 && x < list->max_x) && list->karta[(int)y][(int)x] != '1' && list->karta[(int)y][(int)x] != '2')
	{
		list->pos_x = x;
		list->pos_y = y;
	}
}
int drawimage(t_list *list)
{
	double		x;
	double		y;

	x = list->pos_x;
	y = list->pos_y;
	if (list->key_pressed[LEFT] == 1)
	{	
		list->pos_angle += step;
		if (list->pos_angle >= 2 * M_PI)
			list->pos_angle -= 2 * M_PI;
		else if (list->pos_angle < 0)
			list->pos_angle += 2 * M_PI;
	}
	if (list->key_pressed[RIGHT] == 1)
	{
		list->pos_angle -= step;
		if (list->pos_angle >= 2 * M_PI)
			list->pos_angle -= 2 * M_PI;
		else if (list->pos_angle < 0)
			list->pos_angle += 2 * M_PI;
	}
	drawimage_help(list, x, y);
	drawimage_help2(list);
	return (0);
}

void	*mlx_error(void *ptr)
{
	if (ptr == NULL)
	{
		print_error(-70);
	}
	return (ptr);
}

void	mlx_starter(t_list *list)
{
	list->mlx.mlx = mlx_error(mlx_init());
	list->tnorth.img = mlx_error(mlx_xpm_file_to_image(list->mlx.mlx, list->tnorth.file, &list->tnorth.x, &list->tnorth.y));
	list->tnorth.addr = (int*)mlx_get_data_addr(list->tnorth.img, &list->tnorth.bits_per_pixel, &list->tnorth.line_length, &list->tnorth.endian);
	list->tsouth.img = mlx_xpm_file_to_image(list->mlx.mlx, list->tsouth.file, &list->tsouth.x, &list->tsouth.y);
	list->tsouth.addr = (int*)mlx_get_data_addr(list->tsouth.img, &list->tsouth.bits_per_pixel, &list->tsouth.line_length, &list->tsouth.endian);
	list->teast.img = mlx_xpm_file_to_image(list->mlx.mlx, list->teast.file, &list->teast.x, &list->teast.y);
	list->teast.addr = (int*)mlx_get_data_addr(list->teast.img, &list->teast.bits_per_pixel, &list->teast.line_length, &list->teast.endian);
	list->twest.img = mlx_xpm_file_to_image(list->mlx.mlx, list->twest.file, &list->twest.x, &list->twest.y);
	list->twest.addr = (int*)mlx_get_data_addr(list->twest.img, &list->twest.bits_per_pixel, &list->twest.line_length, &list->twest.endian);
	list->tsprite.img = mlx_xpm_file_to_image(list->mlx.mlx, list->tsprite.file, &list->tsprite.x, &list->tsprite.y);
	list->tnorth.addr = (int*)mlx_get_data_addr(list->tnorth.img, &list->tnorth.bits_per_pixel, &list->tnorth.line_length, &list->tnorth.endian);
	list->data.img = mlx_new_image(list->mlx.mlx, list->r_x, list->r_y);
	list->data.addr = (int*)mlx_get_data_addr(list->data.img, &list->data.bits_per_pixel, &list->data.line_length, &list->data.endian);
}

int save_bmp(t_list *list)
{
	int		fd;
	fd = open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC, 444);
	int a = 0;
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
	int i;
	int j;
	i = 0;
	cast_rays(list);
	while (i < list->r_y)
	{
		j = 0;
		while (j < list->r_x)
		{
			write(fd, &list->data.addr[i*list->r_x + j], 4);
			j++;
		}
		i++;
	}
	close(fd);
	mlx_destroy_image(list->mlx.mlx, list->data.img);
	return (0);
}

int	 main(int argc, char **argv)
{
	t_list  list;
	
	init_flags(&list);
	gnl(argc, argv, &list);
	mlx_starter(&list);
	if (argc == 3)
	{
		save_bmp(&list);
		exit(0);
	}
	list.mlx.mlx_win = mlx_new_window(list.mlx.mlx, list.r_x, list.r_y, "Cub3D");
	mlx_hook(list.mlx.mlx_win, 02, (1L<<0), key_hook, &list);
	mlx_hook(list.mlx.mlx_win, 17, (1L<<17), key_hook_exit, &list);
	mlx_hook(list.mlx.mlx_win, 03, (1L<<1), key_hook_stop, &list);
	mlx_loop_hook(list.mlx.mlx, drawimage, &list);
	mlx_loop(list.mlx.mlx);
	return (0);
}