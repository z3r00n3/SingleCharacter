#pragma once

#include "command.h"
#include "AGK.h"

// Mnemonic names for keys
#define KEY_BACKSPACE 8
#define KEY_TAB 9
#define KEY_ENTER 13
#define KEY_SHIFT 16
#define KEY_CONTROL 17
#define KEY_ESCAPE 27
#define KEY_SPACE 32
#define KEY_PAGE_UP 33
#define KEY_PAGE_DOWN 34
#define KEY_END 35
#define KEY_HOME 36
#define KEY_LEFT 37
#define KEY_UP 38
#define KEY_RIGHT 39
#define KEY_DOWN 40
#define KEY_INSERT 45
#define KEY_DELETE 46

#define KEY_0 48
#define KEY_1 49
#define KEY_2 50
#define KEY_3 51
#define KEY_4 52
#define KEY_5 53
#define KEY_6 54
#define KEY_7 55
#define KEY_8 56
#define KEY_9 57

#define KEY_A 65
#define KEY_B 66
#define KEY_C 67
#define KEY_D 68
#define KEY_E 69
#define KEY_F 70
#define KEY_G 71
#define KEY_H 72
#define KEY_I 73
#define KEY_J 74
#define KEY_K 75
#define KEY_L 76
#define KEY_M 77
#define KEY_N 78
#define KEY_O 79
#define KEY_P 80
#define KEY_Q 81
#define KEY_R 82
#define KEY_S 83
#define KEY_T 84
#define KEY_U 85
#define KEY_V 86
#define KEY_W 87
#define KEY_X 88
#define KEY_Y 89
#define KEY_Z 90

#define KEY_F1 112
#define KEY_F2 113
#define KEY_F3 114
#define KEY_F4 115
#define KEY_F5 116
#define KEY_F6 117
#define KEY_F7 118
#define KEY_F8 119

#define KEY_SEMICOLON 186
#define KEY_EQUAL 187
#define KEY_COMMA 188
#define KEY_HYPHEN 189
#define KEY_PERIOD 190
#define KEY_SLASH 191
#define KEY_APOSTROPHE 192
#define KEY_SQUARE_BRACKET_OPEN 219
#define KEY_SQUARE_BRACKET_CLOSE 221
#define KEY_SHARP 222

class InputHandler
{
public:
	InputHandler();
	~InputHandler();
	Command* Handler();

private:
	Command* keyIdle_;
	Command* keyTurnRight_;
	Command* keyTurnLeft_;
	Command* keyLeft_;
	Command* keyRight_;
	Command* keySpace_;
};