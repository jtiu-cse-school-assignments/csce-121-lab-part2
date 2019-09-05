#include <iostream>
#include "ColorButton.h"

using namespace std;

int getRandomColor();

ColorButton::ColorButton(int x, int y, int width, int height, const char *L = 0) :
	Fl_Button(x, y, width, height, L), clickCount(0) {
	this->labelsize(36);
	this->labelfont(FL_HELVETICA_BOLD);
}

/*
  FIXME 1 b:
    Add handle function definition
	  - On a mouse release
      1. set the buttons's background color to a randomly generated 
          color obtained by calling getRandomColor()
      2. increment click count for the button
      3. In the console, output which button is being pressed and 
          the number of times the button has been pressed
    - Otherwise, pass event to parent's handle function
*/

int ColorButton::handle(int event) {
    switch (event) {
        case FL_RELEASE:
            redraw();
        }
    }