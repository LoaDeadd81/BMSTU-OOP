#ifndef ERRORTYPE_H
#define ERRORTYPE_H

#include <QString>

enum error_code {SUCCESS, DATA_ERROR, MODEL_INIT_ERROR, REQUEST_ERROR, FILE_OPENING_ERROR, BAD_MODEL_DATA, ACCESS_ERROR, MEM_ERROR};

QString error_interpretation(error_code rc);

#endif 
