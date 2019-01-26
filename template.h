#pragma once

// Link to GDK libraries
#include "AGK.h"
#include "game.h"

#define DEVICE_WIDTH 1000
#define DEVICE_HEIGHT 600
#define DEVICE_POS_X 200
#define DEVICE_POS_Y 50
#define FULLSCREEN false

// used to make a more unique folder for the write path
#define COMPANY_NAME "My Company"

// Global values for the app
class app
{
private:
	Game game;

public:

	// constructor
	app();

	// main app functions - mike to experiment with a derived class for this..
	void Begin();
	int Loop();
	void End();
};

extern app App;

// Allow us to use the LoadImage function name
#ifdef LoadImage
 #undef LoadImage
#endif