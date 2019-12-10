/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_init_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arumpler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 00:14:59 by arumpler          #+#    #+#             */
/*   Updated: 2019/02/22 00:15:01 by arumpler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node		*init_node(t_hole *hole, t_node *parent, t_node *next)
{
	t_node *node;

	if (!(node = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	node->hole = hole;
	node->parent = parent;
	node->next = next;
	return (node);
}

t_open		*init_open(t_node *node)
{
	t_open *open;

	if (!(open = (t_open *)malloc(sizeof(t_open))))
		return (NULL);
	open->node = node;
	open->next = NULL;
	return (open);
}

int			init_search(t_lm *lm)
{
	if (!(lm->nodes = init_node(lm->start, NULL, NULL)))
		return (1);
	if (!(lm->opened = init_open(lm->nodes)))
		return (1);
	return (0);
}

int			create_open_at_end(t_lm *lm)
{
	t_open *open;

	open = lm->opened;
	while (open && open->next)
		open = open->next;
	if (!(open->next = init_open(lm->nodes)))
		return (1);
	return (0);
}

void		set_marked(t_lm *lm)
{
	t_hole *hole;

	hole = lm->holes;
	while (hole)
	{
		hole->marked = 0;
		hole = hole->next;
	}
	lm->start->marked = 1;
}
