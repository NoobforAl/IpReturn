#ifndef LOGGER
#define LOGGER

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// message formate
// log level | time | message
#define INFO_MSG "INFO | %s | %s"
#define WARN_MSG "WARN | %s | %s"
#define DEBUG_MSG "DEBUG | %s | %s"
#define ERROR_MSG "ERROR | %s | %s"

// init logger if program
// run debug, set debug on
void initLogger(const bool de);

// show info messages
void info(const char *messages);

// show warn messages
void warn(const char *messages);

// show debug messages
void debug(const char *messages);

// show error messages
void error(const char *messages);

#endif