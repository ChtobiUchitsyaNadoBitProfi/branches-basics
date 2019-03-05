#include <stdio.h>

int kbhit() {
  struct timeval tv;
  fd_set fds;
  tv.tv_sec = 0;
  tv.tv_usec = 0;
  FD_ZERO(&fds);
  FD_SET(STDIN_FILENO, &fds);
  select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
  return FD_ISSET(STDIN_FILENO, &fds);
}

void nonblock(int state) {
  struct termios ttystate;

  tcgetattr(STDIN_FILENO, &ttystate);

  if (state == NB_ENABLE) {
    ttystate.c_lflag &= ~ICANON;
    ttystate.c_cc[VMIN] = 1;
  } else if (state == NB_DISABLE) {
    ttystate.c_lflag |= ICANON;
  }
  tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
}

int getch() {
  return fgetc(stdin);
}

#endif

int snake_size, change_x, change_y, coordinates_x[1000], coordinates_y[1000];
int food_x = -1, food_y = -1;
char symbol, a[1000][1000];
const int N = 13, M = 17, INTERVAL = 200;


int main() {
  /* code */
  return 0;
}
 
