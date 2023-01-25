
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
    }

    LOG_FATAL("This is a fatal message, the program will now exit");

    puts("This will never be printed");

    return 0;
}
