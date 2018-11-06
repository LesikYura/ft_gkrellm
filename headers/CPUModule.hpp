// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   CPUModule.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dpozinen <dpozinen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/14 10:08:37 by dpozinen          #+#    #+#             //
//   Updated: 2018/10/14 10:08:38 by dpozinen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP

#include "header.hpp"

class	CPUModule : public IMonitorModule
{
	private:
		std::string		_generalInfo; // i5-6500 CPU @ 3.20GHz
		std::string		_userUsage; // 26.43%
		std::string		_sysUsage; // 31.3%
		std::string		_idle; // 42.52%

	public:
		CPUModule();
		CPUModule(const CPUModule &other);
		CPUModule &operator=(const CPUModule &other);
		~CPUModule();

		void			makeAll(void);
		void			update(SDL &sdl);
		void			update(Ncurses &nc);
		void			makeGeneralInfo(void);
		void			makeUsage(void);
		std::string		getUserUsage() const;
		std::string		getSysUsage() const;
		std::string		getIdle() const;
		std::string		getGeneralInfo(void) const;

};

#endif