/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_free_lists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arumpler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 00:16:57 by arumpler          #+#    #+#             */
/*   Updated: 2019/02/22 00:17:00 by arumpler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		del_first_opened(t_lm *lm)
{
	t_open *tmp;

	tmp = lm->opened;
	lm->opened = lm->opened->next;
	free(tmp);
}

void		free_nodes(t_lm *lm)
{
	t_node *tmp;
	t_node *tmp1;

	tmp = lm->nodes;
	while (tmp)
	{
		tmp1 = tmp->next;
		free(tmp);
		tmp = tmp1;
	}
}
