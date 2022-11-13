#ifndef FRAMEWORK_HPP_
#define FRAMEWORK_HPP_

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <cmath>

class SDL_Exception: public std::exception{
	public:
		SDL_Exception(std::string _file,const char* _msg,int _line){
			_file += " ";
			aux.assign(_msg);
			this->message += _file + std::to_string(_line)+" -> " + aux; 
		}

		virtual const char* what() const throw(){
			return this->message.c_str();
		}

	private:
		std::string message = "";
		std::string aux;
};

//own headers CLAS
#include "Window.hpp"
#include "Timer.hpp"
#include "Mesh.hpp"
#include "Fonts.hpp"

enum PositionW{
	UP_LEFT,UP_CENTER,UP_RIGHT,
	DOWN_LEFT,DOWN_CENTER,DOWN_RIGHT
};

struct FPS{
	Timer fpsTimer,capTimer;

	float avgFPS = 0;
	int contFrames = 0,fpsCap = 60, frameTicks;
   	int screenTicksPerFrame = 1000 / fpsCap;
   	//-----------------------

   	void Update(){
   		avgFPS = contFrames/ (fpsTimer.GetTicks() / 1000.f);
   		contFrames++;
   	}

 	void Delay(){
 		frameTicks = capTimer.GetTicks();
 		if(frameTicks < screenTicksPerFrame){
 			SDL_Delay(screenTicksPerFrame - frameTicks);
 		}
 	}  	
};


class Framework{
	public:
		explicit Framework(const int _WIDTH,const int _HEIGHT,std::string _obj = "",std::string _author = ""): Object(_obj), Author(_author){
			window = new Window(_WIDTH,_HEIGHT);
			mesh = new Mesh(_WIDTH,_HEIGHT);
			fonts = new Fonts(_WIDTH,_HEIGHT);
		}

		virtual ~Framework();
		
		void SetUp();
		void Event();
		void Update();
		void Clean();
		void Render();

		void DrawSolid();
		void DrawTriangle(int _x0,int _y0,int _x1,int _y1,int _x2,int _y2,unsigned int _color);
		void DrawPixel(int _posX,int _posY,Uint32 _color);
		void DrawLine(int _x1,int _y1,int _x2,int _y2,unsigned int _color);

		inline bool GetExitWindowF() const {
			return window->GetExitWindow();
		}

		//-----------------------
		void Extras();

	private:

		Window* window;
		std::string Object,Author;
		Uint32* colorBuffer;
		SDL_Texture* colorBufferTexture{nullptr};

		FPS time;
		Mesh* mesh;

		//--------------
		SDL_Event event;
		SetColor color;

		Fonts* fonts;

		SDL_Rect rect[3];
};

#endif