#include "gabby.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <time.h>

typedef struct {
    FILE* stream;
    bool closable;
} output_t;

static output_t output = {0};
static int severity = GABBY_WARN;

int gabby_setup(FILE* stream, bool closable) {
    if (output.stream) {
        return 1;
    }

    if (!stream) {
        return 1;
    }

#ifdef NDEBUG
    severity = GABBY_WARN;
#else
    severity = GABBY_DEBUG;
#endif

    output.stream = stream;
    output.closable = closable;
}

void gabby_destroy(void) {
    fflush(output.stream);

    if (output.closable) {
        fclose(output.stream);
    }

    output.stream = NULL;
    output.closable = false;
}

int gabby_severity(int level) {
    if (level < GABBY_DEBUG) {
        return 1;
    }

    if (level > GABBY_FATAL) {
        return 1;
    }

    severity = level;
    return 0;
}

static void gabby_prompt(const char* level) {
    char buffer[124];
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    strftime(buffer, 124, "%H:%M:%S %d/%m/%Y", t);

    fprintf(output.stream, "LEVEL=[%s] TIME=[%s]\n", level, buffer);
}

static int gabby_println(const char* fmt, va_list args) {
    int result = vfprintf(output.stream, fmt, args);
    fprintf(output.stream, "\n");
    return result;
}

static void gabby_separator(void) {
    fprintf(output.stream, "\n");
    fflush(output.stream);
}

int gabby_debug(const char* fmt, ...) {
    if (!output.stream) {
        return 0;
    }

    if (severity > GABBY_DEBUG) {
        return 0;
    }

    gabby_prompt("DEBUG");

    va_list args;
    va_start(args, fmt);
    int result = gabby_println(fmt, args);
    va_end(args);

    gabby_separator();

    return result;
}

int gabby_info(const char* fmt, ...) {
    if (!output.stream) {
        return 0;
    }

    if (severity > GABBY_INFO) {
        return 0;
    }
    
    gabby_prompt("INFO");

    va_list args;
    va_start(args, fmt);
    int result = gabby_println(fmt, args);
    va_end(args);

    gabby_separator();

    return result;
}

int gabby_warn(const char* fmt, ...) {
    if (!output.stream) {
        return 0;
    }

    if (severity > GABBY_WARN) {
        return 0;
    }
        
    gabby_prompt("WARN");

    va_list args;
    va_start(args, fmt);
    int result = gabby_println(fmt, args);
    va_end(args);

    gabby_separator();

    return result;
}

int gabby_error(const char* fmt, ...) {
    if (!output.stream) {
        return 0;
    }

    if (severity > GABBY_ERROR) {
        return 0;
    }
        
    gabby_prompt("ERROR");

    va_list args;
    va_start(args, fmt);
    int result = gabby_println(fmt, args);
    va_end(args);

    gabby_separator();

    return result;
}

int gabby_fatal(const char* fmt, ...) {
    if (!output.stream) {
        return 0;
    }

    if (severity > GABBY_FATAL) {
        return 0;
    }
        
    gabby_prompt("FATAL");

    va_list args;
    va_start(args, fmt);
    int result = gabby_println(fmt, args);
    va_end(args);

    gabby_separator();

    return result;
}
