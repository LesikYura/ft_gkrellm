// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OSModule.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dpozinen <dpozinen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 19:17:50 by dpozinen          #+#    #+#             //
//   Updated: 2018/10/13 19:17:50 by dpozinen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef OSMODULE_HPP
# define OSMODULE_HPP

#include "IMonitorModule.hpp"
#include "header.hpp"

class	OSModule : public IMonitorModule
{
	private:
		std::string		_name; // Mac OS X
		std::string		_version; // 10.13.3
		std::string		_build; // 17D47
		std::string		_all; // 17D47

	public:
		OSModule();
		OSModule(const OSModule &other);
		OSModule &operator=(const OSModule &other);
		~OSModule();
		void		makeName(void);
		void		makeVersion(void);
		void		makeBuild(void);
		void		makeAll(void);
		void		update(SDL &sdl);
		void		update(Ncurses &nc);
		std::string getName(void) const;
		std::string getBuild(void) const;
		std::string getVersion(void) const;
		std::string getAll(void) const;
};

#endif