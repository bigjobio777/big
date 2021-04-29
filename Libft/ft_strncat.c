/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strncat.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tfines <tfines@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/11/14 19:38:02 by tfines			#+#	#+#			 */
/*   Updated: 2020/11/23 18:16:28 by tfines		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned	int	i;
	unsigned	int	j;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (j < n && s2[j])
	{
		s1[i] = s2[j];
		i++;
		++j;
	}
	s1[i] = '\0';
	return (s1);
}
