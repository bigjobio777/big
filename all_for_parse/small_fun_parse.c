/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_fun_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfines <tfines>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:01:59 by bigjobio          #+#    #+#             */
/*   Updated: 2021/05/25 22:52:52 by tfines           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../cub3d.h"

void	check_karta2(t_list *list)
{
	int	 i;
	int	 j;
	int	 length_x;
	int	 length_y;

	i = 0;
	j = 0;
	length_y = 0;
	length_x = 0;
	length_x = ft_strlen(list->karta[0]);
	while (list->karta[length_y])
		length_y++;
	while (j < (length_y -1))
	{
		while (i < (length_x - 1))
		{
			if (list->karta[j][i] == '1')
				i = length_x;
			else if (list->karta[j][i] != ' ' && list->karta[j][i])
				print_error(list, -52);
			i++;
		}
		i = 0;
		j++;
	}
}

void	check_player(char c, t_list *list)
{
	if (c == 'E' || c == 'S' || c == 'N' || c == 'W')
	{
		if (list->playes_location == 0)
			list->playes_location = c;
		else
			print_error(list, -44);
	}
}

int	availeble_simvol(char c)
{
	if (c == ' ' || c == '1' || c == '2' || c == '0'
		|| c == 'S' || c == 'N' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

char	**big_massiv2(char **karta, char *testline)
{
	char	**big;
	int		i;

	i = 0;
	big = NULL;
	while (karta[i])
		i++;
	big = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (karta[i])
	{
		big[i] = karta[i];
		i++;
	}
	big[i] = ft_strdup(testline);
	i++;
	big[i] = NULL;
	return (big);
}

char	**big_massiv(char **karta, char *testline)
{
	int	 	i;
	char	**big;

	i = 0;
	big = NULL;
	if (karta == NULL)
	{
		big = (char **)malloc(sizeof(char *) * (2));
		big[i] = ft_strdup(testline);
		big[i + 1] = NULL;
	}
	else
	{
		big = big_massiv2(karta, testline);
		free(karta);
		karta = NULL;
	}
	return (big);
}
