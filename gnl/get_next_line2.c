/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigjobio <bigjobio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:31:21 by bigjobio          #+#    #+#             */
/*   Updated: 2021/05/18 20:33:15 by bigjobio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*help_gnl3(char *p_n, char *buf, char *tmp, char **ostatok)
{
	char	*p_n2;

	p_n2 = ft_strjoin("", p_n);
	p_n2 = ft_strchr(buf, '\n');
	if (p_n2)
	{
		*p_n2 = '\0';
		tmp = *ostatok;
		*ostatok = ft_strjoin("", ++p_n2);
		free(tmp);
	}
	return (p_n2);
}
