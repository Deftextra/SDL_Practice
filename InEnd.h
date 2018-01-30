#ifndef _INEND

#define _INEND 


//The Window we'll be rendering to 
static SDL_Window* gWindow; 

//The surface contained by the Window
static SDL_Surface* gScreenSurface; 

//The Image we'll load and show on the screen 
static SDL_Surface* gHelloWorld; 

//Starts up SDL and creates window 
bool init(); 

//Loads Media 
bool loadMedia(); 

//Frees Media and shuts down SDL
void closeClosed(); 

#endif /*_INEND */
