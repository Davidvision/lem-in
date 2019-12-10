/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_init_lm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:11:11 by hklein            #+#    #+#             */
/*   Updated: 2019/02/18 16:12:28 by hklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link		*init_link(void)
{
	t_link	*buf;

	if (!(buf = (t_link*)malloc(sizeof(t_link))))
		return (NULL);
	buf->linked = NULL;
	buf->flow = 0;
	buf->next = NULL;
	return (buf);
}

t_hole		*init_hole(void)
{
	t_hole	*buf;

	if (!(buf = (t_hole*)malloc(sizeof(t_hole))))
		return (NULL);
	buf->name = NULL;
	buf->start = 0;
	buf->marked = 0;
	buf->graph_marked = 0;
	buf->links = NULL;
	buf->next = NULL;
	return (buf);
}

t_lm		*init_lm(void)
{
	t_lm	*lm;

	if (!(lm = (t_lm*)malloc(sizeof(t_lm))))
		return (NULL);
	lm->holes = NULL;
	lm->nodes = NULL;
	lm->opened = NULL;
	lm->start = NULL;
	lm->end = NULL;
	lm->paths = NULL;
	lm->ants = 0;
	lm->mem_ants = 0;
	lm->distribution = NULL;
	lm->ant_lst = NULL;
	lm->end_str = NULL;
	return (lm);
}

void		set_start(t_lm *lm)
{
	t_hole *buf;

	buf = lm->holes;
	while (buf)
	{
		if (buf->start == 1)
			lm->start = buf;
		else if (buf->start == -1)
			lm->end = buf;
		buf = buf->next;
	}
	lm->start->marked = 1;
}
