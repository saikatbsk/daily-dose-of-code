#include <ncurses.h>

int main() {
    /* start curses mode */
    initscr();

    /* print Hello World */
    printw("Hello World !!");

    /* print to the real screen */
    refresh();

    /* wait for user input and end curses mode */
    getch();
    endwin();

    return 0;
}
