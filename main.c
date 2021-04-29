#include "Libft/libft.h"
#include "cub3d.h"
#include "mlx/mlx.h"

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
	if ((y < list->max_y && y >= 0) && (x >= 0 && x < list->max_x) && list->karta[(int)y][((int)(x))] != '1')
	{
		list->pos_x = x;
		list->pos_y = y;
	}
	cast_rays(list);
	mlx_do_sync(list->mlx.mlx);
	mlx_put_image_to_window(list->mlx.mlx, list->mlx.mlx_win, list->data.img, 0, 0);
	return (0);
}

void	mlx_starter(t_list *list)
{
	list->mlx.mlx = mlx_init();
	list->mlx.mlx_win = mlx_new_window(list->mlx.mlx, list->r_x, list->r_y, "Hello world!");
	list->data.img = mlx_new_image(list->mlx.mlx, list->r_x, list->r_y);
	list->data.addr = mlx_get_data_addr(list->data.img, &list->data.bits_per_pixel, &list->data.line_length, &list->data.endian);
	mlx_hook(list->mlx.mlx_win, 02, (1L<<0), key_hook, list);
	mlx_hook(list->mlx.mlx_win, 17, (1L<<17), key_hook_exit, list);
	mlx_hook(list->mlx.mlx_win, 03, (1L<<1), key_hook_stop, list);
	mlx_loop_hook(list->mlx.mlx, drawimage, list);
}

int	 main(int argc, char **argv)
{
	t_list  list;
	
	init_flags(&list);
	gnl(argc, argv, &list);
	mlx_starter(&list);
	mlx_loop(list.mlx.mlx);
	return (0);
}