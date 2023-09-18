#include "Display.h"
#include <memory>
#include "displayType.h"

void Display::addDisplay(std::shared_ptr<displayType> display){
    displays.push_back(display);
}

void Display::removeDisplay(std::shared_ptr<displayType> display){
    for (int i = 0; i < displays.size(); ++i){
        if (display->get_id() == displays[i]->get_id()){
            displays.erase(displays.begin() + i);
        }
    }
}

void Display::notifyDisplays(){
    for (int i = 0; i < displays.size(); ++i){
        displays[i]->update();
    }
}

