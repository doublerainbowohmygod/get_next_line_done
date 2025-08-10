/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:06:41 by aoneil            #+#    #+#             */
/*   Updated: 2025/08/10 17:15:57 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_loop(int fd, char *reminder, char *buffer)
{
	char	*tmp;
	ssize_t	bytes;

	while (!ft_strchr(reminder, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buffer), free(reminder), reminder = NULL, NULL);
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		tmp = reminder;
		reminder = ft_strjoin(tmp, buffer);
		free(tmp);
		if (!reminder)
			return (free(buffer), NULL);
	}
	return (reminder);
}

char	*ft_read_line(int fd, char *reminder)
{
	char		*buffer;

	buffer = NULL;
	if (!reminder)
		reminder = ft_strdup("");
	if (!reminder)
		return (free(buffer), NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(reminder), NULL);
	reminder = ft_read_loop(fd, reminder, buffer);
	free (buffer);
	if (reminder[0] == '\0')
		return (free(reminder), reminder = NULL, NULL);
	return (reminder);
}

char	*cut_reminder(char *s)
{
	char	*nl;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] == '\0' || s[i + 1] == '\0')
		return (NULL);
	nl = ft_strdup(&s[i + 1]);
	s[i + 1] = '\0';
	return (nl);
}

char	*get_next_line(int fd)
{
	static char	*reminder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (reminder)
			free (reminder);
		reminder = NULL;
		return (NULL);
	}
	line = ft_read_line(fd, reminder);
	if (!line)
		return (NULL);
	reminder = cut_reminder(line);
	return (line);
}
