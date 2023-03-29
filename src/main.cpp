#include <iostream>
#include <SDL.h>

#include "Application.h"
#include "Entity.h"

Application* app;
Entity* obj1;

void handleEvents(){
	SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            app->stop();
        }
    }
}

void render(){
	obj1->render();
}

// You must include the command line parameters for your main function to be recognized by SDL
int main() {
    app = new Application("Test", 1280, 720);
	obj1 = new Entity("assets/textures/Mario.bmp", app->getRenderer());
	obj1->getRect()->setProperties(20,30,200,200);

	app->setEventCallback(handleEvents);
	app->setRenderCallback(render);

	app->run();

	delete app;
	delete obj1;
	
	// End the program
	return 0;
}