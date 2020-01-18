/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabayle <mabayle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 23:38:57 by mabayle           #+#    #+#             */
/*   Updated: 2020/01/18 04:10:10 by mabayle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projectinclude.h"

t_21sh	*init_shell(int debug)
{
	t_21sh		*shell;

	shell = ft_memalloc(sizeof(*shell));
	shell->lex = NULL;
	shell->lex_size = 0;
	shell->ast = NULL;
	shell->debug = debug;
	return (shell);
}

int		main(int argc, char **argv)
{
	if (argc == 2 || argc == 3)
	{
		if (argc == 3 && ft_strcmp(argv[2], "DEBUG") == 0)
			g_shell = init_shell(1);
		else
			g_shell = init_shell(0);
		g_shell->line = argv[1];
		ft_lexer(&g_shell->lex, g_shell->line);
	}
	else
		ft_putendl("Usage : BTreeTest [test argument] [DEBUG]\n");
	return (0);
}
