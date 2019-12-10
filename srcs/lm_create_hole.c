/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_create_hole.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 22:41:15 by hklein            #+#    #+#             */
/*   Updated: 2019/02/14 22:51:58 by hklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		setup_hole(t_lm *lm, char **tab, int start)
{
	t_hole	*buf;

	if (!(buf = init_hole()))
		return (1);
	if (!(buf->name = ft_strdup(tab[0])))
		return (1);
	buf->coord[0] = ft_atoi(tab[1]);
	buf->coord[1] = ft_atoi(tab[2]);
	buf->start = start;
	buf->next = lm->holes;
	lm->holes = buf;
	return (0);
}

int		create_hole(t_lm *lm, char **line)
{
	char	**tab;
	int		start;

	start = !ft_strcmp((*line), "##start") ? 1 : 0;
	start = !start && !ft_strcmp((*line), "##end") ? -1 : start;
	if (start != 0)
	{
		ft_strdel(line);
		if (get_next_line(0, line) < 0)
			return (-2);
	}
	if (!(tab = ft_strsplit((*line), ' ')))
		return (-2);
	if (ft_tab_len(tab) != 3)
		return (ft_tabdel(&tab) + 1);
	if (tab[0][0] == '#' || tab[0][0] == 'L' || get_hole(tab[0], lm->holes)
		|| !ft_is_str_digit(tab[1]) || !ft_is_str_digit(tab[2]))
		return (ft_tabdel(&tab) - 2);
	if (setup_hole(lm, tab, start))
		return (ft_tabdel(&tab) - 2);
	return (ft_tabdel(&tab));
}
