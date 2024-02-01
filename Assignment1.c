//  Group Members: Samira Masri () & Evon Troy Alexander (1945955)
//  This program simulates a parallel task execution scenario using process forking.
//  The user will be prompted to enter a number between 1 and 5 (child processes to be created).
//  Each child process will perform a unique task and the parent process will wait for all child processes to finish before it finishes.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    // Variable declaration
    int num;

    // Here we'll prompt the user to enter a number
    printf("How many child processes would you like to create? Please enter a number up to 5: ");
    scanf("%d", &num);

    // If the number is > 0 AND < 5, we'll prompt the user to enter a valid number
    while (num < 1 || num > 5)
    {
        printf("Invalid entry. Child processes should be in the range of 1-5: ");
        scanf("%d", &num);
    }
    // User is notified of the number of child processes to be created
    printf("Parent process (PID: %d) will create %d child processes per the users request.", getpid(), num);

    // Here we declare the child_pid variable
    pid_t child_pid;

    // Fork a new process
    child_pid = fork();

    if (child_pid < 0)
    {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    else if (child_pid == 0)
    {
        // This code will be executed by the child process

        // Execute a new program using execl
        execl("/bin/ls", "ls", "-l", NULL);

        // If execl fails, this code will be reached
        perror("Execl failed");
        exit(EXIT_FAILURE);
    }
    else
    {
        // This code will be executed by the parent process

        printf("Parent: Child process created with PID %d\n", child_pid);

        // Wait for the child process to finish
        wait(NULL);

        printf("Parent: Child process finished\n");
    }

    return 0;

    // Function definitions

    // Function to calculate the factorial of a number
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

    // Function to determine if palindrome
    int is_palindrome(int num)
    {
        int reversed_num = 0, remainder, original_num;
        original_num = num;
        while (num != 0)
        {
            remainder = num % 10;
            reversed_num = reversed_num * 10 + remainder;
            num /= 10;
        }
        if (original_num == reversed_num)
        {
            return 1; // Palindrome
        }
        else
        {
            return 0; // Not a palindrome
        }
    }
    // Function to calculate the square root
    int square_root(int num)
    {
        int i;
        for (i = 1; i <= num; i++)
        {
            if (i * i == num)
            {
                return i;
            }
        }
        return 0;
    }
    // Function to determine if a number is a perfect square
    int is_perfect_square(int num)
    {
        int i;
        for (i = 1; i <= num; i++)
        {
            if (i * i == num)
            {
                return 1; // Perfect square
            }
        }
        return 0; // Not a perfect square
    }
}
