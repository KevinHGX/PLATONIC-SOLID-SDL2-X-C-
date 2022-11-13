#ifndef FONTS_HPP_
#define FONTS_HPP_

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

#define OPACITY 255

extern "C"{
	#include <SDL.h>
	#include <SDL_image.h>
	#include <SDL_ttf.h>
	//------------------
	#include <dirent.h>
}

//-------
#include "Colors.hpp" //struct

struct LFonts{
	TTF_Font* font{nullptr};
	SDL_Texture* fontTexture{nullptr};
	SDL_Rect dest;

	void Close(){
		TTF_CloseFont(font);
		font = NULL;
	}

	void Destroy(){
		SDL_DestroyTexture(fontTexture);
		fontTexture = NULL;
	}
};

class Fonts {
public:
	Fonts()=default;
	Fonts(const int _w,const int _h):W_WIDTH(_w),W_HEIGHT(_h){}
	~Fonts();

	void SetUp();
	void PushListFonts(std::string _file,const int _sizeFont);

	void SetFontTexture(std::string _dataType,
								SDL_Renderer* _renderer,
								int _indexFont,
								SetColor _color,
								int _position);

	inline SDL_Texture* GetFontTexture(const int _index){
		return this->ListFonts[_index].fontTexture;
	}

	inline SDL_Rect GetFontDest(const int _index) const {
		return this->ListFonts[_index].dest;
	}

private:

	int W_WIDTH,W_HEIGHT;
	std::vector<int> size={25,25,50,25,18};
	std::vector<LFonts> ListFonts;

};


#endif //FONTS_HPP_