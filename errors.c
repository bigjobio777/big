/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigjobio <bigjobio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 23:22:24 by bigjobio          #+#    #+#             */
/*   Updated: 2021/05/21 23:20:32 by bigjobio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "cub3d.h"

void	print_error3(int numerror)
{
	if (numerror == (-23))
		printf("Error\nin -Sprite- arguments more than 2\n");
	else if (numerror == (-24))
		printf("Error\nDuplicate line -Sprite-\n");
	else if (numerror == (-25))
		printf("Error\nNot digit arguments in -F-\n");
	else if (numerror == (-26))
		printf("Error\nNot dot in -F-\n");
	else if (numerror == (-27))
		printf("Error\nline -F- haven't end line\n");
	else if (numerror == (-28))
		printf("Error\nDuplicate line -F-\n");
	else if (numerror == (-29))
		printf("Error\ncolors in -F- or -C- more 255 or lower than 1\n");
	else if (numerror == (-30))
		printf("Error\nDuplicate line -C-\n");
	else if (numerror == (-31))
		printf("Error\nNot dot in -C-\n");
	else if (numerror == (-32))
		printf("Error\nline -C- haven't end line\n");
	else if (numerror == (-33))
		printf("Error\nNot digit arguments in -C-\n");
	else if (numerror == (-34))
		printf("Error\nin -NO- no adress(2th argument)\n");
}

void	print_error2(int numerror)
{
	if (numerror == (-10))
		printf("Error\nAfter F not digit\n");
	else if (numerror == (-11))
		printf("Error\nin F more digits than 3\n");
	else if (numerror == (-12))
		printf("Error\nError arguments in F\n");
	else if (numerror == (-13))
		printf("Error\nDuplicate line -R-\n");
	else if (numerror == (-14))
		printf("Error\nArguments in -R- more than 2\n");
	else if (numerror == (-15))
		printf("Error\nDuplicate line -NO-\n");
	else if (numerror == (-16))
		printf("Error\nDuplicate line -SO-\n");
	else if (numerror == (-17))
		printf("Error\nDuplicate line -WE-\n");
	else if (numerror == (-18))
		printf("Error\nin -WE- arguments more than 2\n");
	else if (numerror == (-19))
		printf("Error\nin -SO- arguments more than 2\n");
	else if (numerror == (-20))
		printf("Error\nin -NO- arguments more than 2\n");
}

void	print_error(int numerror)
{
	if (numerror == (-1))
		printf("Error\nNumbers of arguments wrong\n");
	else if (numerror == (-2))
		printf("Error\nFile not end with .cub\n");
	else if (numerror == (-3))
		printf("Error\n3th argument not '--save'\n");
	else if (numerror == (-4))
		printf("Error\nNot valid integer in R\n");
	else if (numerror == (-5))
		printf("Error\nNot path to texture for NORTH in 2th argument\n");
	else if (numerror == (-6))
		printf("Error\nNot path to texture for SOUTH in 2th argument\n");
	else if (numerror == (-7))
		printf("Error\nNot path to texture for WEST in 2th argument\n");
	else if (numerror == (-8))
		printf("Error\nNot path to texture for EAST in 2th argument\n");
	else if (numerror == (-9))
		printf("Error\nNot path to texture for SPRITE in 2th argument\n");
	else if (numerror <= (-10) && numerror >= (-76))
		print_error6(numerror);
	else if (numerror == (-71))
		printf("Error\nSecond Map\n");
	exit(1);
}

void	errors(int argc, char **argv)
{
	int	 length;

	length = 0;
	if (argc > 3 || argc < 2)
		print_error(-1);
	length = ft_strlen(argv[1]);
	if (argc == 2)
	{
		if (length > 4)
		{
			if (ft_strcmp(&argv[1][length - 4], ".cub"))
				print_error(-2);
		}
		else
			print_error(-1);
	}
}

void	errors2(int argc, char **argv)
{
	int	 length;

	length = ft_strlen(argv[1]);
	if (argc == 3)
	{
		if (length > 4)
		{
			if (ft_strcmp(&argv[1][length - 4], ".cub"))
				print_error(-2);
		}
		else
			print_error(-2);
		if (ft_strcmp(argv[2], "--save"))
			print_error(-3);
	}
}
