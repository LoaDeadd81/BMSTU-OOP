#include "ErrorType.h"

QString error_interpretation(error_code rc)
{
    QString err_message;
    switch (rc)
    {
        case SUCCESS:
            err_message = "Нет ошибок";
            break;
        case DATA_ERROR:
            err_message = "Исправьте поля выделенные красным";
            break;
        case MODEL_INIT_ERROR:
            err_message = "Модель не инициализирована";
            break;
        case REQUEST_ERROR:
            err_message = "Неизвестный запрос действия";
            break;
        case FILE_OPENING_ERROR:
            err_message = "Невозможно открыть файл";
            break;
        case BAD_MODEL_DATA:
            err_message = "Ошибка в текстовом представлении модели";
            break;
        case ACCESS_ERROR:
            err_message = "Ошибка доступа к ресурсам";
            break;
        case MEM_ERROR:
            err_message = "Ошибка пр работе с памятью";
            break;
        default:
            err_message = "Неизвестная ошибка";
            break;
    }
    return err_message;
}
