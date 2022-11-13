#include "../inc/Framework.hpp"

int main(int , char** ){ //SDL_main

	char* errorMessage = new (std::nothrow) char[10000];
		
	Framework Solid(800,500,"Cube","KevinHGX");
			
	try{

		Solid.SetUp();

		while(Solid.GetExitWindowF()){
			Solid.Event();	
			Solid.Update();
			Solid.Clean();
			Solid.Render();
		}

		Solid.~Framework();

	}catch(std::bad_alloc &ex){

		delete[] errorMessage;
		errorMessage = nullptr;

		std::cerr<<"Out memory"<<std::endl;

		Solid.~Framework();
		exit(1);
	}

	delete[] errorMessage;
	errorMessage = nullptr;


	return 0;
}
