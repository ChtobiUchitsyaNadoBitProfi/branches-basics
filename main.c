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

  // Get the terminal state.
  tcgetattr(STDIN_FILENO, &ttystate);

  if (state == NB_ENABLE) {
    // Turn off canonical mode.
    ttystate.c_lflag &= ~ICANON;
    // Minimum of number input read.
    ttystate.c_cc[VMIN] = 1;
  } else if (state == NB_DISABLE) {
    // Turn on canonical mode.
    ttystate.c_lflag |= ICANON;
  }
  // Set the terminal attributes.
  tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
}

int getch() {
  return fgetc(stdin);
}

#endif

int main() {
  /* code */
  return 0;
}
 
