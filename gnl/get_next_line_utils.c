/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line_utils.c							  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tfines <tfines@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/01/17 16:26:29 by tfines			#+#	#+#			 */
/*   Updated: 2021/01/17 16:52:48 by tfines		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	size_t			len_s1;
	size_t			len_s2;
	size_t			i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char*)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i - len_s1 < len_s2)
	{
		str[i] = s2[i - len_s1];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_strcpy(char *dest, char const *src)
{
	int				i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t		ft_strlen(const char *s)
{
	size_t			i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*area;
	unsigned char	chr;
	size_t			i;

	area = (unsigned char*)s;
	chr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (area[i] == chr)
			return ((void*)(s + i));
		i++;
	}
	return (NULL);
}

char		*ft_strchr(const char *s, int c)
{
	return (ft_memchr(s, c, ft_strlen(s) + 1));
}
