/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_update_flow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arumpler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 00:03:36 by arumpler          #+#    #+#             */
/*   Updated: 2019/02/22 00:03:39 by arumpler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		mark_link(t_hole *src, t_hole *dest, int value)
{
	t_link	*buf;

	buf = src->links;
	while (buf->linked != dest)
		buf = buf->next;
	buf->flow += value;
}

void		update_flow(t_lm *lm)
{
	t_node	*node;

	node = lm->nodes;
	while (node && node->parent)
	{
		mark_link(node->parent->hole, node->hole, 1);
		mark_link(node->hole, node->parent->hole, -1);
		node->hole->graph_marked = 1;
		node = node->parent;
	}
}
