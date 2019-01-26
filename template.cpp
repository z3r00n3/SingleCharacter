// Includes
#include "template.h"

// Namespace
using namespace AGK;

app App;

app::app()
{

}

void app::Begin()
{
	game.Settings();
	game.LoadResources();
}

int app::Loop()
{
	agk::Print(agk::ScreenFPS());
	agk::Print(agk::GetSeconds());

	game.GetInputHandler();

	agk::Sync();

	return 0; // return 1 to close app
}

void app::End()
{
	agk::DeleteAllSprites();
	agk::DeleteAllImages();
	//agk::DeleteAllText();
}
