/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_entity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmonie <rbryento@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:05:15 by harmonie          #+#    #+#             */
/*   Updated: 2024/09/13 23:32:13 by harmonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ecs.h"

void	update_entity(t_entity *entity, t_game *data)
{
	t_component	*curr;

	curr = NULL;
	if (!entity)
		return ;
	curr = entity->components;
	while (curr)
	{
		if (curr->update)
			curr->update(curr->data, entity, data);
		curr = curr->next;
	}
}

void	update_entity_list(t_entity *head, t_game *data)
{
	if (!head)
		return ;
	update_entity(head, data);
	update_entity_list(head->next, data);
}

void	update_entity_group_list(t_entity_group *head, t_game *data)
{
	if (!head)
		return ;
	update_entity_list(head->entity, data);
	update_entity_group_list(head->next, data);
}
