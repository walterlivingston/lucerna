#include <iostream>
#include <SDL.h>

#include "Application.h"

// You shouldn't really use this statement, but it's fine for small programs
using namespace std;

// You must include the command line parameters for your main function to be recognized by SDL
int main(int argc, char** args) {
    Application app("Test", 1280, 720);

	app.loop();

	// Quit SDL
	SDL_Quit();
	
	// End the program
	return 0;
}