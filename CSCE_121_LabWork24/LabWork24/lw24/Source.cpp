#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_GIF_Image.H>
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    srand(time(NULL)); // set random seed based on current time
    vector<string> filenames {"cloudy.gif","fog.gif","lightning.gif","partsunny.gif","rain.gif","sunny.gif"};
    
    char stop = ' ';
    string myFile = "cloudy.gif";
    
    Fl_Window *window = new Fl_Window(640, 480);
    Fl_Button *button = new Fl_Button(0, 0, 200, 200);
    Fl_GIF_Image *img = nullptr;
    
    do {
        string filename = filenames.at(rand() % filenames.size());
        // Start add code for image on button
        if(img) delete img;
        img = new Fl_GIF_Image(myFile.c_str());
        
        if (img->w() == 0 || img->h() == 0 || img->d() == 0) {
            cerr << "Error loading image.\nPress enter to close...";
            cin.get();
            exit(1);
        }
        button->image(*img);
        window->show(argc, argv);
        
        //return Fl::run();
        // End code for image on button
        cout << "Do it again? (y/n) ";
        cin >> stop;
    } while ('n' != tolower(stop));
    
    return Fl::run();
}