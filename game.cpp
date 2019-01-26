#include "game.h"

Game::Game()
{
	character_ = new Character(1, Direction::RIGHT, 50, 100, -1, 50);
}

Game::~Game()
{
	delete character_;
}

void Game::Settings()
{
	agk::SetWindowTitle("Single Character");
	agk::SetWindowSize(WIN_WIDTH, WIN_HEIGHT, FULLSCREEN);
	agk::SetWindowPosition(WIN_POS_X, WIN_POS_Y);
	agk::SetWindowAllowResize(ALLOW_RESIZE);
	agk::SetDisplayAspect(static_cast<float>(WIN_WIDTH) / WIN_HEIGHT);
	agk::SetClearColor(101, 146, 214);
	agk::UseNewDefaultFonts(true);
	agk::SetSyncRate(SYNC_RATE, 0);
}

void Game::LoadResources()
{
	character_->LoadResources();
}

void Game::GetInputHandler()
{
	command_ = inputHandler_.Handler();

	if (command_)
		command_->Execute(character_);
}