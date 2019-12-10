/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_check_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 22:41:07 by hklein            #+#    #+#             */
/*   Updated: 2019/02/26 11:10:32 by hklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_inputs(t_lm *lm)
{
	int		start;
	int		end;
	t_hole	*tmp;

	start = 0;
	end = 0;
	tmp = lm->holes;
	while (tmp)
	{
		if (tmp->start > 0)
			start++;
		else if (tmp->start < 0)
			end++;
		tmp = tmp->next;
	}
	if (!lm->ants || lm->ants <= 0
		|| start != 1 || end != 1)
		return (1);
	return (0);
}
