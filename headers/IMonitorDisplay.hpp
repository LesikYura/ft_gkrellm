// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IMonitorDisplay.hpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dpozinen <dpozinen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 17:44:02 by dpozinen          #+#    #+#             //
//   Updated: 2018/10/13 17:44:03 by dpozinen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef IMONDISP_HPP
# define IMONDISP_HPP
# include <iostream>

class IMonitorDisplay
{
	// public:
		virtual void create_frame(void) = 0;
		virtual int use_color(void) = 0;
		virtual void end_win(void) = 0;
		// void	score(int score, int level, int life, int enem, int hp);
		// void	help(void);
		virtual void data(std::string data, std::string time) = 0;
		virtual void general(std::string name, std::string ver, std::string buld) = 0;
		virtual void ram(std::string all_ram, std::string used, std::string unused) = 0;
		virtual void cpu(std::string info, std::string u_usage) = 0;
		// virtual ~IMonitorDisplay() {};
};

#endif
