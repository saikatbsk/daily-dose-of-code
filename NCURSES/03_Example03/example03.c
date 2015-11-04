/*
 * Example 03 : Erase window example.
 */
#include <ncurses.h>

int main() {
    int ch;

    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);

    /*
     * erase() and werase(win): werase(...) and erase() will
     * copy blanks to every position on the window
     */
    printw("Hello World! Press F1 to erase the window [ erase() ]");
    refresh();
    while((ch = getch()) != KEY_F(1)) {}
    erase();

    /*
     * clear() and wclear(win): the same as erase();
     * when we set clearok() the screen will be cleared with
     * the next refresh
     */
    printw("Hello World! Press F1 to erase the window [ clear() ]");
    refresh();
    while((ch = getch()) != KEY_F(1)) {}
    clear();
    //refresh();

    /*
     * clrtobot() and wclrtobot(win): clearing the current cursor line
     * (start is one character right from the cursor)
     * and the line below the cursor
     */
    mvprintw(20, 20, "Hello!!"); //-- this line gets cleared
    mvprintw(10, 10, "Press F1 to erase the line bellow [ clrtobot() ]");
    refresh();
    while((ch = getch()) != KEY_F(1)) {}
    clrtobot();

    /*
     * clrtoeol() and wclrtoeol(win): clear the current line right
     * from the cursor up to its end
     */
    mvprintw(0, 40, "Hello!! Hello!! Hello!! Hello!! Hello!!");
    mvprintw(0, 0, "Press F1 to erase to eol[ clrtoeol() ]");
    refresh();
    while((ch = getch()) != KEY_F(1)) {}
    clrtoeol();

    printw("Press any key to exit..");
    refresh();
    getch();
    endwin();

    return 0;
}
