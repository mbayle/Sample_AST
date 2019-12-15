/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:19:06 by jaleman           #+#    #+#             */
/*   Updated: 2017/01/19 15:19:06 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function begins printing from the address specified (ws) until it reaches
** the terminating null wide character.
** This terminating null wide character is not printed to the file descriptor.
*/

int		ft_putwstr_fd(wchar_t *wcs, int fd)
{
	int		len;

	len = 0;
	while (*wcs)
	{
		ft_putwchar_fd(*wcs, fd);
		len += ft_wclen(*wcs);
		wcs += 1;
	}
	return (len);
}
