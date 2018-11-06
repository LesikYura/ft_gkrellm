// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IMonitorModule.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dpozinen <dpozinen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 17:40:28 by dpozinen          #+#    #+#             //
//   Updated: 2018/10/13 17:40:29 by dpozinen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef IMONMOD_HPP
# define IMONMOD_HPP

#include "header.hpp"

class	IMonitorModule
{
	public:
		virtual void	update(Ncurses &nc) = 0;
		virtual void	update(SDL &sdl) = 0;
		virtual void	makeAll(void) = 0;
		virtual 		~IMonitorModule() {};
};

#endif