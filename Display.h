#include <vector>
#include <memory>
#include "Game.h"

class displayType;

class Display {
private:
    std::vector<std::shared_ptr<displayType>> displays;

public:

    void addDisplay(std::shared_ptr<displayType> display);
    void removeDisplay(std::shared_ptr<displayType> display);
    void notifyDisplays();
    
};

