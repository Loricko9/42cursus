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
	int				nb;
	struct s_list	*next;
}	t_list;

//Push_swap.c
long long	ft_atoi(const char *nptr);
int		create_node(int i, int j, char **av, t_list **stack_a);
void		get_lst(char **av, t_list **stack_a);
void		printlst(t_list *stack_a, t_list *stack_b); //-----A RETIRER-----

//list_utils.c
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int nb);
void	ft_lstadd_back(t_list **lst, t_list	*new);
t_list	*ft_lstlast(t_list *lst);
void	ft_free_lst(t_list *lst);

//check_av.c
int	check_line(char *str);
int	check_av(char **av);
int	check_double(t_list *stock);
int	check_order(t_list *stack_a);

//Sort.c
void	sab(t_list *stack, int a);
void	ss(t_list *stack_a, t_list *stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);

//Sort2.c
void	rab(t_list *stack, int a);
void	rr(t_list *stack_a, t_list *stack_b);
void	rev_i(int *i);
void	rrab(t_list *stack, int a);
void	rrr(t_list *stack_a, t_list *stack_b);

//Swap.c
void	swap(t_list **stack_a, t_list **stack_b);
int		min(t_list *stack);
int		near(int min, int size);

#endif
