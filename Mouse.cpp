#include "Mouse.h"

Mouse::Mouse()
{
}

Mouse::~Mouse()
{
}

bool Mouse::LeftClick()
{
    if (current_state && !previous_state) return true;
                                          return false;
}

void Mouse::Update()
{
    if (button_bitmask & SDL_BUTTON_LEFT) previous_state = true;
                                     else previous_state = false;

    button_bitmask = SDL_GetMouseState(&x_position, &y_position);

    if (button_bitmask & SDL_BUTTON_LEFT) current_state = true;
                                     else current_state = false;
}

int Mouse::GetX()
{
    return x_position;
}

int Mouse::GetY()
{
    return y_position;
}
