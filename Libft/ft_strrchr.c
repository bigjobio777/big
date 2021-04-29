/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strrchr.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tfines <tfines@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/11/07 21:46:50 by tfines			#+#	#+#			 */
/*   Updated: 2020/11/24 17:19:24 by tfines		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	*tmp;

	if (c == 0)
		return ((char*)(s + ft_strlen(s)));
	tmp = (char*)s;
	p = NULL;
	while (*tmp)
	{
		if (*tmp == (char)c)
			p = tmp;
		tmp++;
	}
	if (p != NULL)
		return (p);
	return (NULL);
}
