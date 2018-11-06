// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HostUserModule.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dpozinen <dpozinen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/14 09:14:26 by dpozinen          #+#    #+#             //
//   Updated: 2018/10/14 09:14:26 by dpozinen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HOSTUSERMOD_HPP
# define HOSTUSERMOD_HPP

#include "header.hpp"

class	HostUserModule : public IMonitorModule
{
	private:
		std::string	_hostName; // e1r6p12.unit.ua
		std::string	_userName; // dpozinen

	public:
		HostUserModule();
		HostUserModule(const HostUserModule &other);
		HostUserModule &operator=(const HostUserModule &other);
		~HostUserModule();
		void		makeAll(void);
		void		update(SDL &sdl);
		void		update(Ncurses &nc);
		void		makeHostName(void);
		void		makeUserName(void);
		std::string	getHostName(void) const;
		std::string	getUserName(void) const;
};

#endif