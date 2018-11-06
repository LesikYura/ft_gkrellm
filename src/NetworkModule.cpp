// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NetworkModule.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dpozinen <dpozinen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/14 18:08:39 by dpozinen          #+#    #+#             //
//   Updated: 2018/10/14 18:08:39 by dpozinen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "NetworkModule.hpp"
#include <net/route.h>
#include <net/if.h>
#include <sys/sysctl.h>
#include <sstream>

NetworkModule::NetworkModule() {
}

NetworkModule::~NetworkModule() {
}

NetworkModule::NetworkModule(const NetworkModule &other) {
	*this = other;
}

NetworkModule &NetworkModule::operator=(const NetworkModule &other)
{
	_inPackets = other._inPackets;
	_outPackets = other._outPackets;
	return *this;
}

void	NetworkModule::makeAll(void) {
	makeInOut();
}

void	NetworkModule::update(SDL &sdl)
{
	makeAll();
	(void)sdl;
}

void	NetworkModule::update(Ncurses &nc) {
	// (void)nc;
	makeAll();
	nc.net(_inPackets, _outPackets);
}

void	NetworkModule::makeInOut(void)
{
	FILE	*pipe = popen("top -l 1 -n0 | grep -E \"^Net\"", "r");
	char	usage[256];
	char	temp[24];
	char	*t;

	if (!pipe)
		return ; // TODO: throw
	while (!feof(pipe))
		fgets(usage, 256, pipe);

	t = strstr(usage, ":") + 2;
	t = strstr(t, ":") + 2;
	int i = 0;
	for (i = 0; t[i] != '/'; i++)
		temp[i] = t[i];
	temp[i] = '\0';
	_inPackets = temp;

	for (i = 0; i < 10; i++)
		temp[i] = '\0';

	t = strstr(usage, ",") + 2;
	for (i = 0; t[i] != '/'; i++)
		temp[i] = t[i];
	t += i + 1;
	temp[i] = '\0';
	_outPackets = temp;
	pclose(pipe);
}

std::string	NetworkModule::getInPackets(void) const {
	return _inPackets;
}

std::string	NetworkModule::getOutPackets(void) const {
	return _outPackets;
}