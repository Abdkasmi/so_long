/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkasmi <abkasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:06:21 by abkasmi           #+#    #+#             */
/*   Updated: 2022/03/26 12:03:33 by abkasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * (size * nmemb));
	if (!str)
		return (NULL);
	while (str && i < (nmemb * size))
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

int	ft_strchr(const char *s)
{
	int				i;
	char			*str;

	if (!s)
		return (-1);
	str = (char *)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, int n)
{
	char		*cpy;
	const char	*str;
	int			i;

	if (!dest && !src)
		return (NULL);
	cpy = (char *)dest;
	str = (const char *)src;
	i = 0;
	while (i < n)
	{
		cpy[i] = str[i];
		i++;
	}
	return (dest);
}

char	*ft_strnjoin(char *s1, char *s2, int n)
{
	int		lg_s1;
	int		lg_s2;
	int		lgtot;
	char	*nv_str;

	if (!s1)
		lg_s1 = 0;
	else
		lg_s1 = ft_strlen(s1);
	lg_s2 = n;
	lgtot = lg_s1 + lg_s2;
	nv_str = (char *)malloc(sizeof(char) * (lgtot + 1));
	if (!nv_str)
		return (NULL);
	ft_memcpy(nv_str, s1, lg_s1);
	if (s1)
		free((void *)s1);
	ft_memcpy(nv_str + lg_s1, s2, lg_s2);
	nv_str[lgtot] = '\0';
	return (nv_str);
}
