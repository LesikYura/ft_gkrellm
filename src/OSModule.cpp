// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OSModule.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dpozinen <dpozinen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 19:34:51 by dpozinen          #+#    #+#             //
//   Updated: 2018/10/13 19:34:51 by dpozinen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "OSModule.hpp"
#include "header.hpp"

// TODO: operator= & copy constructor

OSModule::OSModule() {
}

OSModule::~OSModule() {
}

OSModule::OSModule(const OSModule &other) {
	*this = other;
}

OSModule &OSModule::operator=(const OSModule &other)
{
	_name = other._name;
	_version = other._version;
	_build = other._build;
	_all = other._all;
	return *this;
}

void	OSModule::makeName(void)
{
	char	name[50];

	FILE *pipe = popen("sw_vers -productName", "r");
	if (!pipe)
		return ; // TODO: throw
	while (!feof(pipe))
		fgets(name, 50, pipe);
	name[strlen(name) - 1] = '\0';
	pclose(pipe);
	_name = name;
}

void	OSModule::makeVersion(void)
{
	char	version[50];

	FILE *pipe = popen("sw_vers -productVersion", "r");
	if (!pipe)
		return ; // TODO: throw
	while (!feof(pipe))
		fgets(version, 50, pipe);
	version[strlen(version) - 1] = '\0';
	pclose(pipe);
	_version = version;
}

void	OSModule::makeBuild(void)
{
	char	build[50];

	FILE *pipe = popen("sw_vers -buildVersion", "r");
	if (!pipe)
		return ; // TODO: throw
	while (!feof(pipe))
		fgets(build, 50, pipe);
	build[strlen(build) - 1] = '\0';
	pclose(pipe);
	_build = build;
}

void	OSModule::makeAll(void)
{
	makeBuild();
	makeName();
	makeVersion();
	std::stringstream ss;
	ss << _name << " " << _version << " " << _build;
	_all = ss.str();
}

void	OSModule::update(SDL &sdl)
{
	(void)sdl;
}

void	OSModule::update(Ncurses &nc) {
	// (void)nc;
	nc.general(_name, _version, _build);
	return ;
}

std::string OSModule::getName(void) const {
	return _name;
}

std::string OSModule::getVersion(void) const {
	return _version;
}

std::string OSModule::getBuild(void) const {
	return _build;
}

std::string OSModule::getAll(void) const {
	return _all;
}