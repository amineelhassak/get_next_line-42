/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 01:53:58 by amel-has          #+#    #+#             */
/*   Updated: 2023/11/14 15:37:10 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
		return (0);
	return (ft_strcpy(s2, (char *)s1));
}

static char	*ft_save(char *save, int fd)
{
	char	*line;
	int		readhandl;

	if (!save)
		return (0);
	line = malloc(BUFFER_SIZE + 1);
	if (!line)
		return (0);
	readhandl = 1;
	while (!ft_strchr(save, '\n') && readhandl != 0)
	{
		readhandl = read(fd, line, BUFFER_SIZE);
		if (readhandl == -1)
		{
			free(line);
			return (0);
		}
		line[readhandl] = '\0';
		save = ft_strjoin(save, line);
	}
	free(line);
	return (save);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*save[OPEN_MAX];

	if (fd >= 0 && read(fd, 0, 0) == -1)
	{
		free(save[fd]);
		save[fd] = NULL;
		return (0);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!save[fd])
		save[fd] = ft_strdup("");
	save[fd] = ft_save(save[fd], fd);
	if (!save[fd])
	{
		free(save[fd]);
		return (0);
	}
	line = ft_getline(save[fd]);
	save[fd] = ft_modifie_save(save[fd]);
	return (line);
}
