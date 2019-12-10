/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_create_link.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 22:41:27 by hklein            #+#    #+#             */
/*   Updated: 2019/02/14 22:58:39 by hklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_link_holes(t_hole *buf, t_hole *buf1)
{
	t_link *tmp;

	tmp = buf->links;
	while (tmp)
	{
		if (!ft_strcmp(tmp->linked->name, buf1->name))
			return (1);
		tmp = tmp->next;
	}
	if (!(tmp = init_link()))
		return (1);
	tmp->linked = buf1;
	tmp->next = buf->links;
	buf->links = tmp;
	if (!(tmp = init_link()))
		return (1);
	tmp->linked = buf;
	tmp->next = buf1->links;
	buf1->links = tmp;
	return (0);
}

int		create_link(t_lm *lm, char *line)
{
	char	**tab;
	t_hole	*buf;
	t_hole	*buf1;

	if (!(tab = ft_strsplit(line, '-')))
		return (-3);
	if (ft_tab_len(tab) != 2)
		return (ft_tabdel(&tab) + 1);
	if ((!(buf = get_hole(tab[0], lm->holes)))
		|| (!(buf1 = get_hole(tab[1], lm->holes))))
		return (ft_tabdel(&tab) + 1);
	if (ft_link_holes(buf, buf1))
		return (ft_tabdel(&tab) - 3);
	return (ft_tabdel(&tab));
}
