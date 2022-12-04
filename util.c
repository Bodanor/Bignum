#include "util.h"

char *secureInput(void)
{
    int c;
    int step_size = 1;
    int i;
    char *tmp = NULL;
    char *input = NULL;

    i = 0;
    while ((c = getchar()) != '\n'){

        if (i % BUFFER_SIZE == 0){
            input = (char*)realloc(input, (sizeof(char)*(BUFFER_SIZE * step_size)));
            if (input == NULL)
                return NULL;
            
            tmp = input + (BUFFER_SIZE *(step_size - 1));
            i = 0;
            step_size++;

        }
        tmp[i++] = c;

    }
    tmp[i] = '\0';
    return input;
}