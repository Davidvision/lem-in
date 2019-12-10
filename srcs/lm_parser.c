/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:58:37 by hklein            #+#    #+#             */
/*   Updated: 2019/02/26 11:11:05 by hklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_comment(char *line)
{
	if (ft_strlen(line) && line[0] != '#')
		return (0);
	if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
		return (0);
	else
		return (1);
}

int		get_ant_nb(t_lm *lm, char *line)
{
	int		i;

	i = 0;
	while (line[i])
		if (!ft_isdigit(line[i++]))
			return (-1);
	lm->ants = ft_atoi(line);
	if (ft_strlen(line) != ft_int_len(lm->ants))
		return (-1);
	return (42);
}

int		add_to_str(t_lm *lm, char *line)
{
	static int	i = 0;
	int			j;

	j = 0;
	if (!i)
	{
		if (!(lm->end_str = ft_strnew(200000)))
			return (1);
	}
	while (line[j])
		lm->end_str[i++] = line[j++];
	lm->end_str[i++] = '\n';
	return (0);
}

void	parse_lm2(int *i, t_lm *lm, char *line)
{
	if (*i == 2)
		*i += create_link(lm, line);
	if (*i == 42)
		*i = 1;
}

int		parse_lm(t_lm *lm)
{
	int		i;
	char	*line;

	i = 0;
	while (i < 3 && get_next_line(0, &line))
	{
		if (!*line)
			i = -1;
		if (!is_comment(line))
		{
			if (!i)
				i += get_ant_nb(lm, line);
			if (i == 1)
				i += create_hole(lm, &line);
			parse_lm2(&i, lm, line);
			if (i < 3)
				if (add_to_str(lm, line))
					return (1);
		}
		ft_strdel(&line);
		if (i < 0)
			return (1);
	}
	return (check_inputs(lm));
}
