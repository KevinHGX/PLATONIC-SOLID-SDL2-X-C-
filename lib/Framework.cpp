#include "../inc/Framework.hpp"
#include "../inc/Colors.hpp" 
#include "../inc/Timer.hpp"

Framework::~Framework(){

	delete mesh;
	mesh = nullptr;

	delete fonts;
	fonts = nullptr;

	delete[] this->colorBuffer;
	this->colorBuffer = nullptr;

	SDL_DestroyTexture(colorBufferTexture);
	this->colorBufferTexture = nullptr;

	delete window;
	window = nullptr;
}

void Framework::SetUp(){

	try{
		window->InitSDL();
		window->GenerateWindow();
		this->colorBuffer = new (std::nothrow) Uint32[window->setting.WIDTH * window->setting.HEIGHT];
		this->colorBufferTexture = SDL_CreateTexture(window->GetRenderer(),
												SDL_PIXELFORMAT_ARGB8888,
												SDL_TEXTUREACCESS_STREAMING,
												window->setting.WIDTH,
												window->setting.HEIGHT);
		mesh->SetUp(this->Object+".obj");
		fonts->SetUp();

	}catch(SDL_Exception const &e){
		window->setting.exit = false;
		std::cerr<<"SDL_Exception: "<<e.what()<<std::endl;
	}

	time.fpsTimer.start();
	time.capTimer.start();
	fonts->SetFontTexture(this->Object,window->GetRenderer(),2,(color = SDL_WHITE),UP_CENTER);
	fonts->SetFontTexture(this->Author,window->GetRenderer(),0,(color = SDL_WHITE),DOWN_RIGHT);

	this->rect[0] = {10,10,window->setting.WIDTH-20,window->setting.HEIGHT-20};
	this->rect[1] = {7,(window->setting.HEIGHT/2)-25,5,(window->setting.HEIGHT/2)-20};
	this->rect[2] = {(window->setting.WIDTH-15),30,5,(window->setting.HEIGHT/2)-20};
	
}

void Framework::Event(){
	SDL_PollEvent(&event);

	switch(event.type){
		case SDL_QUIT:
			window->setting.exit = false;
		break;
	}
}

void Framework::Update(){
	this->time.capTimer.start();
	this->time.Update();
	mesh->Update();
}


void Framework::DrawSolid(){
	size_t sizeT = mesh->GetSizeTriangle();
	for (size_t i = 0; i < sizeT; ++i){
		DrawTriangle(
			mesh->returnX(i,0),
            mesh->returnY(i,0),
            mesh->returnX(i,1),
            mesh->returnY(i,1),
            mesh->returnX(i,2),
            mesh->returnY(i,2),
			WHITE);
	}
}

void Framework::DrawTriangle(int _x0,int _y0,int _x1,int _y1,int _x2,int _y2,unsigned int _color){
	DrawLine(_x0, _y0, _x1, _y1,_color);
    DrawLine(_x1, _y1, _x2, _y2,_color);
    DrawLine(_x2, _y2, _x0, _y0,_color);
}


void Framework::Clean(){
	
	int posUp = window->setting.WIDTH/5;

	DrawLine((posUp*4),0,(posUp),window->setting.HEIGHT,RED);

	size_t size_H = static_cast<size_t>(window->setting.HEIGHT);
	size_t size_W = static_cast<size_t>(window->setting.WIDTH);

	for (size_t y = 0; y < size_H; ++y){

		for (size_t x = 0; x < size_W; ++x){
			size_t index = (size_W * y) + x;
			
			this->colorBuffer[index] = static_cast<Uint32>(BLACK);
			
		}
	}

	DrawSolid();
}

void Framework::Extras(){

	SDL_SetRenderDrawColor(window->GetRenderer(), 255,255,255, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawRect(window->GetRenderer(),&this->rect[0]);	

	SDL_SetRenderDrawColor(window->GetRenderer(), 0,0,0,100);
	SDL_RenderFillRect(window->GetRenderer(),&this->rect[1]);	
	SDL_RenderFillRect(window->GetRenderer(),&this->rect[2]);	
}

void Framework::Render(){

	SDL_Rect aux;

	SDL_SetRenderDrawColor(window->GetRenderer(), 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(window->GetRenderer());

	SDL_UpdateTexture(this->colorBufferTexture,NULL,this->colorBuffer,window->setting.WIDTH * sizeof(Uint32));
	SDL_RenderCopy(window->GetRenderer(),this->colorBufferTexture,NULL,NULL);
	
	SDL_RenderCopy(window->GetRenderer(),fonts->GetFontTexture(2),NULL,&(aux = fonts->GetFontDest(2)));//Object
	SDL_RenderCopy(window->GetRenderer(),fonts->GetFontTexture(0),NULL,&(aux = fonts->GetFontDest(0)));//Author

	fonts->SetFontTexture(std::to_string(this->time.avgFPS),window->GetRenderer(),4,(this->color = SDL_WHITE),DOWN_LEFT);
	SDL_RenderCopy(window->GetRenderer(),fonts->GetFontTexture(4),NULL,&(aux = fonts->GetFontDest(4)));//FPS

	Extras();

	SDL_RenderPresent(window->GetRenderer());
	this->time.Delay();
}

//-----------------------------------------

void Framework::DrawPixel(int _x,int _y,unsigned int _color){
	if((_x >= 0) && (_x < window->setting.WIDTH) && (_y >= 0) && (_y < window->setting.HEIGHT)){
		this->colorBuffer[(window->setting.WIDTH * _y) +_x] = static_cast<Uint32>(_color);
	}
}

void Framework::DrawLine(int _x1,int _y1,int _x2,int _y2,unsigned int _color){
	
    float dX = _x2 - _x1;
    float dY = _y2 - _y1;

    int longestSideLength = abs(dY / dX) < 1 ? abs(dX) : abs(dY);

    float xInc = dX / longestSideLength;
    float yInc = dY / longestSideLength;

    int pos_x = 0;
    int pos_y  = 0;
		
    for (int i = 0; i < longestSideLength; ++i){
    	pos_x = round(_x1 + (xInc * i));
    	pos_y = round(_y1 + (yInc * i));

    	DrawPixel(pos_x,pos_y,_color);
    }	
}