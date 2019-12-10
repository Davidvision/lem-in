/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:51:11 by hklein            #+#    #+#             */
/*   Updated: 2019/02/25 22:23:47 by hklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "../libft/libft.h"

typedef struct		s_hole t_hole;

typedef struct		s_link
{
	int				flow;
	t_hole			*linked;
	struct s_link	*next;
}					t_link;

typedef struct		s_hole
{
	char			*name;
	int				coord[2];
	int				start;
	t_link			*links;
	int				marked;
	int				graph_marked;
	struct s_hole	*next;
}					t_hole;

typedef struct		s_node
{
	t_hole			*hole;
	struct s_node	*parent;
	struct s_node	*next;
}					t_node;

typedef struct		s_open
{
	t_node			*node;
	struct s_open	*next;
}					t_open;

typedef struct		s_path
{
	t_hole			*hole;
	struct s_path	*next;
}					t_path;

typedef struct		s_paths
{
	t_path			*path;
	struct s_paths	*next;
}					t_paths;

typedef struct		s_dis
{
	int				nb;
	struct s_dis	*next;	
}					t_dis;

typedef struct		s_ants
{
	t_path			*path;
	int				index;
	struct s_ants	*next;
}					t_ants;

typedef struct		s_lm
{
	t_hole			*holes;
	t_node			*nodes;
	t_open			*opened;
	t_hole			*start;
	t_hole			*end;
	t_paths			*paths;
	int				ants;
	int				mem_ants;
	t_dis			*distribution;
	t_ants			*ant_lst;
	char			*end_str;
}					t_lm;

int					parse_lm(t_lm *lm);
t_lm				*init_lm(void);
t_hole				*init_hole(void);
t_link				*init_link(void);
t_hole				*get_hole(char *name, t_hole *holes);
int					create_hole(t_lm *lm, char **line);
int					create_link(t_lm *lm, char *line);
int        			check_inputs(t_lm *lm);
void				del_holes(t_lm *lm);
int         solve(t_lm *lm);
void			set_start(t_lm *lm);
int			init_search(t_lm *lm);
int			create_open_at_end(t_lm *lm);
void        free_nodes(t_lm *lm);
void        del_first_opened(t_lm *lm);
t_node		*init_node(t_hole *hole, t_node *parent, t_node *next);
void        update_flow(t_lm *lm);
void		set_marked(t_lm *lm);
int         add_to_path(t_lm *lm, t_hole *hole);
int         add_paths(t_lm *lm);
int         send_ants(t_lm *lm);
int			path_len(t_path *path);
void		sort_first_paths(t_lm *lm);
int			add_ant(t_lm *lm, t_path *path);
void 	   del_ants(t_lm *lm);
int		ants_distribution(t_lm *lm);
void	del_dis(t_lm *lm);
void	del_open(t_lm *lm);
void	del_paths(t_lm *lm);
#endif
