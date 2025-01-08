## Macros
### `GABBY_DEBUG` = 0
**Description:** Represents the debug severity level.

### `GABBY_INFO` = 1
**Description:** Represents the informational severity level.

### `GABBY_WARN` = 2
**Description:** Represents the warning severity level.

### `GABBY_ERROR` = 3
**Description:** Represents the error severity level.

### `GABBY_FATAL` = 4
**Description:** Represents the fatal severity level.

## Functions
### `int gabby_setup(FILE* stream, bool closable)`
**Description:** Initializes the logging system by specifying the output stream and whether the stream should be closed when the logger is destroyed.


**Parameters:**
  - ***stream:*** A pointer to a `FILE` object where log messages will be written (e.g., `stderr`, `stdout`, or a file).

- ***closable:*** A `bool` indicating whether the stream should be closed when `gabby_destroy` is called (`true` to close, `false` to leave open).

**Return Value:**
  - `0` on success.

  - Non-zero on failure (e.g., if the logger was already initialized or `stream` is `NULL`).


### `void gabby_destroy(void)`
**Description:** Cleans up the logging system, releasing any allocated resources. If the logging stream is marked as closable during setup, it will be closed.

**Parameters:** None.

**Return Value:** None.

### `int gabby_severity(int level)`
**Description:** Sets or gets the current logging severity level, determining the minimum level of messages that will be logged.

**Parameters:**
  - ***level:*** The minimum severity level to log (`GABBY_DEBUG`, `GABBY_INFO`, etc.).
  
**Return Value:** 
  - `0` on success.

  - Non-zero on failure.

**Notes:** By default, the severity level is `GABBY_INFO`.

### `int gabby_debug(const char* fmt, ...)`
**Description:** Logs a debug message with the specified format and arguments.

**Parameters:**
  - ***fmt:*** Format string following printf conventions.
  - ***...:*** Additional arguments corresponding to placeholders in `fmt`.

**Return Value:** Number of characters written.

### `int gabby_info(const char* fmt, ...)`
**Description:** Logs an informational message with the specified format and arguments.

**Parameters:** Same as `gabby_debug`.

**Return Value:** Same as `gabby_debug`.

### `int gabby_warning(const char* fmt, ...)`
**Description:** Logs a warning message with the specified format and arguments.

**Parameters:** Same as `gabby_debug`.

**Return Value:** Same as `gabby_debug`.

### `int gabby_error(const char* fmt, ...)`
**Description:** Logs an error message with the specified format and arguments.

**Parameters:** Same as `gabby_debug`.

**Return Value:** Same as `gabby_debug`.

### `int gabby_fatal(const char* fmt, ...)`
**Description:** Logs a fatal error message with the specified format and arguments.

**Parameters:** Same as `gabby_debug`.

**Return Value:** Same as `gabby_debug`.
