/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmonie <rbryento@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:42:15 by harmonie          #+#    #+#             */
/*   Updated: 2024/09/13 23:31:58 by harmonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ecs.h"

t_entity	*init_entity(int id)
{
	t_entity	*entity;

	entity = malloc(sizeof(t_entity));
	if (!entity)
		return (NULL);
	entity->id = id;
	entity->components = NULL;
	entity->next = NULL;
	return (entity);
}

void	destroy_entity(t_entity *entity)
{
	if (!entity)
		return ;
	destroy_component_list(entity->components);
	free(entity);
}

void	destroy_entity_list(t_entity *head)
{
	if (!head)
		return ;
	destroy_entity_list(head->next);
	destroy_entity(head);
}
