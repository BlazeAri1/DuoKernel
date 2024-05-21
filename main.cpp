#include "shell.h"
int main() {
  shell shell;
  shell.register_user();
  shell.command_input();
  return 0;
}
