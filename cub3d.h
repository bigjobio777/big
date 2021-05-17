/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   cub3d.h											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bigjobio <bigjobio@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/03/14 18:48:01 by bigjobio		  #+#	#+#			 */
/*   Updated: 2021/04/06 17:24:51 by bigjobio		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include "gnl/get_next_line.h"
# include <math.h>
# include "Libft/libft.h"

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define STEP_PLAYER 0.01
# define EAST 0x000000
# define SOUTH 0xFFFFFF
# define NORTH 0xFF0000
# define WEST 0x00FF00
# define STEP 0.01
typedef struct s_texture
{
	int		x;
	int		y;
	void	*img;
	char	*file;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_texture;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
}				t_mlx;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
typedef struct s_list
{
	int	 		r_x;
	int			r_y;
	t_texture	tnorth;
	t_texture	tsouth;
	t_texture	twest;
	t_texture	teast;
	t_texture	tsprite;
	int			floor_red;
	int			floor_green;
	int			floor_blue;
	int			ceiling_red;
	int			ceiling_green;
	int			ceiling_blue;
	int			max_map;
	int			help_mas;
	int			bil_1;
	char		playes_location;
	double		*sprites;
	double		*texturecolumn;
	char		**karta;
	double		pos_x;
	double		pos_y;
	double		pos_angle;
	double		FOV;
	int			max_x;
	double		focus;
	char		key_pressed[127];
	int			max_y;
	t_mlx		mlx;
	t_data		data;
	int			i;
	int			j;
	int			length;
	char		**tempo;
	double		wall_distancex;
	double		wall_distancey;
	int			unused;
	int			max_sprite;
	long		floor;
	long		ceiling;
}					t_list;
void	print_error(int numerror);
void	errors(int argc, char **argv);
void	errors2(int argc, char **argv);
void	init_flags(t_list *big);
int		gnl(int argc, char **argv, t_list *list);
void	parse_r(t_list *list, char **big);
void	parse_NO_SO(t_list *list, char **big);
void	parse_WE_EA(t_list *list, char **big);
void	parse_S(t_list *list, char **big);
void	parse_F(char *line, t_list *list);
void	parse_C(char *line, t_list *list);
void	parse_1(char *line, t_list *list);
void	check_player(char c, t_list *list);
int		availeble_simvol(char c);
char	**big_massiv(char **karta, char *testline);
void	check_all(t_list *list);
void	last_line_map(char *line);
char	**check_map(t_list *list);
void	check_karta(t_list *list);
void	check_karta2(t_list *list);
void	check_karta3(t_list *list);
void	check_karta4(t_list *list);
void	image(t_list *list);
int		touch_key(int keycode, t_list *list);
void	cast_rays(t_list *list);
void	angle_maker(t_list *list);
int		max_line(t_list *list);
char	**make_karta(t_list *list);
void	stolbec(t_list *list, int stolbec, double dist, double walldistance, int color);
void	my_mlx_pixel_put(t_list *list, int x, int y, long color);
int		key_hook_stop(int keycode, t_list *list);
int		key_hook_exit(int	keycode, t_list *list);
int		key_hook(int keycode, t_list *list);
double	*sprites(t_list *list, double x, double y, double tempo);
int		sort(t_list *list);
void	clean_tempo(t_list *list);
double	cast_ray_x_3(t_list *list, double tempo);
double	cast_ray_y_3(t_list *list, double tempo);
double	cast_ray_x_4(t_list *list, double tempo);
double	cast_ray_y_4(t_list *list, double tempo);
double	cast_ray_x_1(t_list *list, double tempo);
double	cast_ray_y_1(t_list *list, double tempo);
double	cast_ray_x_2(t_list *list, double tempo);
double	cast_ray_y_2(t_list *list, double tempo);
void	first_quatre(t_list *list, double tempo, int i);
void	second_quatre(t_list *list, double tempo, int i);
void	third_quatre(t_list *list, double tempo, int i);
void	fouth_quatre(t_list *list, double tempo, int i);
void	drawimage_help2(t_list *list, double *x, double *y);
void	drawimage_help(t_list *list, double *x, double *y);
int		drawimage(t_list *list);
void	*mlx_error(void *ptr);
void	mlx_starter(t_list *list);
void	mlx_starter2(t_list *list);
void	print_error4(int numerror);
void	print_error5(int numerror);
void	print_error6(int numerror);
void	print_error3(int numerror);
void	print_error2(int numerror);
void	floor_ceiling(t_list *list);
void	help_parse1(t_list *list);
void	help_parse_f(char *line, int *i, int *digit);
void	help_parse_f2(char *line, int i);
void	help_parse_f3(char *line, int i);
#endif