#include "header.h"

char *password(void)
{
    struct termios oflags, nflags;
    static char password[64];

    /* disabling echo */
    if (tcgetattr(fileno(stdin), &oflags) != 0)
        handle_error("tcgetattr");
    nflags = oflags;
    nflags.c_lflag &= ~ECHO;
    nflags.c_lflag |= ECHONL;

    if (tcsetattr(fileno(stdin), TCSANOW, &nflags) != 0) 
        handle_error("tcsetattr");
    
    printf("Password: ");
    fgets(password, sizeof(password), stdin);
    password[strlen(password) - 1] = 0;
    //printf("you typed '%s'\n", password);

    /* restore terminal */
    if (tcsetattr(fileno(stdin), TCSANOW, &oflags) != 0) 
        handle_error("tcsetattr");

    return password;
}


