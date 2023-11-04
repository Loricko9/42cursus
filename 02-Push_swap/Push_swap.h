/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:27:16 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/04 18:27:16 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "ft_printf.h"

typedef struct s_list
{
	int		nb;
	t_list	*next;
}	t_list;

//list_utils.c
t_list	*ft_lstnew(int nb);
void	ft_lstadd_back(t_list **lst, t_list	*new);
t_list	*ft_lstlast(t_list *lst);

#endif
