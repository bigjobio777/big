#include "../Libft/libft.h"
#include "../cub3d.h"

void		check_karta_help(t_list *list, int i, int j)
{
	if ((list->karta[j][i] == ' ' && (list->karta[j - 1][i] != ' ' && list->karta[j - 1][i] != '1')))
		print_error(-52);
	if ((list->karta[j][i] == ' ' && (list->karta[j + 1][i] != ' ' && list->karta[j + 1][i] != '1')))
		print_error(-52);
	if ((list->karta[j][i] == ' ' && (list->karta[j][i + 1] != ' ' && list->karta[j][i + 1] != '1')))
		print_error(-52);
	if ((list->karta[j][i] == ' ' && (list->karta[j][i - 1] != ' ' && list->karta[j][i - 1] != '1')))
		print_error(-52);
}
void		check_karta(t_list *list)
{
	int	 i;
	int	 j;
	int	 length_x;
	int	 length_y;

	i = 1;
	j = 1;
	length_x = 0;
	length_y = 0;
	while (list->karta[length_y])
		length_y++;
	length_x = ft_strlen(list->karta[0]);
	while (j <= (length_y-2))
	{
		while (i <= (length_x-2))
		{
			check_karta_help(list, i, j);
			i++;
		}
		i = 1;
		j++;
	}
}