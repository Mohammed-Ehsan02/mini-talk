/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 13:53:05 by mkhan             #+#    #+#             */
/*   Updated: 2022/07/16 19:39:34 by mkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free(char *str, char *s)
{
	free(s);
	free(str);
	return (NULL);
}

char	*ft_readline(int fd, char *s, size_t buff)
{
	char	*str;
	int		i;

	i = 1;
	str = (char *)malloc(buff + 1);
	if (!str)
		return (NULL);
	while (i != 0 && !ft_strchr(s, '\n'))
	{
		i = read(fd, str, buff);
		if (i == -1)
		{
			free(str);
			return (NULL);
		}
		str[i] = '\0';
		s = ft_gnl_strjoin(s, str);
	}
	if (s[0] == '\0')
	{
		ft_free(str, s);
		return (NULL);
	}
	free (str);
	return (s);
}

char	*ft_currentline(char *str)
{
	char	*s;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	s = (char *)malloc(i + 2);
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_newline(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	s = (char *)malloc(ft_strlen(str) - i + 1);
	if (!s)
		return (NULL);
	i++;
	while (str[i])
		s[j++] = str[i++];
	s[j] = '\0';
	free (str);
	return (s);
}

char	*get_next_line_bonus(int fd)
{
	static char	*str[256];
	char		*s;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 256)
		return (NULL);
	str[fd] = ft_readline(fd, str[fd], BUFFER_SIZE);
	if (!str[fd])
		return (NULL);
	s = ft_currentline(str[fd]);
	str[fd] = ft_newline(str[fd]);
	return (s);
}
