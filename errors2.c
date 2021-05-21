/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigjobio <bigjobio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 23:22:31 by bigjobio          #+#    #+#             */
/*   Updated: 2021/05/21 10:45:19 by bigjobio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "cub3d.h"

void	print_error4(int numerror)
{
	if (numerror == (-38))
		printf("Error\nin -Sprite- no adress(2th argument)\n");
	else if (numerror == (-39))
		printf("Error\nin -R- not 3 arguments\n");
	else if (numerror == (-40))
		printf("Error\nin -F- not 3 arguments\n");
	else if (numerror == (-41))
		printf("Error\nin -C- not 3 arguments\n");
	else if (numerror == (-42))
		printf("Error\nmap not valid\n");
	else if (numerror == (-43))
		printf("Error\nafter map not end\n");
	else if (numerror == (-44))
		printf("Error\n2 player location on the map\n");
	else if (numerror == (-45))
		printf("Error\nin map bad arguments\n");
	else if (numerror == (-46))
		printf("Error\nFirst argument in map not valid\n");
	else if (numerror == (-47))
		printf("Error\nMissing arguments in map\n");
	else if (numerror == (-48))
		printf("Error\nAfter map empty line\n");
	else if (numerror == (-49))
		printf("Error\nFirst line in map not valid\n");
}

void	print_error5(int numerror)
{
	if (numerror == (-50))
		printf("Error\nMap not start or end with ' ' or '1'\n");
	else if (numerror == (-51))
		printf("Error\nLast line in map not valid\n");
	else if (numerror == (-52))
		printf("Error\nNot valid map\n");
	else if (numerror == (-70))
		printf("Error\nMlx error\n");
}

void	print_error7(int numerror)
{
	if (numerror == (-21))
		printf("Error\nin -EA- arguments more than 2\n");
	else if (numerror == (-22))
		printf("Error\nDuplicate line -EA-\n");
	else if (numerror == (-36))
		printf("Error\nin -WE- no adress(2th argument)\n");
	else if (numerror == (-37))
		printf("Error\nin -EA- no adress(2th argument)\n");
	else if (numerror == (-35))
		printf("Error\nin -SO- no adress(2th argument)\n");
	else if (numerror == (-75))
		printf("Error\nMap not valid\n");
	else if (numerror == (-76))
		printf("Error\nSecond map\n");
}

void	print_error6(int numerror)
{
	if (numerror < (-9) && numerror >= (-20))
		print_error2(numerror);
	else if (numerror < (-22) && numerror >= (-34))
		print_error3(numerror);
	else if (numerror < (-37) && numerror >= (-49))
		print_error4(numerror);
	else if (numerror < (-49) && numerror >= (-70))
		print_error5(numerror);
	else if (numerror == (-21) || numerror == (-22) || numerror == (-36)
		|| numerror == (-37) || numerror == (-35) || numerror == (-75)
		|| numerror == (-76))
		print_error7(numerror);
}
