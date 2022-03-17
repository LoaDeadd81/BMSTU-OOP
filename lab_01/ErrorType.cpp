#include "ErrorType.h"

QString error_interpretation(error_code rc)
{
    QString err_message;
    switch (rc)
    {
        case SUCCESS:
            err_message = "Нет ошибок";
            break;
        case REQUEST_ERROR:
            err_message = "Неизвестный запрос действия";
            break;
//        case INPUT_MODEL_ERROR:
//            err_message = "Ошибка при вводе модели";
//            break;
//        case MEMORY_ERROR:
//            err_message = "Ошибка памяти";
//            break;
//        case DATA_ACCESS_ERROR:
//            err_message = "Ошибка доступа в память";
//            break;
//        case DATA_ERROR:
//            err_message = "Исправьте поля выделенные красным";
//            break;
//        case EXISTING_ERROR:
//            err_message = "Необходимо загрузить модель";
//            break;
//        default:
//            err_message = "Неизвестная ошибка";
//            break;
    }
    return err_message;
}
