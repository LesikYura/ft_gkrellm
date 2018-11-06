// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   CPUModule.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dpozinen <dpozinen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/14 10:08:24 by dpozinen          #+#    #+#             //
//   Updated: 2018/10/14 10:08:24 by dpozinen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "CPUModule.hpp"

CPUModule::CPUModule(){
}

CPUModule::~CPUModule(){
}

CPUModule::CPUModule(const CPUModule &other) {
	*this = other;
}

CPUModule &CPUModule::operator=(const CPUModule &other)
{
	_generalInfo = other._generalInfo;
	_userUsage = other._userUsage;
	_sysUsage = other._sysUsage;
	_idle = other._idle;
	return *this;
}

void	CPUModule::makeAll()
{
	makeUsage();
	makeGeneralInfo();
}

void	CPUModule::update(SDL &sdl)
{
	makeUsage();
	(void)sdl;
}

void	CPUModule::update(Ncurses &nc)
{
	// (void)nc;
	makeUsage();
	nc.cpu(_generalInfo, _userUsage);
	nc.graph_cpu(_userUsage);
}

void	CPUModule::makeGeneralInfo()
{
	FILE 	*pipe = popen("sysctl -n machdep.cpu.brand_string", "r");
	char	generalInfo[128];

	if (!pipe)
		return ; // TODO: throw
	while (!feof(pipe))
		fgets(generalInfo, 128, pipe);
	generalInfo[strlen(generalInfo) - 1] = '\0';
	_generalInfo = strstr(generalInfo, "i");
	pclose(pipe);
}

void	CPUModule::makeUsage() // TODO: refactor
{
	FILE *pipe = popen("top -l 1 -n0 | grep -E \"^CPU\"", "r");
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
	t += i + 1;
	temp[i] = '\0';
	_userUsage = temp;

	for (i = 0; i < 10; i++)
		temp[i] = '\0';
	t = strstr(t, " ") + 1;
	for (i = 0; t[i] != ' '; i++)
		temp[i] = t[i];
	temp[i] = '\0';
	t += i + 1;
	_sysUsage = temp;

	for (i = 0; i < 10; i++)
		temp[i] = '\0';
	t = strstr(t, " ") + 1;
	for (i = 0; t[i] != ' '; i++)
		temp[i] = t[i];
	temp[i] = '\0';
	_idle = temp;
	pclose(pipe);
}

std::string	CPUModule::getGeneralInfo(void) const {
	return _generalInfo;
}

std::string	CPUModule::getUserUsage() const {
	return _userUsage;
}

std::string	CPUModule::getSysUsage() const {
	return _sysUsage;
}

std::string	CPUModule::getIdle() const {
	return _idle;
}