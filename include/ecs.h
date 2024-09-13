/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ecs.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmonie <rbryento@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:28:22 by harmonie          #+#    #+#             */
/*   Updated: 2024/09/13 23:46:36 by harmonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ECS_H
# define ECS_H

# include "ecs_structs.h"
# include "vectors.h"
# include "../minilibx-linux/mlx.h"

# include <stdlib.h>
# include <unistd.h>

// Entities
t_entity	*init_entity(int id);
void		destroy_entity(t_entity *entity);
void		destroy_entity_list(t_entity *head);
void		print_entity(t_entity *entity);
void		print_entity_list(t_entity *head);
int			append_entity(t_entity **head, t_entity *entity);
t_entity	*get_entity(t_entity *head, int id);

// Components
t_component	*init_component(t_component_type type, void *data);
void		destroy_component(t_component *component);
void		destroy_component_list(t_component *head);
void		print_component_list(t_component *head);
int			append_component(t_component **head, t_component *new);
void		*get_component(t_component *head, t_component_type type);
int			remove_component(t_component **head, t_component_type type);

// Utils
void		ecs_putstr_fd(char *str, int fd);
void		ecs_putnbr_fd(int n, int fd);

#endif