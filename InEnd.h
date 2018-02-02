#ifndef _INEND

#define _INEND 



//Arrow key Surface index. 
enum KeyPressSurfaces 
{
  KEY_PRESS_SURFACE_DEFAULT, KEY_PRESS_SURFACE_UP, KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_DOWN, KEY_PRESS_SURFACE_LEFT, KEY_PRESS_SURFACE_TOTAL
}; 

//The Window we'll be rendering to 
extern SDL_Window* gWindow; 

//The surface contained by the Window
extern SDL_Surface* gScreenSurface; 

//Surfaces obtained after pressing arrow keys.
extern SDL_Surface* gKeyPressSurface [KEY_PRESS_SURFACE_TOTAL]; 

//Starts up SDL and creates window 
bool init(); 

//Create indvidual key press surfaces. 
SDL_Surface* LoadSurface(const char *Image); 

//Loads Media 
bool loadMedia(); 



//Frees Media and shuts down SDL
void Close(); 

#endif /*_INEND */
