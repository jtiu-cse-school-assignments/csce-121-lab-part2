#include <Windows.h>
#include <FL/Fl.h>
#include <FL/Fl_Window.h>
#include <FL/Fl_Box.H>
#include <FL/Fl_JPEG_Image.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    
    Fl_JPEG_Image img("img.jpg");
    //Fl_JPEG_Image img("folder/tex.jpg");
    if (img.w() == 0 || img.h() == 0 || img.d() == 0) {
        cerr << "Error loading image.\nPress enter to close...";
        cin.get();
        exit(1);
    }
    
    Fl_Window *window = new Fl_Window(img.w(), img.h());
    
    Fl_Box *box = new Fl_Box(0, 0, img.w(), img.h());
    box->image(img);

    //Fl_Box *box2 = new Fl_Box(100, 100, 200, 200, "Some overlay text here");
    //box2->labelfont(FL_BOLD);
    //box2->labelsize(36);

    window->show(argc, argv);
    return Fl::run();
}








