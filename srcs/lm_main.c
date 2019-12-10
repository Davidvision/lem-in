/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:53:02 by hklein            #+#    #+#             */
/*   Updated: 2019/02/25 21:41:32 by hklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		free_quit(int ret, t_lm *lm)
{
	if (lm->holes)
		del_holes(lm);
	if (lm->distribution)
		del_dis(lm);
	if (lm->opened)
		del_open(lm);
	if (lm->paths)
		del_paths(lm);
	if (lm->end_str)
	{
		free(lm->end_str);
		lm->end_str = NULL;
	}
	if (lm->ant_lst)
		del_ants(lm);
	if (lm)
		free(lm);
	if (ret)
		ft_printf("ERROR\n");
	return (ret);
}

int		main(void)
{
	t_lm	*lm;

	if (!(lm = init_lm()))
		return (free_quit(1, lm));
	if (parse_lm(lm))
		return (free_quit(1, lm));
	if (solve(lm))
		return (free_quit(1, lm));
	if (send_ants(lm))
		return (free_quit(1, lm));
	return (free_quit(0, lm));
}
