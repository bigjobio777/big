/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strlcat.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tfines <tfines@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/11/19 22:26:49 by tfines			#+#	#+#			 */
/*   Updated: 2020/11/23 18:19:11 by tfines		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ln_src;
	size_t	ln_dst;

	ln_dst = ft_strlen(dst);
	ln_src = ft_strlen(src);
	if (dstsize <= ln_dst)
		return (ln_src + dstsize);
	if (ln_src < (dstsize - ln_dst))
		ft_strncat(dst, src, ln_src + 1);
	else
	{
		ft_strncat(dst, src, dstsize - ln_dst - 1);
		dst[dstsize - 1] = '\0';
	}
	return (ln_dst + ln_src);
}
