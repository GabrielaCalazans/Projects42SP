#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 32
#endif

char	*get_next_line(int fd);

char	*get_next_line(int fd) 
{
    static char buffer[BUFFER_SIZE]; // Static buffer to store data read from the file descriptor
    static int index = 0; // Current position in the buffer
    static int size = 0; // Size of data in the buffer

    char *line = NULL; // String to store the accumulated characters of the current line
    int line_size = 0; // Current size of the line string
    int line_capacity = 0; // Capacity of the line string

    while (1) 
	{
        if (index >= size) 
		{
            index = 0;
            size = read(fd, buffer, BUFFER_SIZE); // Read data from the file descriptor into the buffer
            if (size < 0) 
			{
                free(line); // Free allocated memory in case of an error
                return NULL;
            } else if (size == 0) {
                break; // End of file reached, no more lines to read
            }
        }

        char current_char = buffer[index++]; // Get the current character from the buffer

        if (line_size >= line_capacity)
		{
            char *line = (char )malloc((line_capacity + BUFFER_SIZE) * sizeof(char)); // Reallocate more memory for the line string
            if (!line)
			{
                free(line); // Free allocated memory in case of an allocation failure
                return (NULL);
            }
            line_capacity += BUFFER_SIZE; // Increase the line capacity
        }

        line[line_size++] = current_char; // Append the current character to the line string

        if (current_char == '\n')
		{
            break; // End of line reached, break the loop
        }
    }

    if (line)
	{
        line[line_size] = '\0'; // Null-terminate the line string
    }

    return (line); // Return the line string or NULL if no more lines or an error occurred
}
