/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strjoinchr.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tfines <tfines@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/03/26 00:21:02 by tfines		  #+#	#+#			 */
/*   Updated: 2021/03/28 22:16:56 by tfines		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinchr(char *line, char c)
{
	int		i;
	int		length;
	char	*big;

	length = 0;
	i = 0;
	length = ft_strlen(line);
	big = (char *)malloc(sizeof(char) * (length + 2));
	if (big == NULL)
		return (NULL);
	while (i < length)
	{
		big[i] = line[i];
		i++;
	}
	big[i++] = c;
	big[i] = '\0';
	free(line);
	line = NULL;
	return (big);
}
