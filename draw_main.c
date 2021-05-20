#include "Libft/libft.h"
#include "cub3d.h"
#include "mlx/mlx.h"

void	drawimage_help2(t_list *list, double *x, double *y)
{
	if ((*(y) < list->max_y && *(y) >= 0) && (*(x) >= 0 && *(x) < list->max_x)
		&& list->karta[(int)*(y)][(int)*(x)] != '1'
			&& list->karta[(int)*(y)][(int)*(x)] != '2')
	{
		list->pos_x = *(x);
		list->pos_y = *(y);
	}
	cast_rays(list);
	mlx_do_sync(list->mlx.mlx);
	mlx_put_image_to_window(list->mlx.mlx, list->mlx.mlx_win,
		list->data.img, 0, 0);
	mlx_do_sync(list->mlx.mlx);
}

void	drawimage_help(t_list *list, double *x, double *y)
{
	if (list->key_pressed[W] == 1)
	{
		*(x) += (cos(list->pos_angle) * STEP_PLAYER);
		*(y) += (sin(list->pos_angle) * STEP_PLAYER);
	}
	if (list->key_pressed[S] == 1)
	{
		*(x) -= (cos(list->pos_angle) * STEP_PLAYER);
		*(y) -= (sin(list->pos_angle) * STEP_PLAYER);
	}
	if (list->key_pressed[A] == 1)
	{
		*(x) += (STEP_PLAYER * cos(list->pos_angle + (M_PI / 2)));
		*(y) += (STEP_PLAYER * sin(list->pos_angle + (M_PI / 2)));
	}
	if (list->key_pressed[D] == 1)
	{
		*(x) += (STEP_PLAYER * cos(list->pos_angle - (M_PI / 2)));
		*(y) += (STEP_PLAYER * sin(list->pos_angle - (M_PI / 2)));
	}
}

int	drawimage(t_list *list)
{
	double		x;
	double		y;

	x = list->pos_x;
	y = list->pos_y;
	if (list->key_pressed[LEFT] == 1)
	{	
		list->pos_angle += STEP;
		if (list->pos_angle >= 2 * M_PI)
			list->pos_angle -= 2 * M_PI;
		else if (list->pos_angle < 0)
			list->pos_angle += 2 * M_PI;
	}
	if (list->key_pressed[RIGHT] == 1)
	{
		list->pos_angle -= STEP;
		if (list->pos_angle >= 2 * M_PI)
			list->pos_angle -= 2 * M_PI;
		else if (list->pos_angle < 0)
			list->pos_angle += 2 * M_PI;
	}
	drawimage_help(list, &x, &y);
	drawimage_help2(list, &x, &y);
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
	mlx_get_screen_size(list->mlx.mlx, &list->max_xx, &list->max_yy);
	check_size(list);
	list->tnorth.img = mlx_error(mlx_xpm_file_to_image(list->mlx.mlx,
				list->tnorth.file, &list->tnorth.x, &list->tnorth.y));
	list->tnorth.addr = mlx_error(mlx_get_data_addr(list->tnorth.img,
				&list->tnorth.bits_per_pixel, &list->tnorth.line_length,
				&list->tnorth.endian));
	list->tsouth.img = mlx_error(mlx_xpm_file_to_image(list->mlx.mlx,
				list->tsouth.file, &list->tsouth.x,
				&list->tsouth.y));
	list->tsouth.addr = mlx_error(mlx_get_data_addr(list->tsouth.img,
				&list->tsouth.bits_per_pixel,
				&list->tsouth.line_length, &list->tsouth.endian));
	list->teast.img = mlx_error(mlx_xpm_file_to_image(list->mlx.mlx,
				list->teast.file, &list->teast.x, &list->teast.y));
	mlx_starter2(list);
}
