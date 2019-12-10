/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_del_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 22:41:34 by hklein            #+#    #+#             */
/*   Updated: 2019/02/25 22:18:54 by hklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	del_holes(t_lm *lm)
{
	t_hole	*buf_hole;
	t_hole	*buf_hole1;
	t_link	*buf_link;
	t_link	*buf_link1;

	buf_hole1 = lm->holes;
	while (buf_hole1)
	{
		buf_hole = buf_hole1;
		buf_link1 = buf_hole->links;
		while (buf_link1)
		{
			buf_link = buf_link1;
			buf_link1 = buf_link->next;
			free(buf_link);
			buf_link = NULL;
		}
		buf_hole1 = buf_hole->next;
		ft_strdel(&(buf_hole->name));
		free(buf_hole);
		buf_hole = NULL;
	}
}

void	del_dis(t_lm *lm)
{
	t_dis	*buf_dis;
	t_dis	*buf_dis1;

	buf_dis1 = lm->distribution;
	while (buf_dis1)
	{
		buf_dis = buf_dis1;
		buf_dis1 = buf_dis->next;
		free(buf_dis);
		buf_dis = NULL;
	}
}

void	del_ants(t_lm *lm)
{
	t_ants	*buf_ants;
	t_ants	*buf_ants1;

	buf_ants1 = lm->ant_lst;
	while (buf_ants1)
	{
		buf_ants = buf_ants1;
		buf_ants1 = buf_ants->next;
		free(buf_ants);
		buf_ants = NULL;
	}
}

void	del_open(t_lm *lm)
{
	t_open	*buf_open;
	t_open	*buf_open1;

	buf_open1 = lm->opened;
	while (buf_open1)
	{
		buf_open = buf_open1;
		buf_open1 = buf_open->next;
		free(buf_open);
		buf_open = NULL;
	}
}

void	del_paths(t_lm *lm)
{
	t_paths	*buf_paths;
	t_paths	*buf_paths1;
	t_path	*buf_path;
	t_path	*buf_path1;

	buf_paths1 = lm->paths;
	while (buf_paths1)
	{
		buf_paths = buf_paths1;
		buf_path1 = buf_paths->path;
		while (buf_path1)
		{
			buf_path = buf_path1;
			buf_path1 = buf_path->next;
			free(buf_path);
			buf_path = NULL;
		}
		buf_paths1 = buf_paths->next;
		free(buf_paths);
		buf_paths = NULL;
	}
}
