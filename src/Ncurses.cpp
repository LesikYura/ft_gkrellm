
#include "Ncurses.hpp"

Ncurses::Ncurses(void){}
Ncurses::~Ncurses(void){}

Ncurses::Ncurses(const Ncurses &other) {
	*this = other;
}
Ncurses &Ncurses::operator=(const Ncurses &other)
{
	(void)other;
	return *this;
}

void	Ncurses::create_frame(void)
{
	refresh();
	box(this->win, 0, 0);

	move(4, 2);
	hline('-', 73);

	move(10, 2);
	hline('-', 73);
	wrefresh(win);

	move(18, 2);
	hline('-', 73);

	move(24, 2);
	hline('-', 73);

	move(29, 2);
	hline('-', 73);
	wrefresh(win);
}

void	Ncurses::data(std::string data, std::string time)
{
	// std::string str = "Data : 14.09.18";
	// *str = "Data : 14.09.18";
	move(0, 31);
	printw("SYSTEM INFO");
	move(4, 33);
	printw("GENERAL");
	move(2, 4);
	attron(COLOR_PAIR(4));
	// printw("Data : 14.09.18");
	printw("Data :%s", data.c_str());
	//printw("LEVEL: %d", level);
	attroff(COLOR_PAIR(4));
	move(2, 58);
	attron(COLOR_PAIR(4));
	printw("Time :%s", time.c_str());
	attroff(COLOR_PAIR(4));
}

void Ncurses::general_help(std::string user, std::string host)
{
	move(6, 6);
	attron(COLOR_PAIR(4));
	printw("host ");
	attroff(COLOR_PAIR(4));
	move(6, 36);
	attron(COLOR_PAIR(4));
	printw("->");
	attroff(COLOR_PAIR(4));
	move(6, 50);
	attron(COLOR_PAIR(4));
	printw("%s", host.c_str());
	attroff(COLOR_PAIR(4));

	move(7, 6);
	attron(COLOR_PAIR(4));
	printw("user ");
	attroff(COLOR_PAIR(4));
	move(7, 36);
	attron(COLOR_PAIR(4));
	printw("->");
	attroff(COLOR_PAIR(4));
	move(7, 50);
	attron(COLOR_PAIR(4));
	printw("%s", user.c_str());
	attroff(COLOR_PAIR(4));
}


void Ncurses::general(std::string name, std::string ver, std::string buld)
{
	(void)buld;

	move(8, 6);
	attron(COLOR_PAIR(4));
	printw("version ");
	attroff(COLOR_PAIR(4));
	move(8, 36);
	attron(COLOR_PAIR(4));
	printw("->");
	attroff(COLOR_PAIR(4));
	move(8, 50);
	attron(COLOR_PAIR(4));
	// printw("Mac OS X 10.13.3");
	printw("%s", name.c_str());
	attroff(COLOR_PAIR(4));
	move(8, 59);
	attron(COLOR_PAIR(4));
	// printw("Mac OS X 10.13.3");
	printw("| %s", ver.c_str());
	attroff(COLOR_PAIR(4));

	move(10, 35);
	printw("CPU");
}

void Ncurses::cpu(std::string info, std::string u_usage)
{
	move(12, 6);
	attron(COLOR_PAIR(4));
	printw("CPU ");
	attroff(COLOR_PAIR(4));
	move(12, 36);
	attron(COLOR_PAIR(4));
	printw("->");
	attroff(COLOR_PAIR(4));
	move(12, 50);
	attron(COLOR_PAIR(4));
	printw("Intel(R) Core(TM)");
	attroff(COLOR_PAIR(4));

	// move(13, 6);
	// attron(COLOR_PAIR(4));
	// printw("CPU ");
	// attroff(COLOR_PAIR(4));
	// move(13, 36);
	// attron(COLOR_PAIR(4));
	// printw("->");
	// attroff(COLOR_PAIR(4));
	move(13, 50);
	attron(COLOR_PAIR(4));
	printw("%s", info.c_str());
	attroff(COLOR_PAIR(4));

	move(14, 6);
	attron(COLOR_PAIR(4));
	printw("CPU cors ");
	attroff(COLOR_PAIR(4));
	move(14, 36);
	attron(COLOR_PAIR(4));
	printw("->");
	attroff(COLOR_PAIR(4));
	move(14, 50);
	attron(COLOR_PAIR(4));
	printw("4");
	attroff(COLOR_PAIR(4));

	move(15, 6);
	attron(COLOR_PAIR(4));
	printw("CPU threads ");
	attroff(COLOR_PAIR(4));
	move(15, 36);
	attron(COLOR_PAIR(4));
	printw("->");
	attroff(COLOR_PAIR(4));
	move(15, 50);
	attron(COLOR_PAIR(4));
	printw("4");
	attroff(COLOR_PAIR(4));

	move(16, 6);
	attron(COLOR_PAIR(4));
	printw("CPU used ");
	attroff(COLOR_PAIR(4));
	move(16, 36);
	attron(COLOR_PAIR(4));
	printw("->");
	attroff(COLOR_PAIR(4));
	move(16, 50);
	attron(COLOR_PAIR(4));
	printw("%d", atoi(u_usage.c_str()));
	attroff(COLOR_PAIR(4));

	move(18, 35);
	printw("RAM");
}

void Ncurses::ram(std::string all_ram, std::string used, std::string unused)
{
	move(20, 6);
	attron(COLOR_PAIR(4));
	printw("RAM");
	attroff(COLOR_PAIR(4));
	move(20, 36);
	attron(COLOR_PAIR(4));
	printw("->");
	attroff(COLOR_PAIR(4));
	move(20, 50);
	attron(COLOR_PAIR(4));
	printw("%s", all_ram.c_str());
	attroff(COLOR_PAIR(4));

	move(21, 6);
	attron(COLOR_PAIR(4));
	printw("RAM used ");
	attroff(COLOR_PAIR(4));
	move(21, 36);
	attron(COLOR_PAIR(4));
	printw("->");
	attroff(COLOR_PAIR(4));
	move(21, 50);
	attron(COLOR_PAIR(4));
	printw("%s", used.c_str());
	attroff(COLOR_PAIR(4));

	move(22, 6);
	attron(COLOR_PAIR(4));
	printw("RAM free ");
	attroff(COLOR_PAIR(4));
	move(22, 36);
	attron(COLOR_PAIR(4));
	printw("->");
	attroff(COLOR_PAIR(4));
	move(22, 50);
	attron(COLOR_PAIR(4));
	printw("%s", unused.c_str());
	attroff(COLOR_PAIR(4));

	move(24, 33);
	printw("NETWORK");
}

void	Ncurses::net(std::string in, std::string out)
{
	move(26, 6);
	attron(COLOR_PAIR(4));
	printw("in ");
	attroff(COLOR_PAIR(4));
	move(26, 36);
	attron(COLOR_PAIR(4));
	printw("->");
	attroff(COLOR_PAIR(4));
	move(26, 50);
	attron(COLOR_PAIR(4));
	printw("%s", in.c_str());
	attroff(COLOR_PAIR(4));
	
	move(27, 6);
	attron(COLOR_PAIR(4));
	printw("out ");
	attroff(COLOR_PAIR(4));
	move(27, 36);
	attron(COLOR_PAIR(4));
	printw("->");
	attroff(COLOR_PAIR(4));
	move(27, 50);
	attron(COLOR_PAIR(4));
	printw("%s", out.c_str());
	attroff(COLOR_PAIR(4));

	move(29, 33);
	printw("CPU USED");
}

void	Ncurses::graph_cpu(std::string u_usage)
{
	int i = 0;
	if (graph_elem % 10 == 0)
	{
		bzero(ar, 40);
		graph_elem = 0;

		move(39, 2);
		hline(' ', 73);
		move(38, 2);
		hline(' ', 73);
		move(37, 2);
		hline(' ', 73);
		move(36, 2);
		hline(' ', 73);
		move(35, 2);
		hline(' ', 73);
		move(34, 2);
		hline(' ', 73);
		move(33, 2);
		hline(' ', 73);
		move(32, 2);
		hline(' ', 73);
		move(31, 2);
		hline(' ', 73);
		move(30, 2);
		hline(' ', 73);
	}
	ar[graph_elem] = atoi(u_usage.c_str()) % 10;
	while (i < ar[graph_elem])
	{
		move(39 - i, 5 * (graph_elem + 1));
		attron(COLOR_PAIR(1));
		printw("*");
		attroff(COLOR_PAIR(1));
		i++;
	}
	graph_elem++;
	// printw("CPU USED");
}
void	Ncurses::start_ncurses(void)
{
	int start_y = 1;
	int start_x = 1;

	initscr(); // Переход в curses-режим
	this->win = newwin(40, 75, start_y, start_x);
	curs_set(0);
}

int		Ncurses::use_color(void)
{
	if (!has_colors())
	{
		printf("sc_1");
		printw("Terminal does not support color");
		getch();
		return (-1);
	}
	printf("sc_1");
	start_color();
	init_pair(1, 5, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	return (0);
}

void	Ncurses::end_win(void)
{
	endwin(); // Выход из curses-режима. Обязательная команда.
}

// void Ncurses::help(void)
// {
// 	move(37, 2);
// 	printw("1. Move left / right - left / right arrow!");
// 	move(38, 2);
// 	printw("2. Shot / Space button!");
// 	move(39, 2);
// 	printw("3. Exit / ESC button!");
// 	move(40, 2);
// 	printw("4. Cheat_mod / C button!");
// 	move(42, 2);
// 	attron(COLOR_PAIR(2));
// 	printw("HAVE FUN :-)");
// 	attroff(COLOR_PAIR(2));
// }
