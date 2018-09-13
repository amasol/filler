/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newlink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 02:11:30 by klut              #+#    #+#             */
/*   Updated: 2016/12/21 03:57:34 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_newlink(t_list *list, void *content)
{
	t_list	*linkinf;

	if (!(linkinf = malloc(sizeof(t_list))))
		return (NULL);
	if (linkinf)
	{
		linkinf->content = content;
		linkinf->next = list;
	}
	return (linkinf);
}
