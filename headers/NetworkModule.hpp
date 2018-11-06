// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NetworkModule.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dpozinen <dpozinen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/14 18:08:45 by dpozinen          #+#    #+#             //
//   Updated: 2018/10/14 18:08:46 by dpozinen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NETWORKMOD_HPP
# define NETWORKMOD_HPP

#include "IMonitorModule.hpp"

class	NetworkModule : public IMonitorModule
{
	private:
		std::string	_inPackets;
		std::string	_outPackets;

	public:
		NetworkModule();
		NetworkModule(const NetworkModule &other);
		NetworkModule &operator=(const NetworkModule &other);
		~NetworkModule();
		void	makeAll(void);
		void	makeInOut(void);
		void	update(Ncurses &nc);
		void	update(SDL &sdl);
		std::string	getInPackets(void) const;
		std::string	getOutPackets(void) const;
};

#endif