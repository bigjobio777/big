/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_isalpha.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tfines <tfines@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/11/05 21:13:37 by tfines			#+#	#+#			 */
/*   Updated: 2020/11/22 20:20:30 by tfines		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	return (0);
}
