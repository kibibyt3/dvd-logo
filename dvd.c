#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 3

typedef enum direction{
	TOPRIGHT = 1,
	BOTTOMRIGHT,
	BOTTOMLEFT,
	TOPLEFT
}direction;

int main(void){
	
	initscr();
	curs_set(0);
	srand(time(0));
	direction dir = (rand() % 4) + 1;

	int y = ((rand() % LINES) - (WIDTH - 1));
	int x = ((rand() % COLS)  - (WIDTH - 1));
	
	while(true){
		refresh();
		usleep(80000);
		switch (dir){
		case TOPRIGHT:
			x++;
			y--;
			break;
		case BOTTOMRIGHT:
			x++;
			y++;
			break;
		case BOTTOMLEFT:
			x--;
			y++;
			break;
		case TOPLEFT:
			x--;
			y--;
			break;
		}

		clear();
		mvaddstr(y, x, "DVD");	
		if (x == 0 && y == 0){
			x++;
			y++;
			dir = BOTTOMRIGHT;
		}
		else if (x == (COLS - (WIDTH + 1)) && y == LINES - 1){
			x--;
			y--;
			dir = TOPLEFT;
		}
		else if (x == 0 && y == LINES - 1){
			x++;
			y--;
			dir = TOPRIGHT;
		}
		else if (x == (COLS - (WIDTH + 1)) && y == 0){
			x--;
			y++;
			dir = BOTTOMLEFT;
		}
		else if (x == (COLS - (WIDTH + 1))){
			x--;
			dir = (dir == TOPRIGHT)
				? TOPLEFT
				: BOTTOMLEFT;
		}
		else if (y == LINES - 1){
			y--;
			dir = (dir == BOTTOMRIGHT)
				? TOPRIGHT
				: TOPLEFT;
		}
		else if (x == 0){
			x++;
			dir = (dir == TOPLEFT)
				? TOPRIGHT
				: BOTTOMRIGHT;
		}
		else if (y == 0){
			y++;
			dir = (dir == TOPRIGHT)
				? BOTTOMRIGHT
				: BOTTOMLEFT;
		}
	}
}

