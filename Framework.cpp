#include "Framework.h"

char* FileAsString(const char* path)
{
    FILE* file = fopen(path, "r");
    if (file == nullptr) exit(EXIT_FAILURE);

    char line_str[100] = "";
    char* file_str = new char[999];
    memset(file_str, 0, sizeof(*file_str));

    while (fgets(line_str, 100, file) != NULL)
        strcat(file_str, line_str);
    fclose(file);

    return file_str;
}
