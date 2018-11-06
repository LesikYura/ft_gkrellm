// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SDL.hpp			                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dpozinen <dpozinen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 17:46:35 by dpozinen          #+#    #+#             //
//   Updated: 2018/10/13 17:46:35 by dpozinen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SDL_HPP
# define SDL_HPP

#include "IMonitorDisplay.hpp"

#include "SDL_image.h"
// #include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "SDL_net.h"

class	SDL : public IMonitorDisplay
{
  	private:


		// IMonitorGeneralInformation _genInfo;
		// CPU _cpu;
		// DateTime _dataTime;
		// RAM _ram;
		// Network _network;

		// SDL_Texture *_hostnameTextr;
		// SDL_Texture *_usernameTextr;
		// SDL_Texture *_vershonTextr;
		// SDL_Texture *_dataTextr;
		// SDL_Texture *_timeTextr;
		// SDL_Texture *_ramTextr;
		// SDL_Texture *_cpuNameTextr;
		// SDL_Texture *_networInTextr;
		// SDL_Texture *_networOutTextr;

		static bool std_init;

  	public:
	//   SDL_Window *win;
	//   SDL_Renderer *ren;
	//   TTF_Font *font;
	//   SDL_Color color;
	//   SDL_Event event;

	//   int w;
	//   int h;

	  SDL();
	  ~SDL();
	  void end_win(void);
	  int use_color(void);
	  void create_frame(void);
	  void start_sdl(void);
	  void data(std::string data, std::string time);
	  void cpu(std::string info, std::string u_usage);
	  void general(std::string name, std::string ver, std::string buld);
	  void ram(std::string all_ram, std::string used, std::string unused);
};

#endif