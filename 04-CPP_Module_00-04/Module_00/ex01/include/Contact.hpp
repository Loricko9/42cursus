/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:59:04 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/12 18:57:30 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact
{
public:
	Contact();
	~Contact();
	void	Fill_Contact();
	void	Change_index(int nb);
	void	Print_tab() const;
	void	Print_data() const;
	int		Get_index() const;
	std::string	Get_input(std::string str) const;
private:
	std::string	Fname;
	std::string	Lname;
	std::string	Nickname;
	std::string	Phone;
	std::string	Secret;
	int			index;
};

#endif

