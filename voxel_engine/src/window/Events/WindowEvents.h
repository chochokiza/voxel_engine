#pragma once

#include "../Window.h"


typedef unsigned int uint;

class WindowEvents
{
public:
	static bool* _keys;
	static uint numberOfKeys;
	static uint* _frames;
	static uint numberOfFrames;
	static uint _current;
	static float deltaX;
	static float deltaY;
	static float x;
	static float y;
	static bool _cursor_loced;
	static bool _cursor_started;


	static int Initialize();
	static void PullEvents();

	static bool Pressed(int keycode);
	static bool JustPressed(int code);

	static bool Clicked(int button);
	static bool JustClicked(int button);

};