#include "header.hpp"

#include "OSModule.hpp"
#include "HostUserModule.hpp"
#include "DateTimeModule.hpp"
#include "CPUModule.hpp"
#include "RAMModule.hpp"
#include "NetworkModule.hpp"
#include "Ncurses.hpp" //in header
#include "SDL.hpp"


void initModules(std::vector<IMonitorModule *> *modules)
{
	(*modules).push_back(new DateTimeModule());
	(*modules).push_back(new HostUserModule());
	(*modules).push_back(new OSModule());
	(*modules).push_back(new CPUModule());
	(*modules).push_back(new RAMModule());
	(*modules).push_back(new NetworkModule());

	std::vector<IMonitorModule *>::iterator it;
	for (it = (*modules).begin(); it != (*modules).end(); ++it)
		(*it)->makeAll();
}

void delModules(std::vector<IMonitorModule *> modules)
{
	std::vector<IMonitorModule *>::iterator it;

	for (it = modules.begin(); it != modules.end(); ++it)
		delete *it;
}

bool getFlag(int ac, char **args)
{
	if (ac == 1)
		return false; // default view == ncurses
	if (!strcmp(args[1], "-g"))
		return true;
	return false;
}

int main(int ac, char **argv)
{
	Ncurses nc;
	SDL		sdl;

	unsigned int _usleep;
	_usleep = 40000;

	bool graphical = getFlag(ac, argv);

	if (!graphical)
	{
		nc.graph_elem = 0;

		nc.start_ncurses();
		if (nc.use_color() == -1)
		{
			return (-1);
		}
		nc.create_frame();
		move(42, 2);
		attron(COLOR_PAIR(1));
		printw("Press any button to start!");
		attroff(COLOR_PAIR(1));
		keypad(stdscr, true);
		int k = 0;

		std::vector<IMonitorModule *> modules;
		std::vector<IMonitorModule *>::iterator it;

		initModules(&modules);
		int i = 0;
		while (1)
		{
			k = getch();
			if (k == 27)
				break;
			for (it = modules.begin(); it != modules.end(); ++it)
				(*it)->update(nc);


			timeout(0);
			usleep(_usleep);

			move(42, 2);
			attron(COLOR_PAIR(2));
			printw("ESC to exit                          ");
			attroff(COLOR_PAIR(2));
			i++;
		}
		delModules(modules);
		nc.end_win();
	}
	else
	{
		SDL_Window *win;
		SDL_Renderer *ren;
		TTF_Font *font;
		SDL_Color color;

		int w = 800;
		int h = 400;
		int close = 0;
		srand(time(0));
		unsigned int _usleep;
		_usleep = 40000;

		std::vector<IMonitorModule *> modules;
		std::vector<IMonitorModule *>::iterator it;

		initModules(&modules);

		if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
			return (0);

		//------------->>>>>>>>>>>>>>>>>>>>. WINDOW
		win = SDL_CreateWindow("CPU USAGE", 410, 0, w, h,
							   SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
		if (!win)
		{
			SDL_Quit();
			return (0);
		}

		//-------------------->>>>>>>>>>>>>>>> RENDER
		ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

		//------------->>>>>>>>>>>>>>>>>>>>. TTF
		TTF_Init();
		font = TTF_OpenFont("ARIAL.TTF", 40);

		//------------>>>>>>>>>>>>>>>>>>>>>>> COLOR
		color.r = 255;
		color.g = 255;
		color.b = 255;

		//------------>>>>>>>>>>>>>>>>>>>>>>> SURFACE & RENDER_PRESEBNT

		SDL_Event event;
		SDL_Surface *sur2;
		SDL_Texture *text2;
		SDL_Rect dst2;

		SDL_Surface *sur6;
		SDL_Texture *text6;
		SDL_Rect dst6;

		sur2 = TTF_RenderText_Solid(font, "CPU", color);
		int count = 0;
		while (!close)
		{
			int tw, th;
			tw = th = 0;

			text2 = SDL_CreateTextureFromSurface(ren, sur2);
			SDL_QueryTexture(text2, NULL, NULL, &tw, &th);
			dst2.x = 10;
			dst2.y = 210;
			dst2.w = tw;
			dst2.h = th;

			//-------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>

			int depth = 32;
			int i, j;

			int mas[400];

			i = -1;
			j = 0;

			sur6 = SDL_CreateRGBSurface(0, w, h, depth, 0, 0, 0, 0);
			Uint32 *pixels1 = (Uint32 *)sur6->pixels;
			SDL_LockSurface(sur6);
			int k = -1;
			int z = -1;

			i = -1;
			// while (++i < 400)
			// 	mas[i] = abs(rand() % 100);
			for (it = modules.begin(); it != modules.end(); ++it)
				(*it)->update(sdl);
			CPUModule *cpm;
			for (it = modules.begin(); (cpm = dynamic_cast<CPUModule *>(*it)) == NULL; ++it)
				;
			std::cout << cpm->getUserUsage() << std::endl;
			if (count < 400)
				mas[count] = atoi(cpm->getUserUsage().c_str());
			k = -1;
			z = -1;
			int hex;
			i = count;
			while (++k <= count)
			{
				// std::cout << cpm->getUserUsage() << << std::endl;
				// std::cout << mas[k] << std::endl;
				j = 200;
				z = -1;

				if (mas[k] > 20 && mas[k] < 50)
					hex = 0xdfef2b;
				else if (mas[k] >= 50 && mas[k] < 80)
					hex = 0xffca0c;
				else if (mas[k] >= 80)
					hex = 0xdb1825;
				else
					hex = 0x0cff5d;
				while (++z <= mas[k])
				{
					// if (z > 20 && z < 50)
					pixels1[i + (j - z) * w] = hex;
					// else if (z >= 50 && z < 80)
					// 	pixels1[i + (j - z) * w] = 0xffca0c;
					// else if (z >= 80)
					// 	pixels1[i + (j - z) * w] = 0xdb1825;
					// else
					// 	pixels1[i + (j - z) * w] = 0x0cff5d;
				}
				// pixels1[i + (j - mas[i]) * w] = 200;
			}

			i = -1;
			while (++i < w)
			{
				j = 200;
				pixels1[i + j * w] = 0xffffff;
				pixels1[i + 2 * j * w] = 0xffffff;
				pixels1[i + 3 * j * w] = 0xffffff;
			}
			SDL_UnlockSurface(sur6);
			text6 = SDL_CreateTextureFromSurface(ren, sur6);
			SDL_QueryTexture(text6, NULL, NULL, &tw, &th);

			dst6.x = 0;
			dst6.y = 0;
			dst6.w = tw;
			dst6.h = th;

			//-------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>

			SDL_RenderClear(ren);
			// SDL_RenderCopy(ren, text5, NULL, &dst5);
			SDL_RenderCopy(ren, text6, NULL, &dst6);
			// SDL_RenderCopy(ren, text1, NULL, &dst1);
			SDL_RenderCopy(ren, text2, NULL, &dst2);
			// SDL_RenderCopy(ren, text3, NULL, &dst3);
			// SDL_RenderCopy(ren, text4, NULL, &dst4);
			SDL_RenderPresent(ren);

			//-------------------->>>>>>>>>>>>>>>> EVENT
			// while (!close)
			// {
				while (SDL_PollEvent(&event))
				{
					if (event.type == SDL_QUIT)
						close = 1;
					if (event.type == SDL_KEYDOWN)
						if (event.key.keysym.sym == SDLK_ESCAPE)
							close = 1;
				}
			// }
				timeout(0);
				usleep(_usleep);
				count++;
		}
		TTF_CloseFont(font);
		delModules(modules);
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		SDL_Quit();
		}


		return 0;
}
