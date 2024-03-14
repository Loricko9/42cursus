/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:54:45 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/14 10:23:57 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CPP
#define	HARL_CPP

#include <iostream>

class	Harl
{
	typedef	void	(Harl::*functions) (void);
public:
	Harl();
	~Harl();
	void	complain( std::string level );
private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
};

#endif
