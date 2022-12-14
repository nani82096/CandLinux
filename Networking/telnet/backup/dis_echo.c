
#include "header.h"

void dis_echo(int mode)
{
    int status;
    static struct termios old;
    static struct termios new;

    if (mode) {
     status = tcgetattr(STDIN_FILENO, &old);
    if (status == -1)
        handle_error("tcgetattr");
        //if (old.c_lflag == ECHO)
            new.c_lflag = old.c_lflag & ~ECHO;
        new.c_lflag |= ECHONL;

        status = tcsetattr( STDIN_FILENO, TCSANOW, &new);
        if (status == -1)
            handle_error("tcgetattr");
    }
    else {
    status = tcsetattr( STDIN_FILENO, TCSANOW, &old);
    if (status == -1)
        handle_error("tcgetattr");
    }

}
