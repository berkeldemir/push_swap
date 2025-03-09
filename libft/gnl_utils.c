/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 00:29:43 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/10 00:35:15 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./gnl.h"

int	gnl_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*gnl_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[gnl_strlen(s)]);
	c = (unsigned char)c;
	while (*s != c && *s != 0)
		s++;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

static char	*gnl_zerostr(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	int		i;
	char	*res;

	if (!s1)
		s1 = gnl_zerostr();
	if (!s1)
		return (NULL);
	if (!s2)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	while (s2[i - gnl_strlen(s1)])
	{
		res[i] = s2[i - gnl_strlen(s1)];
		i++;
	}
	free(s1);
	res[i] = '\0';
	return (res);
}
