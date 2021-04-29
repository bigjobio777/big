/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_atoi.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tfines <tfines@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/11/07 17:18:29 by tfines			#+#	#+#			 */
/*   Updated: 2020/11/23 21:28:20 by tfines		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

static	int		first_ind(char *s)
{
	int		i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\v' ||
			s[i] == '\t' || s[i] == '\r' || s[i] == '\f')
		i++;
	return (i);
}

int				ft_atoi(const char *str)
{
	int					i;
	long long	int		rez;
	long long	int		new_rez;
	int					sign;

	sign = 1;
	rez = 0;
	i = first_ind((char *)str);
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		new_rez = rez * 10 + str[i++] - '0';
		if (rez > new_rez)
			return (sign == -1 ? 0 : -1);
		rez = new_rez;
	}
	return ((int)rez * sign);
}
