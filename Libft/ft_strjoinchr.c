/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strjoinchr.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bigjobio <bigjobio@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/03/26 00:21:02 by bigjobio		  #+#	#+#			 */
/*   Updated: 2021/03/28 22:16:56 by bigjobio		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinchr(char *line, char c)
{
	int	 i;
	int	 length;
	char	*big;

	length = 0;
	i = 0;
	length = ft_strlen(line);
	if (!(big = (char *)malloc(sizeof(char)*(length + 2))))
		return (NULL);
	while (i < length)
	{
		big[i] = line[i];
		i++;
	}
	big[i++] = c;
	big[i] = '\0';
	free(line);
	return (big);
}