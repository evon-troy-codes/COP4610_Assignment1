//  Group Members: Samira Masri (6390566) & Evon Troy Alexander (1945955)
//  This program simulates a parallel task execution scenario using process forking.
//  The user will be prompted to enter a number between 1 and 5 (child processes to be created).
//  Each child process will perform a unique task and the parent process will wait for all child processes to finish before it finishes.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <math.h>

// Function prototypes
unsigned long long factorial(int sum_factor);
int is_prime_num(int num);
void print_prime_numbers();
bool is_palindrome(int num);
double square_root(int num);
bool is_perfect_square(int num);

int main()
{
    // Variable declaration - num will store the number of child processes to be created
    int num;

    // Here we'll prompt the user to enter a number
    printf("Enter the number of child processes to create: ");

    // Error handling for invalid input
    while (1)
    {
        // Attempt to read an integer from the user
        if (scanf("%d", &num) != 1)
        {
            // If a non integer is entered we clear the buffer
            while (getchar() != '\n')
                ;

            // Here we'll ask the user to enter a valid integer
            printf("Invalid input. Please enter a numeric value: ");
        }
        // In the else-if clause we'll check if the number is within the range of 1-4
        else if (num < 1 || num > 4)
        {
            // Prompt the user to enter a valid number within the range
            printf("Invalid entry. Child processes should be in the range of 1-4: ");
        }
        else
        {
            // Now that we finally have a valid input we'll exit the loop
            break;
        }
    }
    // User is notified of the number of child processes to be created
    printf("Parent process (PID: %d) is creating %d child processes.\n", getpid(), num);

    // Here we declare the child_pid variable
    pid_t child_pid;

    // We need to iterate through the number of child processes to be created
    for (int i = 1; i <= num; i++)
    {

        // Declare the child_pid variable and fork a new process
        pid_t child_pid = fork();

        if (child_pid < 0)
        {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }
        else if (child_pid == 0)
        {

            // Here we'll use the switch case statement to determine the task to be performed by the child process
            switch (i)
            {
            case 1:
                printf("Child %d (PID: %d) is computing the factorial of 50.\n", i, getpid());
                unsigned long long result1 = factorial(50);
                printf("Child %d completed it's task. Result: %llu\n", i, result1);
                break;
            case 2:
                printf("Child %d (PID: %d) is finding prime numbers up to 20.\n", i, getpid());
                printf("Child %d completed its task. Result: ", i);
                print_prime_numbers();
                printf("\n");
                break;
            case 3:
                printf("Child %d (PID: %d) is determining if 121 is a palindrome.\n", i, getpid());
                printf("Child %d completed its task. Result: %s\n", i, is_palindrome(121) ? "Palindrome" : "Not Palindrome");
                break;
            case 4:
                printf("Child %d (PID: %d) is calculating the square root of 30.\n", i, getpid());
                printf("Child %d completed its task. Result: %f\n", i, square_root(30));
                break;
            default:
                printf("Invalid entry. Please enter a number between 0 and 4.\n");
                break;
            }
            // Child process exits
            exit(EXIT_SUCCESS);
        }
    }
    // Wait for all child processes to finish
    for (int i = 1; i <= num; i++)
    {
        wait(NULL);
    }

    // Display the final parent message
    printf("\nAll child processes have completed. Parent (PID: %d) is displaying the final message.\n", getpid());

    return 0;
}

// Function definitions
// Variable declaration - num will store the number of child processes to be created

// Function to calculate the factorial of a number
unsigned long long factorial(int num)
{
    if (num < 0)
    {
        return -1;
    }

    unsigned long long result = 1;
    for (int i = 1; i <= num; i++)
    {
        result *= i;
    }
    return result;
}

// Function to print prime numbers up to 20
int is_prime_num(int num)
{
    if (num < 2)
    {
        return 0; // Not a prime number
    }

    int sqrt_num = sqrt(num);

    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            return 0; // Not a prime number
        }
    }
    return 1; // Prime number
}

// Created a function to print prime numbers up to 20 to clean up the case statement
void print_prime_numbers()
// Variable declaration - num will store the number of child processes to be created
{
    printf("Prime numbers up to 20: ");
    for (int j = 2; j <= 20; j++)
    {
        if (is_prime_num(j))
        {
            printf("%d ", j);
        }
    }
    printf("\n");
}

// Function to determine if palindrome
bool is_palindrome(int num)
{
    int reversed_num = 0, remainder, original_num;
    original_num = num;
    while (num != 0)
    {
        remainder = num % 10;
        reversed_num = reversed_num * 10 + remainder;
        num /= 10;
    }
    return (original_num == reversed_num);
}
// Function to calculate the square root
double square_root(int num)
{
    if (num < 0)
    {
        return -1;
    }
    return sqrt(num);
}
