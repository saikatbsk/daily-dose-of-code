/*
 * Example 02: More Initialization Function Usage example
 */

#include <ncurses.h>
#include <stdlib.h>

int main() {
    int ch;

    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);

    printw("Type something. Press F1 to exit.\n");

    while((ch = getch()) != KEY_F(1)) {
        attron(A_BOLD);
        printw("%c", ch);
        attroff(A_BOLD);

        refresh();
    }

    printw("Press any key to exit..");
    refresh();
    getch();

    endwin();
    return 0;
}
