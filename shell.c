#include "shell.h"

int main(void)
{
    while (1) {
        char *command = read_user_command();

        if (command == NULL) {
            break;
        }

        if (str_len(command) > 0) {
            run_command(command);
        }

        free(command);
    }

    return 0;
}

