/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ecs_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmonie <rbryento@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:03:39 by harmonie          #+#    #+#             */
/*   Updated: 2024/09/13 23:33:33 by harmonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ECS_STRUCTS_H
# define ECS_STRUCTS_H

typedef struct s_entity	t_entity;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
}	t_game;

typedef enum s_component_type
{
	CT_OTHER
}	t_component_type;

typedef enum s_entity_group_type
{
	EG_OTHER,
}	t_entity_group_type;

typedef struct s_component
{
	t_component_type	type;
	void				*data;
	void				(*destroy)(void *);
	void				(*print)(void *);
	void				(*update)(void *, t_entity *, t_game *);
	struct s_component	*next;
}	t_component;

typedef struct s_entity
{
	int				id;
	t_component		*components;
	struct s_entity	*next;
}	t_entity;

typedef struct s_entity_group
{
	t_entity_group_type		type;
	t_entity				*entity;
	struct s_entity_group	*next;
}	t_entity_group;

#endif