// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RAMModule.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dpozinen <dpozinen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/14 13:04:02 by dpozinen          #+#    #+#             //
//   Updated: 2018/10/14 13:04:02 by dpozinen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "RAMModule.hpp"

RAMModule::RAMModule() {
}

RAMModule::~RAMModule() {
}

RAMModule::RAMModule(const RAMModule &other) {
	*this = other;
}

RAMModule &RAMModule::operator=(const RAMModule &other)
{
	_used = other._used;
	_unused = other._unused;
	_fullSize = other._fullSize;
	return *this;
}

void	RAMModule::makeAll()
{
	_fullSize = "8192M";
	makeCurUsed();
}

void	RAMModule::update(SDL &sdl)
{
	makeCurUsed();
	(void)sdl;
}

void	RAMModule::update(Ncurses &nc)
{
	makeCurUsed();
	nc.ram(_fullSize, _used, _unused);
}

void	RAMModule::makeCurUsed(void)
{
	FILE	*pipe = popen("top -l 1 -n0 | grep -E \"^Phys\"", "r");
	char	usage[256];
	char	temp[10];
	char	*t;

	if (!pipe)
		return ; // TODO: throw
	while (!feof(pipe))
		fgets(usage, 256, pipe);

	t = strstr(usage, ":") + 2;
	int i = 0;
	for (i = 0; t[i] != ' '; i++)
		temp[i] = t[i];
	temp[i] = '\0';
	_used = temp;

	for (i = 0; i < 10; i++)
		temp[i] = '\0';

	t = strstr(usage, ",") + 2;
	for (i = 0; t[i] != ' '; i++)
		temp[i] = t[i];
	t += i + 1;
	temp[i] = '\0';
	_unused = temp;
	pclose(pipe);
}

std::string		RAMModule::getUsed(void) const {
	return _used;
}

std::string		RAMModule::getUnused(void) const {
	return _unused;
}

std::string		RAMModule::getFullSize(void) const {
	return _fullSize;
}
