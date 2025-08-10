/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:07:11 by aoneil            #+#    #+#             */
/*   Updated: 2025/08/07 17:40:45 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000

# endif

// size_t	ft_strlcpy(char *dst, const char *src, size_t size);
// size_t	ft_strlcat(char *dst, const char *src, size_t size);
// void	ft_bzero(void *s, size_t n);
// void	*ft_calloc(size_t nmemb, size_t size);

size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, size_t start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strdup(char *s);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*cut_reminder(char	*line);
char	*ft_read_line(int fd, char *reminder);

#endif