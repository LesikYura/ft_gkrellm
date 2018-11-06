#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpozinen <dpozinen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 09:34:59 by dpozinen          #+#    #+#              #
#    Updated: 2018/10/01 09:34:59 by dpozinen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_gkrellm

SRC = main.cpp OSModule.cpp HostUserModule.cpp DateTimeModule.cpp \
CPUModule.cpp RAMModule.cpp Ncurses.cpp NetworkModule.cpp SDL.cpp

SRCDIR = src

SRCS = $(addprefix $(SRCDIR)/, $(SRC:.cpp=.o))

NCUR = -lncurses

HRSDIR = headers

OBJDIR = objects

OBJS = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

FLAGS = -Wall -Werror -Wextra -g

INCLUDES	=	-I./frameworks/SDL2.framework/Versions/A/Headers \
				-I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
				-I./frameworks/SDL2_image.framework/Versions/A/Headers \
				-I./frameworks/SDL2_mixer.framework/Headers \
				-I./frameworks/SDL2_net.framework/Headers \
				-F./frameworks
FRAMEWORKS	=	-F./frameworks \
				-rpath ./frameworks \
				-framework OpenGL -framework AppKit -framework OpenCl \
				-framework SDL2 -framework SDL2_ttf -framework SDL2_image \
				-framework SDL2_mixer -framework SDL2_net

SDL_FRM = -framework SDL2 -F /Library/Frameworks/ ./SDL2_ttf/SDL2_ttf

SDL_INC = -I /Library/Frameworks/SDL2.framework/Headers/ -I SDL_ttf/

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS) $(HRSDIR)/*
	@clang++ $(FLAGS) -lncurses $(OBJS) -o $(NAME) -I $(HRSDIR) $(FRAMEWORKS)

$(OBJS) : $(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(HRSDIR)/*
	@clang++ $(FLAGS) -o $@ -c $< -I $(HRSDIR) $(INCLUDES)

$(OBJDIR):
	@mkdir $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean $(NAME)