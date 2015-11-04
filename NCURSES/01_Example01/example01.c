/*
 * Example 01: Initialization Function Usage example
 */

#include <ncurses.h>

int main() {
    int ch;

    initscr();

    /* disable line buffering */
    raw();

    /* get function and arrow keys */
    keypad(stdscr, TRUE);

    /* do not echo while we do getch */
    noecho();

    printw("Type any character to see it in bold..\n");
    ch = getch();

    if(ch == KEY_F(1)) {
        printf("You pressed the F1 key.");
    }
    else {
        printw("You pressed ");
        attron(A_BOLD);
        printw("%c", ch);
        attroff(A_BOLD);
    }

    refresh();
    getch();
    endwin();

    return 0;
}
