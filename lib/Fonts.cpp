#include "../inc/Fonts.hpp"
#include "../inc/Framework.hpp"

Fonts::~Fonts(){
	if(!this->ListFonts.empty()){
		size_t sizeListFonts = this->ListFonts.size();

		for(size_t i = 0; i < sizeListFonts; ++i){
			this->ListFonts[i].Close();
			this->ListFonts[i].Destroy();
		}
		ListFonts.clear();
	}
}

void Fonts::PushListFonts(std::string _file,const int _sizeFont){
	LFonts auxSF;

	auxSF.font = TTF_OpenFont(_file.c_str(),_sizeFont);

	if(!auxSF.font){
		SDL_Exception(__FILE__,SDL_GetError(),__LINE__);
	}

	this->ListFonts.push_back(auxSF);
}

void Fonts::SetUp(){
	DIR *dir; struct dirent *diread;
	std::string aux,file = "../res/fonts/";
	size_t index = 0;

	if((dir = opendir(file.c_str())) != NULL ){
		try{
			while((diread = readdir(dir)) != NULL){
				aux.assign(diread->d_name);
				if(aux[0] != '.'){
					PushListFonts((file+aux),this->size[index]);
					++index;
				}
			}
			closedir (dir);
		}catch(SDL_Exception const &e){
			closedir (dir);
			throw SDL_Exception(__FILE__,e.what(),__LINE__);
		}
	}else{
		throw SDL_Exception(__FILE__,"No such file or directory Fonts",__LINE__);
	}
}

void Fonts::SetFontTexture(std::string _dataType,SDL_Renderer* _renderer,int _indexFont,SetColor _color,int _position){
	SDL_Surface* fontSurface = nullptr;
	SDL_Color setColor = {_color.r,_color.g,_color.b,OPACITY};

	std::string text = (!isalpha(_dataType.front()))? "FPS >> "+ _dataType.substr(0,_dataType.size()-4) : _dataType;

	fontSurface = TTF_RenderText_Solid(this->ListFonts[_indexFont].font,text.c_str(),setColor); 
    this->ListFonts[_indexFont].fontTexture = SDL_CreateTextureFromSurface(_renderer,fontSurface);  
    
   switch(_position){
   		case UP_LEFT:
   			this->ListFonts[_indexFont].dest = {10,21, fontSurface->w, fontSurface->h};
   		break;
   		case UP_CENTER:
   			this->ListFonts[_indexFont].dest = {abs((fontSurface->w/2)-(this->W_WIDTH/2)), 21, fontSurface->w, fontSurface->h};
   		break;
   		case UP_RIGHT:
   			this->ListFonts[_indexFont].dest = {(this->W_WIDTH)-(fontSurface->w+10), 21, fontSurface->w, fontSurface->h};
   		break;
   		case DOWN_LEFT:
   			this->ListFonts[_indexFont].dest = {20,(this->W_HEIGHT-(fontSurface->h+21)), fontSurface->w, fontSurface->h};
   		break;
   		case DOWN_CENTER:
   			this->ListFonts[_indexFont].dest = {abs((fontSurface->w/2)-(this->W_WIDTH/2)),(this->W_HEIGHT-(fontSurface->h+21)), fontSurface->w, fontSurface->h};
   		break;
   		case DOWN_RIGHT:
   			this->ListFonts[_indexFont].dest = {(this->W_WIDTH)-(fontSurface->w+20), (this->W_HEIGHT-(fontSurface->h+21)), fontSurface->w, fontSurface->h};
   		break;

   }

    SDL_FreeSurface(fontSurface);
}


