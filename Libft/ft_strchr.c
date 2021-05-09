/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strchr.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tfines <tfines@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/11/14 19:42:51 by tfines			#+#	#+#			 */
/*   Updated: 2020/11/22 20:07:08 by tfines		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)\
{
	return (ft_memchr(s, c, ft_strlen(s) + 1));
}