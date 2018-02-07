#include <SDL2/SDL.h>
#include <stdio.h>
#include "InEnd.h"


#define EVENT_QUEUE_IS_EMPTY 0

SDL_Rect dstrect = {200, 200 , 50, 50}; 
SDL_Rect srcrect = {0, 0, 100, 100 }; 

int
main (int argc, char *argv[])
{
  bool Quit = false;
  SDL_Event s;
  

  if (!init ()) {
    fprintf (stderr, "Error during initilization\n");
    return -1;
  }
  else {
    if (!loadMedia ()) {
      fprintf (stderr, "Error during loading media:\n");
      return -1;
    }
    else {
      //Print instruction on window surface
      SDL_BlitSurface(gKeyPressSurface[0], NULL, gScreenSurface, NULL);    
      SDL_UpdateWindowSurface(gWindow); 
      
      //Main program loop. 
      while (!Quit) {
	//Obtain events from event queue.                               
	while (SDL_PollEvent (&s) != EVENT_QUEUE_IS_EMPTY) {
	  //quit program
	  if (s.type == SDL_QUIT) {
	    Quit = true;
	    break;
	  }
	  //key press events. 
	  if (s.type == SDL_KEYDOWN) {
	    switch (s.key.keysym.sym) {
	      case SDLK_UP:
	        SDL_BlitSurface (gKeyPressSurface[1], NULL,
			       gScreenSurface, NULL);
                SDL_UpdateWindowSurface(gWindow); 
                break; 
              
              case SDLK_RIGHT: 
                SDL_BlitSurface(gKeyPressSurface[2], &srcrect, gScreenSurface, &dstrect); 
                SDL_UpdateWindowSurface(gWindow); 
                break; 
                    
              case SDLK_DOWN: 
                SDL_BlitSurface(gKeyPressSurface[3], NULL, gScreenSurface, NULL); 
                SDL_UpdateWindowSurface(gWindow); 
                break;         
              case SDLK_LEFT:  
                SDL_BlitSurface(gKeyPressSurface[4], NULL, gScreenSurface, NULL); 
                SDL_UpdateWindowSurface(gWindow); 
                break;  
             
           }
         }
       }
     }  
   } 
  }  
  Close(); 
  
  return 0;   

}
