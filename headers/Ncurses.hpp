
#ifndef NCURSES_HPP
# define NCURSES_HPP

#include <ncurses.h>
#include <iostream>
#include "IMonitorDisplay.hpp"

class Ncurses : public IMonitorDisplay
{
	public:
		Ncurses();
		Ncurses(const Ncurses &other);
		Ncurses &operator=(const Ncurses &other);
		~Ncurses();

		WINDOW	*win;
		int		graph_elem;
		int		ar[10];
		void	create_frame(void);
		void	start_ncurses(void);
		int		use_color(void);
		void	end_win(void);
		// void	score(int score, int level, int life, int enem, int hp);
		// void	help(void);
		void	data(std::string data, std::string time);
		void	general(std::string name, std::string ver, std::string buld);
		void	general_help(std::string user, std::string host);
		void	ram(std::string all_ram, std::string used, std::string unused);
		void	cpu(std::string info, std::string u_usage);
		void	net(std::string in, std::string out);
		void 	graph_cpu(std::string u_usage);
};


#endif