/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_entity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmonie <rbryento@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:51:52 by harmonie          #+#    #+#             */
/*   Updated: 2024/09/13 23:29:54 by harmonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ecs.h"

int	append_entity(t_entity **head, t_entity *entity)
{
	if (!entity)
		return (1);
	if (*head)
		entity->next = *head;
	*head = entity;
	return (0);
}

t_entity	*get_entity(t_entity *head, int id)
{
	t_entity	*curr;

	curr = head;
	while (curr && curr->id != id)
		curr = curr->next;
	return (curr);
}
