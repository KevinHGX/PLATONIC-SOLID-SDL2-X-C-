#ifndef COLORS_HPP_
#define COLORS_HPP_


/*

ARGB HEXADECIMAL
AA -> TRANSPARENCY
RR -> RED
GG -> GREEN
BB -> BLUE
*/

extern "C"{
	#include <SDL.h>
}


#define BLACK 0xFF000000
#define BLUE_DARK 0xFF14163C
#define YELLOW 0xFFFCA311
#define GRAY 0xFFE5E5E5
#define WHITE 0xFFFFFFFF
#define PINK 0xFFE52241
#define BLUE_D 0xFF0F2241
#define BLUE_SKYE 0XFF33D1FE

//GLITCH
#define RED 0xFFFF0000
#define GREEN 0xFF00FF00
#define BLUE 0xFF0000FF

//fonts
#define SDL_BLACK {0,0,0}
#define SDL_RED {255,0,0}
#define SDL_GREEN {0,255,0}
#define SDL_BLUE {0,0,255}
#define SDL_WHITE {255,255,255}

typedef struct Color{
	Uint8 r,g,b;
}SetColor;


#endif