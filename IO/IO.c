#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *source, *destination;
    char ch;

    // Open source file for reading
    source = fopen(argv[1], "r");
    if (source == NULL)
    {
        printf("Error: Could not open input.txt for reading\n");
        return 1;
    }

    // Open destination file for writing
    destination = fopen(argv[2], "w");
    if (destination == NULL)
    {
        printf("Error: Could not open output.txt for writing\n");
        fclose(source);
        return 1;
    }

    // Read character by character and write to destination
    while ((ch = fgetc(source)) != EOF)
    {
        fputc(ch, destination);
    }

    printf("File copied successfully!\n");

    // Close both files
    fclose(source);
    fclose(destination);

    return 0;
}
