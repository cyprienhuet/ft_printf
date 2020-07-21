/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:36:53 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/09 09:37:00 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	if (!ft_strlen(s))
		return (0);
	count = 1;
	while (i < (int)ft_strlen(s))
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] == c)
				i++;
		}
		i++;
	}
	return (count);
}

static int	ft_len_split(const char *str, char c)
{
	int i;

	i = 0;
	while (*str && *str != c)
	{
		i++;
		str++;
	}
	return (i);
}

static void	*free_str(char **str)
{
	char	*temp;
	int		i;

	i = 0;
	while (str[i])
	{
		temp = str[i];
		free(temp);
		temp = NULL;
		i++;
	}
	free(str);
	str = NULL;
	return (0);
}

char		**ft_split(const char *s, char c)
{
	char	**str;
	int		i;
	int		count_words;
	int		j;

	if (!s)
		return (0);
	count_words = ft_count_words(ft_strtrim(s, &c), c);
	if (!(str = ((char **)malloc(sizeof(*str) * (count_words + 1)))))
		return (0);
	j = 0;
	while (count_words-- > 0)
	{
		while (*s && *s == c)
			s++;
		i = ft_len_split(s, c);
		if (!(str[j] = ft_substr(s, 0, i)))
			return (free_str(str));
		s = s + i;
		j++;
	}
	str[j] = 0;
	return (str);
}
