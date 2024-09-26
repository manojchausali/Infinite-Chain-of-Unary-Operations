#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <math.h>

char* remove_dot_slash(char* str) {
    if (strncmp(str, "./", 2) == 0) {
        return str + 2;
    }
    return str;
}

void execute_function(int argc, char* argv[]) {

    char* operation = remove_dot_slash(argv[0]);;
    int number = atoi(argv[argc - 2]);
    int offset = atoi(argv[argc - 1]);

    // Calculate the function (square of the number)
    unsigned long long result;

    if (strcmp(operation, "square") == 0) {
        result = number * number;
    }
    else if (strcmp(operation, "root") == 0) {
        result = (int)round(sqrt(number)); // Casting to int to match the function's return type
    }
    else if (strcmp(operation, "double") == 0) {
        result = 2 * number;
    }
    else {
        printf("Unknown operation: %s\n", operation);
        return;
    }



    if (argc <= 3) {
        // No next process, print the result to the console
        printf("%d\n", result);
    }
    else {
        // Prepare arguments for the next process

        char* next_op[argc];
        next_op[0] = argv[1]; // First element is the name of the file to be called
        for (int i = 2; i < argc - 2; i++) {
            next_op[i - 1] = argv[i];
        }
        char result_str[20];
        sprintf(result_str, "%d", result);

        char zero[4];
        sprintf(zero, "%d", 0);

        next_op[argc - 1] = NULL;
        next_op[argc - 2] = zero;
        next_op[argc - 3] = result_str;


        char buffer[255];
        sprintf(buffer, "./%s", next_op[0]);

        // Create a new process
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0) {
            // Child process
            execvp(buffer, next_op);
            // If execvp returns, an error occurred
            perror("execvp failed");
            exit(EXIT_FAILURE);
        }
        else {
            // Parent process
            wait(NULL); // Wait for the child process to complete
        }
    }
}

int main(int argc, char* argv[]) {

    if (argc - 2 < 1 || argc - 2 > 100) {
        printf("UNABLE TO EXECUTE");
        exit(EXIT_FAILURE);
    }

    

    int num = atoi(argv[argc - 2]);
    int offset = atoi(argv[argc - 1]);

    if (offset >= argc - 2) {
        printf("UNABLE TO EXECUTE");
        return -1;
    }

    if (offset != 0) {
        char** rearranged = (char**)malloc((argc) * sizeof(char*));
        if (rearranged == NULL) {
            printf("Memory allocation failed.\n");
            return -1;
        }
        // Rearrange elements
        for (int i = 0; i < argc - 2; i++) {
            int Index = (i + offset) % (argc - 2);
            rearranged[i] = argv[Index];
        }
        char result_str[20];
        sprintf(result_str, "%d", num);

        char zero[4];
        sprintf(zero, "%d", 0);

        rearranged[argc - 1] = zero;
        rearranged[argc - 2] = result_str;

        execute_function(argc, rearranged);
        return 0;
        
    }

    execute_function(argc, argv);
    return 0;
}
