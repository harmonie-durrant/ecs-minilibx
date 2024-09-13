/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_component.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmonie <rbryento@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:14:11 by harmonie          #+#    #+#             */
/*   Updated: 2024/09/13 23:31:35 by harmonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ecs.h"

t_component	*init_component(t_component_type type, void *data)
{
	t_component	*component;

	component = malloc(sizeof(t_component));
	if (!component)
		return (NULL);
	component->type = type;
	component->data = data;
	component->destroy = NULL;
	component->print = NULL;
	component->update = NULL;
	component->next = NULL;
	return (component);
}

void	destroy_component(t_component *component)
{
	if (!component)
		return ;
	component->destroy(component->data);
	free(component);
}

void	destroy_component_list(t_component *head)
{
	if (!head)
		return ;
	destroy_component_list(head->next);
	destroy_component(head);
}
