/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:27:34 by rtakashi          #+#    #+#             */
/*   Updated: 2023/02/23 15:36:16 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_line(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\n')
		i++;
	ft_strlcpy(line, line, i + 1);
	return (line);
}

static char	*get_buf(char *buf)
{
	size_t	i;

	if (!ft_strchr(buf, '\n'))
		return (buf);
	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	i++;
	ft_strlcpy(buf, buf + i, ft_strlen(buf));
	return (buf);
}

static char	*readnum_under(ssize_t read_num, char *buf, char *line)
{
	if (read_num < 0)
		return (NULL);
	if (line != NULL)
	{
		buf[0] = '\0';
		return (line);
	}
	else
		return (line);
}

static char	*buf_readjoin(char *buf, char *line, int fd)
{
	ssize_t	read_num;

	read_num = 1;
	if (buf[0] != '\0')
	{
		line = ft_strjoin(line, buf);
		if (line == NULL)
			return (NULL);
	}
	while (read_num > 0 && !ft_strchr(buf, '\n'))
	{
		read_num = read(fd, buf, BUFFER_SIZE);
		if (read_num < 1)
			return (readnum_under(read_num, buf, line));
		buf[read_num] = '\0';
		line = ft_strjoin(line, buf);
		if (line == NULL)
			return (NULL);
	}
	return (get_line(line));
}

char	*get_next_line(int fd)
{
	static char	buf[OPEN_MAX + 1][BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE > SIZE_MAX)
		return (NULL);
	line = NULL;
	if (ft_strchr(buf[fd], '\n'))
	{
		line = ft_strjoin(line, buf[fd]);
		if (line == NULL)
			return (NULL);
		get_buf(buf[fd]);
		return (get_line(line));
	}
	line = buf_readjoin(buf[fd], line, fd);
	get_buf(buf[fd]);
	return (line);
}

#include <stdio.h>
int    main(void)
{
    int        fd;
    int        fd_2;
    char    *get_line;

    fd = open("text", O_RDONLY);
    fd_2 = open("text2", O_RDONLY);
    get_line=get_next_line(fd);
    printf("%s", get_line);
    free(get_line);

    get_line=get_next_line(fd_2);
    printf("%s", get_line);
    free(get_line);

    get_line=get_next_line(fd);
    printf("%s", get_line);
    free(get_line);
    close(fd);
    close(fd_2);
    return (0);
}
