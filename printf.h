/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:00:59 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/17 13:01:01 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>

typedef struct		s_placeholder
{
	int	width;
	int precision;
	int length;
	int	minus;
	int plus;
	int	space;
	int zero;
	int hash;
	int asterisk;
	int	length_print;
	int hh;
	int h;
	int l;
	int ll;
	int error;
}					t_placeholder;

/*
** core
*/

int					ft_printf(const char *str, ...);
void				dispatch_to_type(char *str, t_placeholder *ph, va_list *vl);
void				check_flags(char *str, t_placeholder *ph, va_list *vl);
void				check_length(char *str, t_placeholder *place_holder);
uintmax_t			get_nb_u(va_list *vl, t_placeholder *place_holder);
intmax_t			get_nb(va_list *vl, t_placeholder *place_holder);

/*
** display
*/

void				display_c(t_placeholder *ph, va_list *vl);
void				display_s(t_placeholder *ph, va_list *vl);
void				display_p(t_placeholder *ph, va_list *vl);
void				display_d_i(t_placeholder *ph, va_list *vl);
void				display_x(t_placeholder *ph, va_list *vl, int upp);
void				display_u(t_placeholder *ph, va_list *vl);
void				display_percent(t_placeholder *ph);
char				*helper_precision(t_placeholder *ph, char *str, int neg);
void				helper_minus(int width, char *str, char *disp);
void				helper_disp_width(t_placeholder *ph, char *str, int neg);

/*
** utils
*/

char				*add_zero_front(char *str, int n);
void				fill_space(char *str, int len);
void				fill_zero(char *str, int len);
int					ft_get_index(char *str, char c);
char				*ft_itoa_base(long n, int base, int upp);
long				ft_pow_long(long n, long power);
int					ft_pow(int n, int power);
void				ft_strrev(char *str);
char				*itoa_spec(intmax_t n);
char				*itoa_spec_u_base(uintmax_t n, int base, int upp);
char				*itoa_spec_u(uintmax_t num);
void				put_str_char(char *str, char c, int way);

#endif
