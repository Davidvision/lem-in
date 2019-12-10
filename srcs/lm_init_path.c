/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_init_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arumpler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 00:15:40 by arumpler          #+#    #+#             */
/*   Updated: 2019/02/22 00:15:43 by arumpler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			add_to_path(t_lm *lm, t_hole *hole)
{
	t_path *path;

	if (!(path = (t_path *)malloc(sizeof(t_path))))
		return (1);
	path->hole = hole;
	path->next = lm->paths->path;
	lm->paths->path = path;
	return (0);
}

int			add_paths(t_lm *lm)
{
	t_paths *paths;

	if (!(paths = (t_paths *)malloc(sizeof(t_paths))))
		return (1);
	paths->path = NULL;
	paths->next = lm->paths;
	lm->paths = paths;
	return (0);
}

int			path_len(t_path *path)
{
	int		len;
	t_path	*buf;

	len = 0;
	buf = path;
	while (buf)
	{
		len++;
		buf = buf->next;
	}
	return (len);
}

void		sort_first_paths(t_lm *lm)
{
	int		len;
	t_paths	*buf;
	t_paths	*tmp;

	len = path_len(lm->paths->path);
	buf = lm->paths;
	while (buf && buf->next && len > path_len(buf->next->path))
		buf = buf->next;
	if (lm->paths != buf)
	{
		tmp = lm->paths;
		lm->paths = lm->paths->next;
		tmp->next = buf->next;
		buf->next = tmp;
	}
}
