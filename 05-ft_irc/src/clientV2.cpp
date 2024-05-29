/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clientV2.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:07:44 by lle-saul          #+#    #+#             */
/*   Updated: 2024/05/29 16:47:15 by lle-saul         ###   ########.fr       */
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
	
	SOCKET server(port);
	if (!server.connect_client()) {
		std::cerr << "Err : connection client !" << std::endl;
		return (1);
	}

	std::cout << "Connected to server !" << std::endl;
	try {
		while (1) {
			std::string input;
			std::getline(std::cin, input);
			if (std::cin.good() && !input.empty()) {
				server.send_msg(input);
				if (input == "exit")
					break ;
			}
			else
			{
				std::cin.clear();
				input.clear();
			}
		}
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Good Bye !" << std::endl;
}