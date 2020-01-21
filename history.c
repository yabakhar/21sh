/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabakhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 23:59:46 by yabakhar          #+#    #+#             */
/*   Updated: 2019/12/21 23:59:48 by yabakhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void ft_next(t_node **head, t_node **list, int *cursor, char **str, t_line *line)
{
	if (!(*list) && (*head))
	{
		*list = *head;
		ft_stock(*str, head, line);
	}
	else if ((*list) && (*list)->next)
	{
		if (!(*list)->prev)
		{
			ft_stock(*str, list, line);
			(*list) = (*list)->next;
		}
		(*list) = (*list)->next;
	}
	else
		ft_putstr(tgetstr("bl", NULL));
	if (list && (*list))
	{
		tputs(tgoto(tgetstr("cm", 0), line->c_o.x, line->c_o.y), 0, ft_output);
		tputs(tgetstr("cd", 0), 0, ft_output);
		ft_putstr((*list)->content);
		line->len = ((*list)->prev) ? (*list)->tabl[(*list)->index] : (*list)->len;
		line->b_line = (*list)->b_line;
		ft_strdel(str);
		*cursor = line->len;
		*str = ft_strdup((*list)->content);
		line->index = (*list)->index;
		line->tabl = (*list)->tabl;
		line->t_len = (*list)->b_line;
		line->i = line->index;
		move_cursor_v(line);
		cur_goto(line, *cursor);
	}
}

void ft_prev(t_node **head, t_node **list, int *cursor, char **str, t_line *line)
{
	if ((*list))
		(*list) = (*list)->prev;
	if ((*list))
	{
		tputs(tgoto(tgetstr("cm", 0), line->c_o.x, line->c_o.y), 0, ft_output);
		tputs(tgetstr("cd", 0), 0, ft_output);
		ft_putstr((*list)->content);
		line->len = ((*list)->prev) ? (*list)->tabl[(*list)->index] : (*list)->b_line;
		line->b_line = (*list)->len;
		ft_strdel(str);
		*cursor = line->len;
		*str = ft_strdup((*list)->content);
		line->index = (*list)->index;
		line->tabl = (*list)->tabl;
		line->t_len = (*list)->b_line;
		line->i = line->index;
		move_cursor_v(line);
		cur_goto(line, *cursor);
	}
	else
		ft_putstr(tgetstr("bl", NULL));
	if ((*list) && !(*list)->prev)
	{
		(*list) = NULL;
		(*head) = (*head)->next;
		ft_strdel(&(*head)->prev->content);
		ft_memdel((void **)&(*head)->prev);
		(*list) = NULL;
	}
}

void ft_end(t_node **list, t_node **head, t_line *line, char **str, int *cursor)
{
	if ((*list) && (*list)->prev)
	{
		(*head) = (*head)->next;
		ft_strdel(&(*head)->prev->content);
		ft_memdel((void **)&(*head)->prev);
	}
	multilne(*str,line);
	ft_stock(*str, head, line);
	(*list) = NULL;
	ft_strdel(str);
	line->len = 0;
	line->tabl = 0;
	line->t_len = 0;
	line->b_line = 0;
	print_porompte(cursor, line);
}
