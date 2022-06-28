#ifndef _PRINT_C
#define _PRINT_C

#define log_(...)                                                              \
  print_timestamp();                                                           \
  printf(__VA_ARGS__);                                                         \
  printf("\n");

#include <stdbool.h>
#include <stdio.h>
#include <time.h>

void print_new_line() { printf("\n"); }

void print_timestamp() {
  int hours, minutes, seconds, day, month, year;
  time_t now;
  time(&now);
  struct tm *local = localtime(&now);
  hours = local->tm_hour;
  minutes = local->tm_min;
  seconds = local->tm_sec;
  printf("[%02d:%02d:%02d] ", hours, minutes, seconds);
};

void print_dashes(int dash_count) {
  for (int i = 0; i < dash_count; i++) {
    printf("-");
  }
  print_new_line();
};

#endif
