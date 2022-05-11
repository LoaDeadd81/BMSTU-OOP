#include "Error.h"

BaseError::BaseError(string file, string function, int line, const char *time, string message)
{
    error_message = "\n\nError";
    error_message += "\nFile: " + file;
    error_message += "\nFunction : " + function;
    error_message += "\nLine : " + to_string(line);
    error_message += "\nTime : " + string(time);
    error_message += "Info : " + message;
    error_message += "\n\n";
}

const char *BaseError::what() const noexcept
{
    return error_message.c_str();
}

MemoryError::MemoryError(string file, string function, int line, const char *time, string message)
        : BaseError(file, function, line, time, message)
{

}

DimensionError::DimensionError(string file, string function, int line, const char *time, string message)
        : BaseError(file, function, line, time, message)
{
}

IndexError::IndexError(string file, string function, int line, const char *time, string message)
        : BaseError(file, function, line, time, message)
{
}

IterIndexError::IterIndexError(string file, string function, int line, const char *time, string message)
        : BaseError(file, function, line, time, message)
{
}

ZeroDivError::ZeroDivError(string file, string function, int line, const char *time, string message)
        : BaseError(file, function, line, time, message)
{

}
