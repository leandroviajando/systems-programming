// Source: https://brennan.io/2015/01/16/write-a-shell-in-c/

#include "lsh.h"

/**
   @brief Main entry point.
   @param argc Argument count.
   @param argv Argument vector.
   @return status code
 */
int main(int argc, char **argv) {
  // Load config files, if any.

  // Run command loop.
  lsh_loop();

  // Perform any shutdown/cleanup.
  return EXIT_SUCCESS;
}
