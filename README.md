# c-logger
Simple C/Cpp macros for logging and debuging in code

## Usage
Include the header file in your code, and then use the macros to log messages.

```c
LOGGER_LOG(file,level,fmt,...) 

LOG_DEBUG(fmt,...)
LOG_INFO(fmt,...)
LOG_WARN(fmt,...)
LOG_ERROR(fmt,...)
LOG_FATAL(fmt,...) // exits the program, with exit code 1

LOG_WATCH(var) // Only for c++
LOG_WATCH_INT(var)
LOG_WATCH_FLOAT(var)
LOG_WATCH_STRING(var)
// ...
```


## Settings

#### LOGGER_SETTINGS_LEVEL
- LOGGER_LEVEL_DEBUG (default)
- LOGGER_LEVEL_INFO
- LOGGER_LEVEL_WARNING
- LOGGER_LEVEL_ERROR
- LOGGER_LEVEL_FATAL

#### LOGGER_SETTINGS_COLORS
- LOGGER_COLORS_ON (default)
- LOGGER_COLORS_OFF


## Example
```c
#define LOGGER_SETTINGS_LEVEL LOGGER_LEVEL_DEBUG    // optional
#define LOGGER_SETTINGS_COLORS LOGGER_COLORS_ON     // optional
#include "logger.h"

int main(int argc, char const *argv[])
{
    LOG_DEBUG("This is a debug message");
    LOG_INFO("Five plus five is %d", 5 + 5);
    LOG_WARN("Formating is %s", "easy");
    LOG_ERROR("This is an error message");

    for (size_t i = 0; i < 3; i++)
    {
        LOG_WATCH_INT(i);
        // LOG_WATCH(i); // Only for c++
    }

    LOG_FATAL("This is a fatal message, the program will now exit");

    puts("This will never be printed");

    return 0;
}
```

#### Output:
```txt
[DEBUG]: This is a debug message
[INFO]: Five plus five is 10
[WARNING]: Formating is easy
[ERROR]: This is an error message
[DEBUG]: i = 0
[DEBUG]: i = 1
[DEBUG]: i = 2
[FATAL]: This is a fatal message, the program will now exit
```

build and run with:
```bash
gcc example.c -o example && ./example
```