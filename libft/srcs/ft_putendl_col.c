/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puendl_col.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabayle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 02:28:20 by mabayle           #+#    #+#             */
/*   Updated: 2020/01/20 02:28:51 by mabayle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_col(char *str, char *color, char *colreset)
{
	ft_putstr(color);
	ft_putstr(str);
	ft_putendl(colreset);
}
