#include <SDL2/SDL.h>
#include <stdio.h> 
#include "InEnd.h"



int main( int argc, char *argv[])
{
	//Start up SDL and create window 
	if ( !init() ) {
		printf( "failed to initialize!\n" ); 
	}
	else {
		//Load media 
		if (!loadMedia() ) {
			printf( "Failed to load media!\n" ); 
		}
		else {
			//Apply the image 
			SDL_BlitSurface( gHelloWorld, NULL, SDL_GetWindowSurface( gWindow ), NULL); 
			//Update the surface 
			SDL_UpdateWindowSurface( gWindow ); 
			//Wait 10 seconds
			SDL_Delay( 10000 ); 
		}
	}
	
	closeClosed(); 
	
	return 0; 	
}	
	
		
	
	
			

