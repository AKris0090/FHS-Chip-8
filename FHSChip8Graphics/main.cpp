#include "CPU.h"
#include "Display.h"


Display WINDOW;
CPU CORE;

using namespace std;

int main(int argc, char **arcgv) {
    
    /* Pseudocode Implementation (Implement as development progresses)
     *
     *  // Set up render system and register input callbacks
     *  setupGraphics();
     *  setupInput();
     *
     *   // Initialize the Chip8 system and load the game into the memory
     *   core.initialize();
     *   core.loadGame("pong");
     *
     *   // Emulation loop
     *   for(;;){
     *   // Emulate one cycle
     *   core.emulateCycle();
     *   // If the draw flag is set, update the screen
     *   if(myChip8.drawFlag)
     *       drawGraphics();
     *       (THIS IS window.updateDisplay();)
     *   }
     *   // Store key press state (Press and Release)
     *   core.setKeys();
     *   }
     */


    setupGraphics();
    setupInput();

    CORE.initialize();

    //FINISH IMPLEMENTING
    CORE.loadGame("pong");

    for (;;) {
        CORE.emulateCycle();
        if (CORE.drawFlag == true) {
            WINDOW.updateDisplay(CORE.getDisplayArray());
        }

        CORE.setKeys();
    }


    return 0;
}

void setupGraphics() {
    WINDOW.initDisplay();
}

void setupInput() {

}
