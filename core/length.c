/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 09:21:22 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/23 09:21:23 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	check_length(char *str, t_placeholder *place_holder)
{
	int i;

	i = 0;
	if ((i = ft_get_index(str, 'l')) >= 0)
	{
		if (str[i + 1] == 'l')
			place_holder->ll = 1;
		else
			place_holder->l = 1;
	}
	if ((i = ft_get_index(str, 'h')) >= 0)
	{
		if (str[i + 1] == 'h')
			place_holder->hh = 1;
		else
			place_holder->h = 1;
	}
}
