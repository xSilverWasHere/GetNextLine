/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-g <jpedro-g@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:24:39 by jpedro-g          #+#    #+#             */
/*   Updated: 2025/05/23 11:24:43 by jpedro-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	c = (unsigned char) c;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	n;
	char	*s3;

	i = 0;
	n = 0;
	s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	while (s1 && s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2 && s2[n])
	{
		s3[i + n] = s2[n];
		n++;
	}
	s3[i + n] = '\0';
	return (s3);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strndup(const char *s, size_t len)
{
	char	*str;
	int		i;
	size_t	s_len;

	s_len = ft_strlen(s);
	i = 0;
	if (len >= s_len)
		return (NULL);
	str = malloc((s_len - len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[len])
	{
		str[i] = s[len];
		i++;
		len++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;
	int		l;

	i = 0;
	l = ft_strlen(s);
	str = malloc ((l + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (i < l)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
