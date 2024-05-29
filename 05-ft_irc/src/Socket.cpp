/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:02:14 by lle-saul          #+#    #+#             */
/*   Updated: 2024/05/29 16:43:41 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Socket.hpp"

SOCKET::SOCKET(int port)
	:fdsocket(socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)),
	info(init_info(port))
{
	if (fdsocket < 0)
		throw SocketErrException();
}

SOCKET::SOCKET(int fd, const sockaddr_in &addr)
	:fdsocket(fd), info(addr)
{
	if (fdsocket < 0)
		throw SocketErrException();
}

SOCKET::~SOCKET()
{
	close(fdsocket);
}

sockaddr_in	SOCKET::init_info(int port)
{
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	return (addr);
}

void	SOCKET::start_serv()
{
	int res = bind(fdsocket, (sockaddr *)&info, sizeof(info));
	if (res != 0)
		throw InitErrException();
	res = listen(fdsocket, SOMAXCONN);
	if (res != 0)
		throw InitErrException();
}

SOCKET*	SOCKET::accept_client()
{
	sockaddr_in client;
	int	size = sizeof(client);
	int fdclient = accept(fdsocket, (sockaddr *)&client, (socklen_t *)&size);
	return (new SOCKET(fdclient, client));
}

bool	SOCKET::connect_client()
{
	if (connect(fdsocket, (sockaddr *)&info, sizeof(info)) != 0)
		return (false);
	return (true);
}

void	SOCKET::send_msg(const std::string &str)
{
	unsigned short strlen = htons(str.length());
	if (send(fdsocket, reinterpret_cast<const char *>(&strlen), sizeof(strlen), 0) != sizeof(strlen))
		throw SendErrException();
	if (send(fdsocket, reinterpret_cast<const char *>(str.c_str()), str.length(), 0) != (long int)str.length())
		throw SendErrException();
}

std::string	SOCKET::recv_msg()
{
	unsigned short size_needed;
	
	//Get size to received
	int	pending = recv(fdsocket, reinterpret_cast<char *>(&size_needed), sizeof(size_needed), 0);
	if (pending <= 0 || pending != sizeof(unsigned short))
		throw RecvErrException();
	
	//Get every char in vector
	size_needed = ntohs(size_needed);
	std::vector<unsigned char> buff;
	buff.resize(size_needed);
	for (int size_get = 0; size_get < size_needed;) {
		int res = recv(fdsocket, reinterpret_cast<char *>(&buff[size_get]), (size_needed - size_get) * sizeof(unsigned char), 0);
		if (res <= 0) {
			buff.clear();
			throw RecvErrException();
		}
		else
			size_get += res;		
	}

	//transform vector in string
	std::string res_str;
	for (std::vector<unsigned char>::const_iterator it = buff.begin(); it != buff.end(); it++) {
		res_str += *it;
	}
	return (res_str);
}
