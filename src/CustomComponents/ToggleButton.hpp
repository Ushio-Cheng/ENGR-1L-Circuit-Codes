#ifndef TOGGLE_BUTTON_HPP
#define TOGGLE_BUTTON_HPP
#include "Button.hpp"
#include "BinaryDeviceState.enum.hpp"

class ToggleButton{
private:
    Button* btn;
    BinaryDeviceState swState;
    ButtonState lastBtnState;
    int* attachedPins;
    int numAttachedPins = 0;
    int maxNumAttachedPins = 13;
    void updateAttachedPins();
public:
    ToggleButton(int pinNum, ButtonType type = PullDOWN, BinaryDeviceState initialState = OFF);
    ~ToggleButton();
    /**
     * Update internals
     * Need to be called on every loop.
     */
    void update();
    BinaryDeviceState getSwitchState();
    void attachPinToSwitchOutput(int pinNum);
};

#endif