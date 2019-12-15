/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabayle <mabayle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 01:20:24 by mabayle           #+#    #+#             */
/*   Updated: 2019/12/15 01:55:48 by mabayle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_ast   *init_node(t_lex *lex)
{
    t_ast *new_node;

    new_node = ft_memalloc(sizeof(t_ast*));
    new_node->lex = lex;
    new_node->value = lex->value;
    new_node->priority = lex->priority;
    new_node->left = NULL;
    new_node->right = NULL;
}

void    init_priority(t_lex *lex)
{
    if (!lex)
        return ;
    while (lex)
    {
        if (lex->token == WORD)
            lex->priority = 0;
        if (lex->token == DAND || lex->token == DPIPE)
            lex->priority = 2;
        if (lex->token == SEMIC || lex->token == AND)
            lex->priority = 3;
        lex = lex->next;
    }
}

int     build_ast(t_lex *lex, t_ast **ast)
{
    init_priority(lex);
    if (lex && lex->token != UNKNOWN)
    {
        *ast = init_node(lex);
        create_ast(*ast, (*ast)->priority);
    }
}