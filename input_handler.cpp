#include "input_handler.h"

InputHandler::InputHandler()
{
	keyIdle_      = new IdleCommand();
	keyTurnLeft_  = new TurnLeftCommand();
	keyTurnRight_ = new TurnRightCommand();
	keyLeft_      = new RunLeftCommand();
	keyRight_     = new RunRightCommand();
	keySpace_     = new JumpCommand();
}

InputHandler::~InputHandler()
{
	delete keyIdle_;
	delete keyTurnLeft_;
	delete keyTurnRight_;
	delete keyLeft_;
	delete keyRight_;
	delete keySpace_;
}

Command* InputHandler::Handler()
{
	if (agk::GetRawKeyReleased(KEY_LEFT) || agk::GetRawKeyReleased(KEY_RIGHT)) return keyIdle_;
	if (agk::GetRawKeyPressed(KEY_LEFT)) return keyTurnLeft_;
	if (agk::GetRawKeyPressed(KEY_RIGHT)) return keyTurnRight_;
	if (agk::GetRawKeyState(KEY_LEFT)) return keyLeft_;
	if (agk::GetRawKeyState(KEY_RIGHT)) return keyRight_;
	if (agk::GetRawKeyPressed(KEY_SPACE)) return keySpace_;

	return NULL;
}
