#ifndef GABBY_LOGGER_H
#define GABBY_LOGGER_H

#include <stdio.h>
#include <stdbool.h>

#define GABBY_DEBUG 0
#define GABBY_INFO 1
#define GABBY_WARN 2
#define GABBY_ERROR 3
#define GABBY_FATAL 4

int gabby_setup(FILE* stream, bool closable);
void gabby_destroy(void);

int gabby_severity(int level);

int gabby_debug(const char* fmt, ...);
int gabby_info(const char* fmt, ...);
int gabby_warning(const char* fmt, ...);
int gabby_error(const char* fmt, ...);
int gabby_fatal(const char* fmt, ...);

#endif