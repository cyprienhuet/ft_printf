/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:42:52 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/17 12:42:53 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_space(char *str, int len)
{
	while (len--)
		*str++ = ' ';
	*str = '\0';
}