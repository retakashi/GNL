/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:59:13 by rtakashi          #+#    #+#             */
/*   Updated: 2023/02/16 23:12:40 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 10

// ssize_t read(int fd, void *buf(読み出したデータを格納するバッファの先頭アドレス),
//		size_t N(読み込む最大バイト数));
// return 0< 読み込んだバイト数 0=EOF -1=error

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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ans;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ans = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (ans == NULL)
		return (NULL);
	ft_strlcpy(ans, s1, s1_len + 1);
	ft_strlcpy(ans + s1_len, s2, s2_len + 1);
	return (ans);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if (c == '\0')
		return (&str[i]);
	return (NULL);
}

char	*get_line(char *line)
{
	char	*str;
	size_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_buf(char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i] != '\n')
		i++;
	i++;
	ft_strlcpy(buf, buf + i, ft_strlen(buf));
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE+1];
	char		*line;
	ssize_t		read_num;

	line = (char *)malloc(sizeof(char) * 1);
	line[0] = '\0';
	if (ft_strchr(buf, '\n'))
	{
		get_buf(buf);
		printf("get_buf=%s\n", buf);
		line = ft_strjoin(line, buf);
		printf("line=%s\n", line);
	}
	read_num=1;
	while (read_num>0 && !ft_strchr(buf, '\n'))
	{
		read_num = read(fd, buf, BUFFER_SIZE);
		printf("read_num=%zd\n", read_num);
		if (read_num < 0)
	{
		free(buf);
		return (NULL);
	}
		if (read_num < 1)
		{
			if()
			printf("buf0=%s\n", buf);
			printf("line0=%s\n", line);
			return(NULL);
		}
		buf[read_num] = '\0';
		printf("buf=%s\n", buf);
		line = ft_strjoin(line, buf);
		printf("line=%s\n", line);
	}
	printf("get_line=%s\n", get_line(line));
	return (get_line(line));
}

// int	main(int argc, char const *argv[])
// {
// 	char *str;
// 	int fd;

// 	if (argc == 1)
// 		fd = 0;
// 	else
// 	{
// 		fd = open(argv[1], O_RDONLY);
// 		if (fd == -1)
// 			return (0);
// 	}
// 	while (1)
// 	{
// 		str = get_next_line(fd);
// 		printf("str=%s\n", str);
// 		if (!str)
// 			break ;
// 		free(str);
// 	}
// 	close(fd);
// 	// system("leaks -q a.out");
// 	return (0);
// }


int	main(void)
{
	char *str;
	int fd;

	fd = open("text", O_RDONLY);
	if (fd == -1)
		return (0);
	while (1)
	{
		str = get_next_line(fd);
		printf("str=%s\n", str);
		if (!str)
			break ;
		free(str);
	}
	close(fd);
	// system("leaks -q a.out");
	return (0);
}