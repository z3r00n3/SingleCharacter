#include "character.h"

void Character::LoadResources()
{
	agk::LoadImage(ImageID::IDLE,       ANIM_IDLE);
	agk::LoadImage(ImageID::RUN,        ANIM_RUN);
	agk::LoadImage(ImageID::JUMP,       ANIM_JUMP);
	agk::LoadImage(ImageID::SLIDE,      ANIM_SLIDE);
	agk::LoadImage(ImageID::MELEE,      ANIM_MELEE);
	agk::LoadImage(ImageID::SHOOT,      ANIM_SHOOT);
	agk::LoadImage(ImageID::RUN_SHOOT,  ANIM_RUN_SHOOT);
	agk::LoadImage(ImageID::JUMP_MELEE, ANIM_JUMP_MELEE);
	agk::LoadImage(ImageID::JUMP_SHOOT, ANIM_JUMP_SHOOT);
	agk::LoadImage(ImageID::DEAD,       ANIM_DEAD);

	imageID_ = ImageID::IDLE;
	imageFrames_ = static_cast<int>(agk::GetImageWidth(imageID_)) / ANIM_FRAME_WIDTH;
	agk::CreateSprite(spriteID_, imageID_);
	agk::SetSpriteSize(spriteID_, spriteWidth_, spriteHeight_);
	agk::SetSpriteOffset(spriteID_, agk::GetSpriteWidth(spriteID_) / 2, agk::GetSpriteHeight(spriteID_));
	agk::SetSpritePositionByOffset(spriteID_, x_, y_);
	agk::SetSpriteAnimation(spriteID_, ANIM_FRAME_WIDTH, ANIM_FRAME_HEIGHT, imageFrames_);
	agk::PlaySprite(spriteID_, static_cast<float>(imageFrames_), true);

	flip_ = (direction_ == Direction::LEFT ? true : false);
	state_ = CharacterState::IDLE;
}

void Character::Idle()
{
	if (state_ == CharacterState::RUN /*|| (state_ == CharacterState::JUMP && !agk::GetSpritePlaying(spriteID_))*/)
	{
		SwitchAnimation(ImageID::IDLE, CharacterState::IDLE, true);
	}
}

void Character::TurnRight()
{
	if (direction_ == Direction::LEFT)
	{
		flip_ = false;
		direction_ = Direction::RIGHT;
		agk::SetSpriteFlip(spriteID_, flip_, false);
	}
}

void Character::TurnLeft()
{
	if (direction_ == Direction::RIGHT)
	{
		flip_ = true;
		direction_ = Direction::LEFT;
		agk::SetSpriteFlip(spriteID_, flip_, false);
	}
}

void Character::RunRight()
{
	if (state_ == CharacterState::IDLE)
	{
		SwitchAnimation(ImageID::RUN, CharacterState::RUN, true);
	}
}

void Character::RunLeft()
{
	if (state_ == CharacterState::IDLE)
	{
		SwitchAnimation(ImageID::RUN, CharacterState::RUN, true);
	}
}

void Character::Jump()
{
	if (state_ == CharacterState::IDLE || state_ == CharacterState::RUN)
	{
		SwitchAnimation(ImageID::JUMP, CharacterState::JUMP, false);
	}
}

void Character::SwitchAnimation(ImageID::ImageID imageID, CharacterState::CharacterState state, bool loop)
{
	imageID_ = imageID;
	imageFrames_ = static_cast<int>(agk::GetImageWidth(imageID_)) / ANIM_FRAME_WIDTH;
	agk::SetSpriteImage(spriteID_, imageID_);
	agk::SetSpriteAnimation(spriteID_, ANIM_FRAME_WIDTH, ANIM_FRAME_HEIGHT, imageFrames_);
	agk::PlaySprite(spriteID_, static_cast<float>(imageFrames_), loop);
	state_ = state;
}
