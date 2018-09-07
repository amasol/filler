/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 12:43:49 by amasol            #+#    #+#             */
/*   Updated: 2018/09/07 12:43:50 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_fl
{
	char		*len;
	char		my_o;
	char 		bot_x;
	int			map_x;
	int 		map_y;
	int			fd;
}				t_fl;

int				main(void);
int				parsing(t_fl *inf);
int				pars_line(t_fl *inf);
int				pars_map(t_fl *inf);
void 			zero_out(t_fl *inf);

#endif
