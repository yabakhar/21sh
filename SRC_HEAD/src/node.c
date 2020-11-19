/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macos <macos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 15:37:17 by macos             #+#    #+#             */
/*   Updated: 2020/11/13 21:20:09 by macos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/21sh.h"

void    append_list(t_lexer **root, char *data, t_type type)
{
    t_lexer *last;
    t_lexer *ret;

    last = *root;

    ret = (t_lexer*)ft_memalloc(sizeof(t_lexer));
    if (ret == NULL)
        return ;
    ret->data = ft_strdup(data);
    ret->type = type;
    ret->next = NULL;
    if (last == NULL)
    {
        *root = ret;
        return ;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = ret;
    return ;
}

void    append_list_redi(t_lexer **root, char *data, t_type type, t_pointt *cor)
{
    t_lexer *last;
    t_lexer *ret;

    last = *root;

    ret = (t_lexer*)ft_memalloc(sizeof(t_lexer));
    if (ret == NULL)
        return ;
    ret->data = data;
    ret->type = type;
    ret->coor.aggr_index = cor->aggr_index;
    cor->aggr_index = cor->aggr_index + 1;
    ret->next = NULL;
    if (last == NULL)
    {
        if (last->type == AGGR_SYM)
            ret->coor.aggr_index = 1;
        *root = ret;
        return ;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = ret;
    return ;
}

void    append_list_pipe(t_lexer **root, char *data, t_type type, t_pointt *cor)
{
    t_lexer *last;
    t_lexer *ret;

    last = *root;

    ret = (t_lexer*)ft_memalloc(sizeof(t_lexer));
    if (ret == NULL)
        return ;
    ret->data = data;
    ret->type = type;
    ret->coor.pipe_index = cor->pipe_index;
    cor->pipe_index = cor->pipe_index + 1;
    ret->next = NULL;
    if (last == NULL)
    {
        *root = ret;
        return ;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = ret;
    return ;
}

void    print_list(t_lexer *token_list)
{
    while (token_list != NULL)
    {
        ft_putnbr_fd(token_list->type, 1);
        ft_putchar_fd(' ', 1);
        ft_putstr_fd(token_list->data, 1);
        ft_putstr_fd("...........|| aggr_index = ", 1);
        ft_putnbr_fd(token_list->coor.aggr_index, 1);
        ft_putstr_fd(" || pipe_index = ", 1);
        ft_putnbr_fd(token_list->coor.pipe_index, 1);
        ft_putchar_fd('\n', 1);
        token_list = token_list->next;
    }
}

t_type last_node_type(t_lexer **head)
{
    t_lexer *current;

    if (head && *head)
    {
        current = *head;
        while (current->next)
            current = current->next;
        return (current->type);
    }
    return (0);
}
