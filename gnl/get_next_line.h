/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.h									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bigjobio <bigjobio@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/01/17 16:26:34 by tfines			#+#	#+#			 */
/*   Updated: 2021/03/20 22:27:58 by bigjobio		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUFFER_SIZE 10

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcpy(char *dest, char const *src);
int		get_next_line(int const fd, char **line);
size_t	ft_strlen(const char *s);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);

#endif
