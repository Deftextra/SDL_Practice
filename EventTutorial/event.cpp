#include <stdio.h>
#include <SDL2/SDL.h>
#include "../InEnd.h"


int
main (int argc, char *argv[])
{
  bool quite = false;
  SDL_Event EventBuffer;

  //Start us SDL and create window. 
  if (!init ())
    fprintf (stderr, "Error during intialization");


  else
    {
      //Load media
      if (!loadMedia ("../Images/hello_world.bmp"))
	fprintf (stderr, "Error during loading media");
      else
	{
	  //Main Program loop.
	  while (!quite)
	    {
	      //Test for Events on Event queu. 
	      while ((SDL_PollEvent (&EventBuffer) == 1) && !quite)
		{
		  switch (EventBuffer.type)
		    {
		      //Shut down Program
		    case SDL_QUIT:
		      quite = true;
		      break;

		    case SDL_KEYDOWN:
		      if (EventBuffer.key.keysym.sym == SDLK_UP)
			printf ("You pressed the up key\n");
		    default:
		      break;
		    }
		}
	    }
	}
    }

  closeClosed ();
  return 0;
}
