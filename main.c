#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(void)
{
    WINDOW *win = initscr();
    // Enable keypad for the window, so that we can get arrow keys
    keypad(win, TRUE);
    // Disable line buffering, so that the input is immediately available
    nodelay(win, TRUE);
    // Disable echo, so that the input is not displayed
    noecho();
    // Hide the cursor
    curs_set(0);
    // Seed the random number generator
    srand(time(NULL));
    int pos_x = 0, pos_y = 0;
    int food_x = rand() % 25, food_y = rand() % 25;
    int dir_x = 1, dir_y = 0;
    while (1)
    {
        int pressed = wgetch(win);
        if (pressed == KEY_UP)
        {
            dir_x = 0;
            dir_y = -1;
        }
        else if (pressed == KEY_DOWN)
        {
            dir_x = 0;
            dir_y = 1;
        }
        else if (pressed == KEY_LEFT)
        {
            dir_x = -1;
            dir_y = 0;
        }
        else if (pressed == KEY_RIGHT)
        {
            dir_x = 1;
            dir_y = 0;
        }
        pos_x += dir_x;
        pos_y += dir_y;
        erase();

        mvaddstr(pos_y, pos_x, "O");
        mvaddstr(food_y, food_x, "*");

        if (pos_x == food_x && pos_y == food_y)
        {
            food_x = rand() % 25;
            food_y = rand() % 25;
        }

        usleep(100000);
    }
    endwin();
}