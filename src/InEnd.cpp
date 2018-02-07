#include <stdio.h>
#include <SDL2/SDL.h>

//Arrow key surface index.
enum KeyPressSurface
{
  KEY_PRESS_SURFACE_DEFAULT, KEY_PRESS_SURFACE_UP, KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_DOWN, KEY_PRESS_SURFACE_LEFT, KEY_PRESS_SURFACE_TOTAL
};



//The window we use for rendering. 
SDL_Window *gWindow = NULL;

//The surface contained by the window.
SDL_Surface *gScreenSurface = NULL;

SDL_Surface *gKeyPressSurface[KEY_PRESS_SURFACE_TOTAL];

//Initialization proccess. 
bool
init ()
{
  bool success = true;
  //Intialize subsystem
  if (SDL_Init (SDL_INIT_VIDEO) < 0)
    {
      printf ("SDL intialzation error: %s\n", SDL_GetError ());
      success = false;
    }
  else
    {				//create Window
      gWindow =
	SDL_CreateWindow ("Arrow Image", SDL_WINDOWPOS_UNDEFINED,
			  SDL_WINDOWPOS_UNDEFINED, 640, 480,
			  SDL_WINDOW_SHOWN);

      if (gWindow == NULL)
	{
	  printf ("Error during window creation: %s\n", SDL_GetError ());
	  success = false;

	}
      else
	gScreenSurface = SDL_GetWindowSurface (gWindow);

    }

  return success;
}

SDL_Surface *
LoadSurface (const char *Image)
{
  SDL_Surface *PSurface = SDL_LoadBMP (Image);
  if (PSurface == NULL)
    fprintf (stderr, "Error during loading image:%s\n", SDL_GetError ());
  return PSurface;
}



bool
loadMedia ()
{
  char I[300]; 

  for (int i = 0; i < 5; i++) {
    sprintf(I, "./Images/%i", i);
    if ((gKeyPressSurface[i] = LoadSurface(I)) == NULL) 
      return false; 
    
  }
  
  return true;  

}


void
Close ()
{
  //Deallocate Surface 
  for (int i = 0; i < 5; i++)
    {
      SDL_FreeSurface (gKeyPressSurface[i]);
      gKeyPressSurface[i] = NULL;
    };
  //Destroy window 
  SDL_DestroyWindow (gWindow);
  gWindow = NULL;

  //Quit SDL subsystem
  SDL_Quit ();

}
