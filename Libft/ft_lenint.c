/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lenint.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tfines <tfines@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/11/19 22:33:45 by tfines			#+#	#+#			 */
/*   Updated: 2020/11/23 18:12:11 by tfines		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

int		ft_lenint(int nbr)
{
	int		len;

	len = 0;
	len = (nbr <= 0 ? 1 : 0);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}
