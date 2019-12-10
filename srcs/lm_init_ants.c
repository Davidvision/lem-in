/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_init_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arumpler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 18:26:11 by arumpler          #+#    #+#             */
/*   Updated: 2019/02/25 21:29:28 by hklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		add_ant(t_lm *lm, t_path *path)
{
	t_ants	*tmp;
	t_ants	*buf;

	if (!(tmp = (t_ants *)malloc(sizeof(t_ants))))
		return (1);
	tmp->path = path;
	tmp->index = lm->mem_ants - lm->ants + 1;
	tmp->next = NULL;
	buf = lm->ant_lst;
	while (buf && buf->next)
		buf = buf->next;
	if (buf)
		buf->next = tmp;
	else
		lm->ant_lst = tmp;
	lm->ants -= 1;
	return (0);
}
