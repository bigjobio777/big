/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_itoa.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tfines <tfines@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/11/15 18:12:32 by tfines			#+#	#+#			 */
/*   Updated: 2020/11/22 20:49:48 by tfines		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned	int	nbr;
	char			*str;
	int				sign;
	int				size;

	sign = (n < 0 ? 1 : 0);
	str = NULL;
	size = ft_lenint(n);
	nbr = (n < 0 ? -n : n);
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size--] = '\0';
	while (size >= 0)
	{
		str[size] = nbr % 10 + '0';
		nbr = nbr / 10;
		size--;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}
