//
// Created by vinson on 2020/11/27.
//
#include <stdio.h>
#include <termio.h>

int getch(void){
    int cr;
    struct termios nts, ots;
    // get the profile from the current terminal(0 means stand io)
    if (tcgetattr(0, &ots) < 0) {
        return EOF;
    }
    nts = ots;
    // set the terminal to raw origin mode, in this mode data to handle by bytes for every input
    cfmakeraw(&nts);
    // apply the settings from the last step
    if (tcsetattr(0, TCSANOW, &nts) < 0) {
        return EOF;
    }

    cr = getchar();
    // recovery to last mode
    if (tcsetattr(0, TCSANOW, &ots) < 0) {
        return EOF;
    }
    return cr;
}
