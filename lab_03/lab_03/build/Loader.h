#ifndef LOADER_H
#define LOADER_H

#include <fstream>
#include <string>

using namespace std;

class BaseLoader
{
public:
    virtual ~BaseLoader() = 0;
    virtual void open(string file_name) = 0;
    virtual int get_num() = 0;
    virtual void close() = 0;
protected:
    ifstream stream;
};

class TXTLoader : public BaseLoader
{
public:
    virtual ~TXTLoader() = default;
    virtual void open(string file_name) override;
    virtual int get_num() override;
    virtual void close() override;

};

#endif
