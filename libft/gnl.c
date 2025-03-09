/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:48:28 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/10 00:33:15 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./gnl.h"

static char	*gnl_read(int fd, char *reco)
{
	char	*buff;
	int		retval;

	retval = 1;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (gnl_strchr(reco, '\n') == NULL && retval != 0)
	{
		retval = read(fd, buff, BUFFER_SIZE);
		if (retval == -1)
			return (free(buff), free(reco), NULL);
		buff[retval] = '\0';
		reco = gnl_strjoin(reco, buff);
	}
	free(buff);
	return (reco);
}

static char	*gnl_line(char *reco)
{
	char	*line;
	int		i;
	int		len;

	if (!reco || reco[0] == '\0')
		return (NULL);
	len = 0;
	while (reco[len] != '\0' && reco[len] != '\n')
		len++;
	if (reco[len] == '\0')
		line = (char *)malloc(sizeof(char) * (len + 1));
	else
		line = (char *)malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	i = -1;
	while (reco[++i] != '\0' && reco[i] != '\n')
		line[i] = reco[i];
	if (reco[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*gnl_next(char *reco)
{
	int		i;
	int		j;
	char	*ret;

	if (!reco || reco[0] == '\0')
		return (NULL);
	i = 0;
	while (reco[i] != '\0' && reco[i] != '\n')
		i++;
	if (!reco[i])
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (gnl_strlen(reco) - i));
	if (!ret)
		return (NULL);
	i++;
	j = 0;
	while (reco[i])
		ret[j++] = reco[i++];
	ret[j] = '\0';
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*reco;
	char		*line;
	char		*newr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reco = gnl_read(fd, reco);
	if (!reco)
		return (NULL);
	line = gnl_line(reco);
	newr = gnl_next(reco);
	free(reco);
	reco = newr;
	return (line);
}
