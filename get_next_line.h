/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:07:11 by aoneil            #+#    #+#             */
/*   Updated: 2025/08/10 17:23:18 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000

# endif

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char *s);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*cut_reminder(char	*line);
char	*ft_read_line(int fd, char *reminder);
char	*ft_read_loop(int fd, char *reminder, char *buffer);

#endif