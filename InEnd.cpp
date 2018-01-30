#include <stdio.h> 
#include <SDL2/SDL.h> 


//The window we use for rendering. 
static SDL_Window* gWindow = NULL; 

//The surface contained by the window.
static SDL_Surface* gScreenSurface = NULL; 

//The image we will load and show on the screen. 
static SDL_Surface* gHelloWorld = NULL; 


//Initialization proccess. 
bool init()
{
	bool success = true; 
	//Intialize subsystem
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL intialzation error: %s\n", SDL_GetError()); 
		success = false; 
	}	
	else {	//create Window
		gWindow = SDL_CreateWindow("Hello world", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN ); 
		
		if (gWindow == NULL) {
			printf("Error during window creation: %s\n", SDL_GetError());
			success = false; 
		
		}
		else	
			gScreenSurface = SDL_GetWindowSurface( gWindow ); 
		 		
	}
	
	return success;  
} 

bool loadMedia()
{
	bool success = true; 
	gHelloWorld = SDL_LoadBMP ("Images/hello_world.bmp"); 	
	if ( gHelloWorld == NULL) {
		printf("Error loading BMP image: %s\n", SDL_GetError()); 
		success = false; 
	} 
	
	
	return success; 
}
			
void closeClosed()
{
	//Deallocate Surface 
	SDL_FreeSurface( gHelloWorld ); 
	gHelloWorld = NULL; 
	
	//Destroy window 
	SDL_DestroyWindow( gWindow ); 
	gWindow = NULL; 

	//Quit SDL subsystem
	SDL_Quit(); 
	
}	
	

