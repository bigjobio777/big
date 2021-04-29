/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_memmove.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tfines <tfines@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/11/14 19:22:46 by tfines			#+#	#+#			 */
/*   Updated: 2020/11/22 19:56:48 by tfines		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*c_dst;
	unsigned char	*c_src;

	if (!dst && !src)
		return (NULL);
	c_dst = (unsigned char*)dst;
	c_src = (unsigned char*)src;
	if (&c_src[0] > &c_dst[0])
		dst = ft_memcpy(dst, src, len);
	else
		while (len > 0)
		{
			c_dst[len - 1] = c_src[len - 1];
			len--;
		}
	return (dst);
}
