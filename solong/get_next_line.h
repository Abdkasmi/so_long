/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkasmi <abkasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:04:43 by abkasmi           #+#    #+#             */
/*   Updated: 2022/03/26 13:48:46 by abkasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
int		ft_strchr(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
char	*return_value(char **str, int pos, int ret);
void	ft_free(char **ptr);
char	*ft_strndup(char *s1, int n);
char	*ft_strtrim(char **str, int pos);
char	*ft_strnjoin(char *s1, char *s2, int n);
void	*ft_memcpy(void *dest, const void *src, int size);
char	*ft_get_after_nl(char **str, int pos);

#endif
