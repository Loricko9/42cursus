/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:29:13 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/16 12:29:13 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "get_next_line.h"
# include "Push_swap.h"

//main_checker_bonus.c
void	get_cmd(t_list **stack_a, t_list **stack_b);

//do_cmd_bonus.c
int		ft_cmp_cmd(char *cmp, char *str);
void	do_cmd(char *str, t_list **stack_a, t_list **stack_b);
void	do_cmd2(char *str, t_list **stack_a, t_list **stack_b);
void	do_cmd3(char *str, t_list **stack_a, t_list **stack_b);

//Sort_bonus.c
void	sab_checker(t_list *stack);
void	ss_checker(t_list *stack_a, t_list *stack_b);
void	pb_checker(t_list **stack_a, t_list **stack_b);
void	pa_checker(t_list **stack_a, t_list **stack_b);

//Sort2_bonus.c
void	rab_checker(t_list **stack);
void	rr_checker(t_list **stack_a, t_list **stack_b);
void	rrab_checker(t_list **stack);
void	rrr_checker(t_list **stack_a, t_list **stack_b);

//Sort3_bonus.c
void	pb2_checker(t_list **stack_a, t_list **stack_b);
void	pa2_checker(t_list **stack_a, t_list **stack_b);

#endif
