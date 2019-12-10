/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arumpler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 00:11:49 by arumpler          #+#    #+#             */
/*   Updated: 2019/02/22 00:11:52 by arumpler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			prev_flow(t_lm *lm)
{
	t_link *link;
	t_hole *hole;

	link = lm->opened->node->hole->links;
	hole = lm->opened->node->parent->hole;
	while (link && link->linked != hole)
		link = link->next;
	return (link->flow);
}

int			find_shortest_path2(t_lm *lm, t_link *link)
{
	if (!(lm->nodes = init_node(link->linked,
		lm->opened->node, lm->nodes)))
		return (1);
	if (create_open_at_end(lm))
		return (1);
	link->linked->marked = 1;
	return (0);
}

int			find_shortest_path(t_lm *lm)
{
	t_link *link;

	if (init_search(lm))
		return (1);
	while (lm->opened)
	{
		link = lm->opened->node->hole->links;
		while (link)
		{
			if (link->linked->marked == 0 && link->flow < 1
				&& !(lm->opened->node->hole->graph_marked == 1
				&& link->flow == 0 && prev_flow(lm) == 0))
			{
				if (find_shortest_path2(lm, link))
					return (1);
				if (link->linked->start == -1)
					return (0);
			}
			link = link->next;
		}
		del_first_opened(lm);
	}
	return (-1);
}

int			solve(t_lm *lm)
{
	int		loop;

	loop = 0;
	set_start(lm);
	while (!loop)
	{
		loop = find_shortest_path(lm);
		if (loop == 1)
			return (1);
		update_flow(lm);
		while (lm->opened)
			del_first_opened(lm);
		free_nodes(lm);
		set_marked(lm);
	}
	return (0);
}
