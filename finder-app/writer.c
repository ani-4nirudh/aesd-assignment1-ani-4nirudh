/*
 1. Check the number of arguments
 2. Save the file path in a writefile
 3. Save word inside writestr
 4. Check for the file
 5. Syslog to wrtie string to the file
 */

#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc, char** argv) {
  // Initialise logging
  openlog("writer", LOG_PID | LOG_CONS, LOG_USER);

  // If arguments are less than 2 exit with failure
  if (argc < 2) {
    syslog(LOG_ERR, "Wrong number of arguments: %d \nEnter 2 arguments\n", argc);
    return EXIT_FAILURE;
  }
  
  char* writefile = argv[1];
  char* writestr = argv[2];

  // Create a file and append text
  FILE *fptr;
  fptr = fopen(writefile, "w");
  if (fptr == NULL) {
    syslog(LOG_ERR, "Error!");
    return EXIT_FAILURE;
  }
  syslog(LOG_DEBUG, "Writing %s to file %s", writestr, writefile);
  fprintf(fptr, "%s", writestr);
  fclose(fptr);

  closelog();
  return EXIT_SUCCESS;
}
