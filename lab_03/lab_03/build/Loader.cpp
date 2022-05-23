#include "Loader.h"

void TXTLoader::open(string file_name)
{
    stream.open(file_name, ios::in);
}

int TXTLoader::get_num()
{
    int num;
    stream >> num;
    return num;
}

void TXTLoader::close()
{
    stream.close();
}
