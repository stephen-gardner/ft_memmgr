/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlremove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 01:28:57 by sgardner          #+#    #+#             */
/*   Updated: 2017/12/05 02:08:16 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_memmgr.h"

t_mlink	*ft_mlremove(t_mlink *mlink)
{
	t_mchain	*mchain;
	t_mlink		**current;

	mchain = mlink->mchain;
	current = &mchain->links;
	while (*current != mlink)
		current = &(*current)->next;
	*current = (*current)->next;
	free(mlink);
	mchain->link_count--;
	return (*current);
}
