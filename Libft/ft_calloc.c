/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_calloc----------.c							  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tfines <tfines@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/11/15 17:42:04 by tfines			#+#	#+#			 */
/*   Updated: 2020/11/22 20:26:44 by tfines		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == 0)
		return (NULL);
	ptr = ft_memset(ptr, 0, count * size);
	return (ptr);
}
