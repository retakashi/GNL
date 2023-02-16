/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:05:47 by rtakashi          #+#    #+#             */
/*   Updated: 2023/02/16 17:58:31 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen(src);
	i = 0;
	while (src[i] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
	{
		dst[i] = '\0';
	}
	return (srclen);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ans = (char *)malloc(sizeof(char)*(s1_len + s2_len + 1));
	if (ans == NULL)
		return (NULL);
	ft_strlcpy(ans, s1, s1_len + 1);
	ft_strlcpy(ans + s1_len, s2, s2_len + 1);
	return (ans);
}

int	main(void)
{
	int		fd;
	char	*line;
	char	*str;
	int a;

	fd = open("./text", O_RDONLY);
	line=malloc(sizeof(char)*(10));
	// a=read(fd,line,5);
	// printf("read= %d\n",a);
	// printf("reads= %s\n",line);
	a=1;
	str="";
	while (a!=0)
	{
		a=read(fd,line,5);
		line[a]='\0';
		str=ft_strjoin(str,line);
		printf("read= %d\n",a);
		printf("str= %s\n",str);
	printf("reads= %s\n",line);
	}
	printf("aaa= %s", line);
	return (0);
}
