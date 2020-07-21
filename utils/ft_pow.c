/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:44:04 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/17 12:44:05 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_pow(int n, int power)
{
	if (power == 0)
		return (1);
	else if (power == 1)
		return (n);
	return (n * ft_pow(n, power - 1));
}
