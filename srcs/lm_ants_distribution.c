/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_ants_distribution.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arumpler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 18:27:27 by arumpler          #+#    #+#             */
/*   Updated: 2019/02/25 18:27:31 by arumpler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		init_dis(t_lm *lm, int nb)
{
	t_dis *tmp;

	if (!(tmp = (t_dis *)malloc(sizeof(t_dis))))
		return (1);
	tmp->next = lm->distribution;
	tmp->nb = nb;
	lm->distribution = tmp;
	return (0);
}

int		init_last_dis(t_lm *lm)
{
	t_dis *tmp;
	t_dis *buf;

	buf = lm->distribution;
	if (!(tmp = (t_dis *)malloc(sizeof(t_dis))))
		return (1);
	tmp->nb = lm->ants;
	while (buf && buf->nb > lm->ants)
		buf = buf->next;
	tmp->next = buf->next;
	buf->next = tmp;
	return (0);
}

int		sublist_len(t_dis *distrib, int nb)
{
	int		len;
	t_dis	*buf;

	len = 0;
	buf = distrib;
	while (buf && buf->nb == nb)
	{
		len++;
		buf = buf->next;
	}
	return (len);
}

int		get_nb(t_lm *lm)
{
	t_paths	*buf;
	int		nb;
	int		i;
	int		prev_len;

	if (!lm->distribution)
		return (1);
	nb = lm->distribution->nb;
	i = 0;
	buf = lm->paths;
	while (buf && i < lm->distribution->nb)
	{
		prev_len = path_len(buf->path);
		buf = buf->next;
		i++;
	}
	if (buf && path_len(buf->path) - prev_len
		<= sublist_len(lm->distribution, nb))
		return (nb + 1);
	return (nb);
}

int		ants_distribution(t_lm *lm)
{
	int nb;

	nb = 0;
	while (lm->ants > nb)
	{
		nb = get_nb(lm);
		lm->ants -= nb;
		if (init_dis(lm, nb))
			return (1);
	}
	if (lm->ants)
		if (init_last_dis(lm))
			return (1);
	return (0);
}
