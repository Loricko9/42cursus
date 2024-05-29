/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:42:00 by lle-saul          #+#    #+#             */
/*   Updated: 2024/05/29 16:33:20 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <unistd.h>
#include <exception>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <vector>

class SOCKET
{
public:
	SOCKET(int port);
	SOCKET(int fd, const sockaddr_in &addr);
	~SOCKET();

	void		start_serv();
	SOCKET*		accept_client();
	bool		connect_client(); //Only for client, DON'T USE IT !!!!
	
	void			send_msg(const std::string &str);
	std::string		recv_msg();
	

	class	SocketErrException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Error : Socket creation error !");
			}
	};
	class	InitErrException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Error : Initialisation server !");
			}
	};
	class	SendErrException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Error : Send message !");
			}
	};
	class	RecvErrException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Error : Recv message !");
			}
	};
private:
	const int			fdsocket;
	const sockaddr_in	info;

	sockaddr_in	init_info(int port);
	SOCKET();
	SOCKET(const SOCKET &src);
};

