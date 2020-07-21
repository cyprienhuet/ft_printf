/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_zero_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:42:45 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/17 12:42:46 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

char	*add_zero_front(char *str, int n)
{
	int		i;
	char	*ret;

	if (!(ret = (char *)malloc(sizeof(*ret) * (n + 1))))
		return (0);
	i = 0;
	while (i < n - (int)ft_strlen(str))
		ret[i++] = '0';
	while (*str)
		ret[i++] = *str++;
	ret[i] = '\0';
	return (ret);
}
