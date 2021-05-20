/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tfines <tfines@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/01/17 16:26:22 by tfines			#+#	#+#			 */
/*   Updated: 2021/01/17 16:26:39 by tfines		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"

void	help_gnl2(char *p_n, int *byte_was_read, int fd, char *buf)
{
	if (!p_n)
		*(byte_was_read) = read(fd, buf, BUFFER_SIZE);
}

void	help_gnl(char *vremennaya, char **ostatok)
{
	free(vremennaya);
	free(*ostatok);
	*ostatok = NULL;
}

int	ft_test(char **remainder, char *p_n)
{
	if (*remainder || p_n)
	{
		return (1);
	}
	else
	{
		free(*remainder);
		*remainder = NULL;
		return (0);
	}
}

char	*check_remainder(char **ostatok, char **line)
{
	char	*p_n;
	char	*vremennaya;

	*line = ft_strjoin("", "");
	p_n = NULL;
	if (*ostatok)
	{
		p_n = ft_strchr(*ostatok, '\n');
		if (p_n)
		{
			*p_n = '\0';
			vremennaya = *line;
			*line = ft_strjoin(*line, *ostatok);
			free(vremennaya);
			vremennaya = *ostatok;
			*ostatok = ft_strjoin("", ++p_n);
			free(vremennaya);
			return (p_n);
		}
		vremennaya = *line;
		*line = ft_strjoin("", *ostatok);
		help_gnl(vremennaya, ostatok);
	}
	return (NULL);
}

int	get_next_line(int fd, char **line)
{
	static char		*ostatok;
	char			buf[BUFFER_SIZE + 1];
	int				byte_was_read;
	char			*p_n;
	char			*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || !(line) || read(fd, buf, 0) == (-1))
		return (-1);
	p_n = check_remainder(&ostatok, line);
	help_gnl2(p_n, &byte_was_read, fd, buf);
	while (!p_n && byte_was_read)
	{
		buf[byte_was_read] = '\0';
		p_n = help_gnl3(p_n, buf, tmp, &ostatok);
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		if (!*line)
			return (-1);
		free(tmp);
		help_gnl2(p_n, &byte_was_read, fd, buf);
	}
	return (ft_test(&ostatok, p_n));
}
