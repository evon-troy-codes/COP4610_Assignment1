// Group Members: Samira Masri () & Evon Troy Alexander (1945955)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{

    // Function to determine the sum of the factors of a number
    int factorial(int sum_factor)
    {
        int i, sum = 0;
        for (i = 1; i <= sum_factor; i++)
        {
            if (sum_factor % i == 0)
            {
                sum += i;
            }
        }
        return sum;
    }

    // Function to determine if a number is prime
    int is_prime_num(int num)
    {
        // In the initial loop we'll check to see if the number is 1 or 2
        if (num < 2)
        {
            return 0; // Not a prime number
        }
        for (int i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                return 0; // Not a prime number
            }
        }
        return 1; // Prime number
    }

    int main()
    {
        // Variable declarations
        int sum_factor, num;
    }

    pid_t child_pid;

    // // Fork a new process
    // child_pid = fork();

    // if (child_pid < 0)
    // {
    //     perror("Fork failed");
    //     exit(EXIT_FAILURE);
    // }
    // else if (child_pid == 0)
    // {
    //     // This code will be executed by the child process

    //     // Execute a new program using execl
    //     execl("/bin/ls", "ls", "-l", NULL);

    //     // If execl fails, this code will be reached
    //     perror("Execl failed");
    //     exit(EXIT_FAILURE);
    // }
    // else
    // {
    //     // This code will be executed by the parent process

    //     printf("Parent: Child process created with PID %d\n", child_pid);

    //     // Wait for the child process to finish
    //     wait(NULL);

    //     printf("Parent: Child process finished\n");
    // }

    // return 0;
}
