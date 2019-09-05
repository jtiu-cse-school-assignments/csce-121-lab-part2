#pragma once
//#include <Windows.H>
#include <FL/Fl_Window.H>
#include "ColorButton.h"

class ColorWindow : public Fl_Window {
	ColorButton* buttonOne;
	ColorButton* buttonTwo;

public:
	ColorWindow(int, int);
};