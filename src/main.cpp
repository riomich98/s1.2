#include <mbed.h>

#include <stdbool.h>

bool isPressed(DigitalIn button) {
  if (button.read() == 1) {
    // if the button is 1 and evaluates to true, the button is not pressed, and false is returned
    return false;
  } else {
    // if the button is pressed, the true is returned
    return true;
  }
}

int main() {
    DigitalOut red(PTB22); // red LED
    DigitalOut green(PTE26); // green LED
    DigitalIn  btnRight(PTC6); // right hand button on board
    DigitalIn  btnLeft(PTA4); // left hand button on board

    while(1) { // while true (always)
      green.write(1); // turn LEDs off at first run
      red.write(1);
        if (isPressed(btnLeft) || isPressed(btnRight)) { // check that any buttons are actually pressed down
        if(isPressed(btnLeft)) { // if left button is pressed down, using isPressed function
            printf("Left Button Pressed"); // print status out to console
            red.write(0); // turn on LED
            wait(0.25);
            red.write(1); // turn off LED
            wait(0.25);
        }
        else if (isPressed(btnRight)) { // if right button is pressed down, using isPressed function
            printf("Right Button Pressed"); // print status out to console
            green.write(0); // turn on LED
            wait(0.25);
            green.write(1); // turn off LED
            wait(0.25);
        }
        else { // turn off all LEDs
          green.write(1);
          red.write(1);
        }
    }
  }
}
