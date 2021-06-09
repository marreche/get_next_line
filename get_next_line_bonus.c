/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marreche <marreche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:11:45 by marreche          #+#    #+#             */
/*   Updated: 2021/06/09 12:22:56 by marreche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

static char	*clean(char *s, char **line, int r)
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			break ;
		i++;
	}
	if (i < ft_strlen(s))
	{
		*line = ft_substr(s, 0, i);
		tmp = ft_substr(s, i + 1, ft_strlen(s));
		free(s);
		s = ft_strdup(tmp);
		free(tmp);
	}
	else if (r == 0)
	{
		*line = s;
		s = NULL;
	}
	return (s);
}

static char	*ft_temp(char *s, char *buff)
{
	char	*temp;

	temp = ft_strjoin(s, buff);
	free(s);
	s = temp;
	return (s);
}

int	get_next_line(int fd, char **line)
{
	static char	*s[MAX_FD];
	char		buff[BUFFER_SIZE + 1];
	int			r;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (ERROR);
	r = read(fd, buff, BUFFER_SIZE);
	while (r > 0)
	{
		buff[r] = '\0';
		s[fd] = ft_temp(s[fd], buff);
		if (ft_strchr(s[fd], '\n'))
			break ;
		r = read(fd, buff, BUFFER_SIZE);
	}
	if (r <= 0 && !s[fd])
	{
		*line = ft_strdup("");
		return (r);
	}
	s[fd] = clean(s[fd], line, r);
	if (r <= 0 && !s[fd])
		return (r);
	return (SUCCESS);
}
