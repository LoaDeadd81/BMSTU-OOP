#ifndef ERORRS_H
#define ERORRS_H

#include <QString>

enum error_code {SUCCESS, REQUEST_ERROR, INPUT_MODEL_ERROR, MEMORY_ERROR, DATA_ACCESS_ERROR, DATA_ERROR, EXISTING_ERROR};

QString error_interpretation(error_code rc);

#endif 
