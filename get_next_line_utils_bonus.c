/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:27:54 by rtakashi          #+#    #+#             */
/*   Updated: 2023/02/23 17:00:54 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	srclen = i;
	i = 0;
	while (src[i] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (srclen);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ans;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = (ft_strlen(s1));
	s2_len = (ft_strlen(s2));
	ans = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (ans == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(ans, s1, s1_len + 1);
	ft_strlcpy(ans + s1_len, s2, s2_len + 1);
	free(s1);
	return (ans);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	if (c == '\0')
		return (&s[i]);
	return (NULL);
}
