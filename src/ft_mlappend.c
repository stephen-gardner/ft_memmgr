/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlappend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:37:31 by sgardner          #+#    #+#             */
/*   Updated: 2017/12/05 20:51:48 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_memmgr.h"

t_mlink	*ft_mlappend(t_mchain *mchain, void *ptr, size_t size)
{
	t_mlink	*mlink;
	t_mlink	**current;

	if (!(mlink = ft_mladd(mchain, ptr, size)))
		return (NULL);
	mchain->links = mlink->next;
	current = &mchain->links;
	while (*current)
		current = &(*current)->next;
	*current = mlink;
	mlink->next = NULL;
	return (mlink);
}
