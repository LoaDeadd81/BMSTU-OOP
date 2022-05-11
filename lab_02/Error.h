#ifndef ERROR_H
#define ERROR_H

#include <execution>
#include <string>
#include <ctime>

using namespace std;

//todo нормальные сообщения об ошибках
class BaseError : public exception
{
public:
    BaseError()=default;
    BaseError(string file, string function, int line, const char *time, string message);
    virtual const char *what() const noexcept override;

protected:
    string error_message;
};

class MemoryError : public BaseError
{
public:
    MemoryError()=default;
    explicit MemoryError(string file, string function, int line, const char *time, string message);
};

class DimensionError : public BaseError
{
public:
    DimensionError()=default;
    explicit DimensionError(string file, string function, int line, const char *time, string message);
};

class IndexError : public BaseError
{
public:
    IndexError()=default;
    explicit IndexError(string file, string function, int line, const char *time, string message);
};

class IterIndexError : public BaseError
{
public:
    IterIndexError()=default;
    explicit IterIndexError(string file, string function, int line, const char *time, string message);
};

class ZeroDivError : public BaseError
{
public:
    ZeroDivError()=default;
    explicit ZeroDivError(string file, string function, int line, const char *time, string message);
};


#endif
