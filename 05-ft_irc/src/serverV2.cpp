/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverV2.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:01:46 by lle-saul          #+#    #+#             */
/*   Updated: 2024/05/29 16:47:03 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Socket.hpp"
#include <sstream>

int main(int ac, char **av)
{
	if (ac != 3) {
		std::cerr << "Use : ./ft_irc <port> <password>" << std::endl;
		return (1);
	}
	int fdsocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (fdsocket < 0) {
		std::cerr << "Socket creation echec" << std::endl;
		return (1);
	}

	std::stringstream ss(av[1]);
	int port;
	ss >> port;
	if (ss.fail()) {
		std::cerr << "Err: conversion !" << std::endl;
		return (1);
	}
	std::cout << "Port use : " << port << std::endl;
	
	try {
		SOCKET	server(port);
		server.start_serv();
		
		SOCKET	*client1 = server.accept_client();
		std::cout << "Client connected !" << std::endl;
		
		while (1) {
			std::string res(client1->recv_msg());
			std::cout << res << std::endl;
			if (res == "exit") {
				delete client1;
				break ;
			}
		}
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
