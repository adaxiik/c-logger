#pragma once
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
    #include <string>
#endif

#define LOGGER_LEVEL_DEBUG 0
#define LOGGER_LEVEL_INFO 1
#define LOGGER_LEVEL_WARNING 2
#define LOGGER_LEVEL_ERROR 3
#define LOGGER_LEVEL_FATAL 4

#define LOGGER_COLORS_OFF 0
#define LOGGER_COLORS_ON 1

#define LOGGER_COLOR_RESET "\033[0m"
#define LOGGER_COLOR_RED "\033[31m"
#define LOGGER_COLOR_GREEN "\033[32m"
#define LOGGER_COLOR_YELLOW "\033[33m"
#define LOGGER_COLOR_BLUE "\033[34m"

static const char* g_levelStrings[] = {
    "[DEBUG]",
    "[INFO]",
    "[WARNING]",
    "[ERROR]",
    "[FATAL]"
};

static const char* g_levelColors[] = {
    LOGGER_COLOR_BLUE,
    LOGGER_COLOR_GREEN,
    LOGGER_COLOR_YELLOW,
    LOGGER_COLOR_RED,
    LOGGER_COLOR_RED
};

#define LOGGER_OUTPUT_STDOUT stdout
#define LOGGER_OUTPUT_STDERR stderr

#ifndef LOGGER_SETTINGS_LEVEL
    #define LOGGER_SETTINGS_LEVEL LOGGER_LEVEL_DEBUG
#endif

#ifndef LOGGER_SETTINGS_COLORS
    #define LOGGER_SETTINGS_COLORS LOGGER_COLORS_ON
#endif


#define LOGGER_LOG(file,level,fmt,...) do { \
    if (level >= LOGGER_SETTINGS_LEVEL) { \
        fprintf(file, "%s%s%s: ", LOGGER_SETTINGS_COLORS ? g_levelColors[level] : "", g_levelStrings[level], LOGGER_SETTINGS_COLORS ? LOGGER_COLOR_RESET : ""); \
        fprintf(file, fmt, ##__VA_ARGS__); \
        fprintf(file, "\n"); \
    } \
    } while (0)


#define LOG_DEBUG(fmt,...) LOGGER_LOG(LOGGER_OUTPUT_STDOUT, LOGGER_LEVEL_DEBUG, fmt, ##__VA_ARGS__)
#define LOG_INFO(fmt,...) LOGGER_LOG(LOGGER_OUTPUT_STDOUT, LOGGER_LEVEL_INFO, fmt, ##__VA_ARGS__)
#define LOG_WARN(fmt,...) LOGGER_LOG(LOGGER_OUTPUT_STDOUT, LOGGER_LEVEL_WARNING, fmt, ##__VA_ARGS__)
#define LOG_ERROR(fmt,...) LOGGER_LOG(LOGGER_OUTPUT_STDERR, LOGGER_LEVEL_ERROR, fmt, ##__VA_ARGS__)
#define LOG_FATAL(fmt,...) LOGGER_LOG(LOGGER_OUTPUT_STDERR, LOGGER_LEVEL_FATAL, fmt, ##__VA_ARGS__); exit(1)

#define LOG_WATCH_INT(variable) LOG_DEBUG(#variable " = %d (%s:%d)", variable, __FILE__, __LINE__)
#define LOG_WATCH_UINT(variable) LOG_DEBUG(#variable " = %u (%s:%d)", variable, __FILE__, __LINE__)
#define LOG_WATCH_LONG(variable) LOG_DEBUG(#variable " = %ld (%s:%d)", variable, __FILE__, __LINE__)
#define LOG_WATCH_ULONG(variable) LOG_DEBUG(#variable " = %lu (%s:%d)", variable, __FILE__, __LINE__)
#define LOG_WATCH_FLOAT(variable) LOG_DEBUG(#variable " = %f (%s:%d)", variable, __FILE__, __LINE__)
#define LOG_WATCH_DOUBLE(variable) LOG_DEBUG(#variable " = %lf (%s:%d)", variable, __FILE__, __LINE__)
#define LOG_WATCH_STRING(variable) LOG_DEBUG(#variable " = %s (%s:%d)", variable, __FILE__, __LINE__)
#define LOG_WATCH_BOOL(variable) LOG_DEBUG(#variable " = %s (%s:%d)", variable ? "true" : "false", __FILE__, __LINE__)
#define LOG_WATCH_HEX(variable) LOG_DEBUG(#variable " = 0x%x (%s:%d)", variable, __FILE__, __LINE__)
#define LOG_WATCH_PTR(variable) LOG_DEBUG(#variable " = %p (%s:%d)", variable, __FILE__, __LINE__)

#ifdef __cplusplus
    #define LOG_WATCH(variable) do { \
        LOG_DEBUG(#variable " = %s (%s:%d)", std::to_string(variable).c_str(), __FILE__, __LINE__); \
        } while (0)
#endif