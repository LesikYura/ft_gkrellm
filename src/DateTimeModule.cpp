// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   DateTimeModule.cpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dpozinen <dpozinen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/14 09:39:59 by dpozinen          #+#    #+#             //
//   Updated: 2018/10/14 09:39:59 by dpozinen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "DateTimeModule.hpp"
#include "header.hpp"

DateTimeModule::DateTimeModule() {
}

DateTimeModule::~DateTimeModule() {
}

void	DateTimeModule::makeAll() {
	makeTime();
	makeDate();
}

DateTimeModule::DateTimeModule(const DateTimeModule &other) {
	*this = other;
}
DateTimeModule &DateTimeModule::operator=(const DateTimeModule &other)
{
	_date = other._date;
	_time = other._time;
	return *this;
}

void	DateTimeModule::update(SDL &sdl)
{
	(void)sdl;
	makeTime();
}

void	DateTimeModule::update(Ncurses &nc) {
	// (void)nc;
	makeTime();
	nc.data(_date, _time);
}

void	DateTimeModule::makeDate()
{
	time_t	curTime;
	char	*d;

	time(&curTime);
	d = ctime(&curTime);
	d[11] = '\0';
	_date = d;
}

void	DateTimeModule::makeTime()
{
	time_t	curTime;
	char	*t;

	time(&curTime);
	t = ctime(&curTime);
	t += 11;
	t[8] = '\0';
	_time = t;
}

std::string	DateTimeModule::getDate() const {
	return _date;
}

std::string	DateTimeModule::getTime() const {
	return _time;
}