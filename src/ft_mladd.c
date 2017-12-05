/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mladd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 00:04:08 by sgardner          #+#    #+#             */
/*   Updated: 2017/12/05 02:02:42 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_memmgr.h"

t_mlink	*ft_mladd(t_mchain *mchain, void *ptr, size_t size)
{
	t_mlink		*mlink;

	if (!(mlink = (t_mlink *)ft_memalloc(sizeof(t_mlink))))
		return (NULL);
	mlink->mchain = mchain;
	mlink->ptr = ptr;
	mlink->size = size;
	mlink->next = mchain->links;
	mchain->links = mlink;
	mchain->link_count++;
	return (mlink);
}
