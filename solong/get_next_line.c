/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkasmi <abkasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:04:54 by abkasmi           #+#    #+#             */
/*   Updated: 2022/03/26 13:19:35 by abkasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			ret;
	static char	*str;
	char		*buff;
	int			pos;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	pos = ft_strchr(str);
	buff = NULL;
	while (pos == -1)
	{
		buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buff)
			return (NULL);
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret <= 0)
		{
			ft_free(&buff);
			break ;
		}
		str = ft_strnjoin(str, buff, ret);
		pos = ft_strchr(str);
		ft_free(&buff);
	}
	return (return_value(&str, pos, ret));
}

char	*return_value(char **str, int pos, int ret)
{
	char	*str2;

	if (!*str && ret <= 0)
		return (0);
	str2 = NULL;
	if (pos == -1)
		pos = ft_strlen(*str);
	else
		pos++;
	str2 = ft_strndup(*str, pos);
	if (pos == ft_strlen(*str))
		ft_free(str);
	else
	{
		*str = ft_get_after_nl(str, pos);
	}
	return (str2);
}

char	*ft_strndup(char *s1, int n)
{
	char	*ptr;
	int		i;

	ptr = malloc(sizeof(char) * (n + 1));
	if (!ptr)
		return (NULL);
	i = -1;
	while (++i < n)
		ptr[i] = s1[i];
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_get_after_nl(char **str, int pos)
{
	char	*str2;

	str2 = ft_strndup(&(*str)[pos], ft_strlen(*str) - pos);
	ft_free(str);
	return (str2);
}

void	ft_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}
