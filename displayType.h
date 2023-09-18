#include "Game.h"

class displayType {
protected:
    Game* game; 

public:
    // constructor
    displayType(Game* game) : game{game} {}

    virtual int get_id() = 0; // return display type
    virtual void update() = 0;
};

class textDisplay : public displayType{
public: 
    // constructors
    textDisplay(Game* game) : displayType(game) {};

    void update() override;
    int get_id() override; 
};

