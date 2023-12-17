#include "lexer.h"
#include "parser.h"
#include "executor.h"
#include <stdio.h>
#include <stdlib.h>

// Function to read the source code from a file
char* readSourceCode(const char* filepath) {
    FILE* file = fopen(filepath, "r");
    if (!file) {
        perror("File opening failed");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = malloc(length + 1);
    if (!buffer) {
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, length, file);
    buffer[length] = '\0';

    fclose(file);
    return buffer;
}

int main(int argc, char *argv[]) {
    // Handle command line arguments for the source file
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <source file>\n", argv[0]);
        return 1;
    }

    char* sourceCode = readSourceCode(argv[1]);
    if (sourceCode == NULL) {
        fprintf(stderr, "Failed to read the source file.\n");
        return 1;
    }

    // The rest of your main function logic...
    // Don't forget to free the sourceCode when done
    free(sourceCode);

    return 0;
}
