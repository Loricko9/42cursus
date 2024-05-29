/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:21:56 by lle-saul          #+#    #+#             */
/*   Updated: 2024/05/27 14:21:56 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include <sstream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int	main(int ac, char **av)
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
	std::cout << port << std::endl;

	sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	if (connect(fdsocket, (sockaddr *)&server, sizeof(server)) != 0) {
		std::cerr << "Err: connection socket !" << std::endl;
		return (1);
	}
	std::cout << "connection success !" << std::endl;

	char buff[20];
	if (recv(fdsocket, buff, 19, 0) <= 0) {
		std::cerr << "Err : de reception !" << std::endl;
	}
	std::cout << buff << std::endl;

	std::string str("Ok bien reçu !");
	if (send(fdsocket, str.c_str(), 16, 0) == -1) {
		std::cerr << "Err : d'envoi !" << std::endl;
	}

	close(fdsocket);
}