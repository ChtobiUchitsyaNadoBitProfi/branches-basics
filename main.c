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

void change_direction() {
  symbol = getch();
  switch (symbol) {
    case 'w': if (change_x != 1 || change_y != 0) {
                change_x = -1; change_y = 0;
              }
              break;
    case 'a': if (change_x != 0 || change_y != 1) {
                change_x = 0; change_y = -1;
              }
              break;
    case 's': if (change_x != -1 || change_y != 0) {
                change_x = 1; change_y = 0;
              }
              break;
    case 'd': if (change_x != 0 || change_y != -1) {
                change_x = 0; change_y = 1;
              }
              break;
#ifndef WINDOWS
    case 'q': nonblock(NB_DISABLE); std::exit(0);
#endif
    default: break;
  }
}

void show_table() {
#ifdef WINDOWS
  system("cls");
#else
  system("clear");
#endif
  for (int i = 0; i <= N + 1; ++i)
    for (int j = 0; j <= M + 1; ++j)
      std::cout
        << (i == 0 || j == 0 || i == N + 1 || j == M + 1 ?
           '#' : a[i][j])
        << (j <= M ? "" : "\n");
}

int main() {
  /* code */
  return 0;
}
 
