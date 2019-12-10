/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_send_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arumpler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 00:12:29 by arumpler          #+#    #+#             */
/*   Updated: 2019/02/26 11:11:56 by hklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			create_path(t_lm *lm, t_hole *hole)
{
	t_link	*link;

	add_to_path(lm, lm->end);
	add_to_path(lm, hole);
	link = hole->links;
	while (link)
	{
		if (link->flow == -1)
		{
			if (add_to_path(lm, link->linked))
				return (1);
			link = link->linked->links;
		}
		else
			link = link->next;
	}
	return (0);
}

int			create_ants(t_lm *lm, int nb)
{
	t_paths *buf;
	int		i;

	buf = lm->paths;
	i = 0;
	while (buf && lm->ants > 0 && i < nb)
	{
		add_ant(lm, buf->path);
		buf = buf->next;
		i++;
	}
	return (0);
}

void		move_ants2(t_ants *buf, int *changed)
{
	if (buf->path->next)
	{
		buf->path = buf->path->next;
		(*changed)++;
		if (buf->next)
			ft_printf("L%d-%s ", buf->index, buf->path->hole->name);
		else
			ft_printf("L%d-%s\n", buf->index, buf->path->hole->name);
	}
}

int			move_ants(t_lm *lm)
{
	t_ants	*buf;
	t_dis	*distribution;
	int		changed;

	distribution = lm->distribution;
	while (distribution || changed)
	{
		changed = 0;
		if (create_ants(lm, distribution ? distribution->nb : 0))
			return (1);
		buf = lm->ant_lst;
		while (buf)
		{
			move_ants2(buf, &changed);
			buf = buf->next;
		}
		if (distribution)
			distribution = distribution->next;
	}
	return (0);
}

int			send_ants(t_lm *lm)
{
	t_link	*link;

	link = lm->end->links;
	while (link)
	{
		if (link->flow == -1)
		{
			add_paths(lm);
			if (create_path(lm, link->linked))
				return (1);
			sort_first_paths(lm);
		}
		link = link->next;
	}
	if (lm->paths)
		ft_printf("%s\n", lm->end_str);
	else
		return (1);
	lm->mem_ants = lm->ants;
	if (ants_distribution(lm))
		return (1);
	lm->ants = lm->mem_ants;
	if (move_ants(lm))
		return (1);
	return (0);
}
