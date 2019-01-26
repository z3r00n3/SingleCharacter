#pragma once

#include "AGK.h"

#define ANIM_FRAME_WIDTH  567
#define ANIM_FRAME_HEIGHT 556
#define ANIM_IDLE         "media/images/cyborg/idle.png"
#define ANIM_RUN          "media/images/cyborg/run.png"
#define ANIM_JUMP         "media/images/cyborg/jump.png"
#define ANIM_SLIDE        "media/images/cyborg/slide.png"
#define ANIM_MELEE        "media/images/cyborg/melee.png"
#define ANIM_SHOOT        "media/images/cyborg/shoot.png"
#define ANIM_RUN_SHOOT    "media/images/cyborg/run_shoot.png"
#define ANIM_JUMP_MELEE   "media/images/cyborg/jump_melee.png"
#define ANIM_JUMP_SHOOT   "media/images/cyborg/jump_shoot.png"
#define ANIM_DEAD         "media/images/cyborg/dead.png"

namespace ImageID
{
	enum ImageID
	{
		EMPTY_IMAGE = 0,
		IDLE,
		RUN,
		JUMP,
		SLIDE,
		MELEE,
		SHOOT,
		RUN_SHOOT,
		JUMP_MELEE,
		JUMP_SHOOT,
		DEAD,
	};
}

namespace CharacterState
{
	enum CharacterState
	{
		IDLE = 1,
		RUN,
		JUMP,
		SLIDE,
		MELEE,
		SHOOT,
		RUN_SHOOT,
		JUMP_MELEE,
		JUMP_SHOOT,
		DEAD,
	};
}

namespace Direction
{
	enum Direction
	{
		RIGHT,
		LEFT,
		TOP,
		DOWN,
	};
}

class Character
{
public:	
	// -1.0F - Specified dimension will be automatically calculate
	Character(int spriteID, Direction::Direction direction, float x, float y, float spriteWidth = (-1.0F), float spriteHeight = (-1.0F)) :
		spriteID_(spriteID),
		direction_(direction),
		x_(x),
		y_(y),
		spriteWidth_(spriteWidth),
		spriteHeight_(spriteHeight)
	{}

	void LoadResources();
	void Idle();
	void TurnRight();
	void TurnLeft();
	void RunRight();
	void RunLeft();
	void Jump();

private:
	int spriteID_, imageID_, imageFrames_;
	float x_, y_, spriteWidth_, spriteHeight_;
	bool flip_;
	CharacterState::CharacterState state_;
	Direction::Direction direction_;
	
	void SwitchAnimation(ImageID::ImageID imageID, CharacterState::CharacterState state, bool loop);
};
