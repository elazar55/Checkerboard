#ifndef MOUSE_H
#define MOUSE_H

#include <SDL.h>

class Mouse
{
public:
    Mouse();
    ~Mouse();
    bool LeftClick();
    void Update();
    int GetX();
    int GetY();
private:
    int x_position;
    int y_position;
    bool current_state;
    bool previous_state;
    Uint32 button_bitmask;
};

#endif // MOUSE_H
