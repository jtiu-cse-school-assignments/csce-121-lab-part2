#pragma once
//#include <Windows.H>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>

class ColorButton : public Fl_Button {
	int clickCount;

public:
	ColorButton(int x, int y, int width, int height, const char *L);

	// FIXME 1 a: Uncomment the following line
	int handle(int event);

};