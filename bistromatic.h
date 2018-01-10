/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistromatic.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 18:41:07 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/10 12:08:23 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BISTROMATIC_H
# define BISTROMATIC_H
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	char			*data;
	int				level;
	struct s_list	*next;
}					t_list;

typedef struct              s_linked_list
{
    char                    *data;
    struct s_linked_list    *next;
}                           linked_list;
#endif
