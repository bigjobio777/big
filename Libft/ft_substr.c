/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_substr.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tfines <tfines@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/11/15 17:59:26 by tfines			#+#	#+#			 */
/*   Updated: 2020/11/24 19:26:44 by tfines		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub_str;

	i = 0;
	if (!s)
		return (NULL);
	sub_str = (char*)(malloc(sizeof(char) * (len + 1)));
	if (!sub_str)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
	{
		*(sub_str + i) = '\0';
		return (sub_str);
	}
	while (i < len)
	{
		*(sub_str + i) = *(s + start + i);
		i++;
	}
	*(sub_str + i) = '\0';
	return (sub_str);
}
