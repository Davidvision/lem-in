/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_get_hole.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 22:41:39 by hklein            #+#    #+#             */
/*   Updated: 2019/02/14 22:41:41 by hklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_hole	*get_hole(char *name, t_hole *holes)
{
	t_hole	*buf;

	buf = holes;
	while (buf && ft_strcmp(buf->name, name))
		buf = buf->next;
	return (buf);
}
