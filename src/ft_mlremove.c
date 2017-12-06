/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlremove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 01:28:57 by sgardner          #+#    #+#             */
/*   Updated: 2017/12/06 00:30:51 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_memmgr.h"

t_mlink	*ft_mlremove(t_mlink *mlink)
{
	t_mchain	*mchain;
	t_mlink		**current;

	mchain = mlink->mchain;
	if (mchain->end == mlink)
		mchain->end = NULL;
	current = &mchain->start;
	while (*current != mlink)
		current = &(*current)->next;
	*current = (*current)->next;
	free(mlink);
	mchain->link_count--;
	return (*current);
}
