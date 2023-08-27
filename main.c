#include "monty.h"
bus_t new_bus = {NULL, NULL, NULL, 0};

int main(int argc, char *argv[])
{
    char *data;
    FILE *data_file;
    size_t data_size = 0;
    ssize_t read_status = 1;
    stack_t *data_stack = NULL;
    unsigned int line_counter = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    data_file = fopen(argv[1], "r");
    new_bus.file = data_file;
    if (!data_file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while (read_status > 0)
    {
        data = NULL;
        read_status = getline(&data, &data_size, data_file);
        new_bus.content = data;
        line_counter++;
        if (read_status > 0)
        {
            execute(data, &data_stack, line_counter, data_file);
        }
        free(data);
    }
    free_stack(data_stack);
    fclose(data_file);
    return (0);
}

