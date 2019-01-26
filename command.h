#pragma once

#include "character.h"

class Command
{
public:
	virtual ~Command() {};
	virtual void Execute(Character* character) = 0;
};

class IdleCommand: public Command
{
public:
	virtual void Execute(Character* character) { character->Idle(); }
};

class TurnRightCommand: public Command
{
public:
	virtual void Execute(Character* character) { character->TurnRight(); }
};

class TurnLeftCommand: public Command
{
public:
	virtual void Execute(Character* character) { character->TurnLeft(); }
};

class RunRightCommand: public Command
{
public:
	virtual void Execute(Character* character) { character->RunRight(); }
};

class RunLeftCommand: public Command
{
public:

	virtual void Execute(Character* character) { character->RunLeft(); }
};

class JumpCommand: public Command
{
public:
	virtual void Execute(Character* character) { character->Jump(); }
};