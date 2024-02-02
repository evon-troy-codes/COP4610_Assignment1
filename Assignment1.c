//  Group Members: Samira Masri () & Evon Troy Alexander (1945955)
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
int factorial(int sum_factor);
int is_prime_num(int num);
void print_prime_numbers();
bool is_palindrome(int num);
int square_root(int num);
bool is_perfect_square(int num);

int main()
{
    // Variable declaration
    int num;

    // Here we'll prompt the user to enter a number
    printf("Enter the number of child processes to create: ");
    scanf("%d", &num);

    // If the number is > 0 AND < 5, we'll prompt the user to enter a valid number
    while (num < 1 || num > 5)
    {
        printf("Invalid entry. Child processes should be in the range of 1-5: ");
        scanf("%d", &num);
    }
    // User is notified of the number of child processes to be created
    printf("Parent process (PID: %d) is creating %d child processes.\n", getpid(), num);

    // // Here we declare the child_pid variable
    // pid_t child_pid;

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
                printf("Child %d (PID: %d) is computing the factorial of 5.\n", i, getpid());
                int result1 = factorial(5);
                printf("Child %d completed it's task. Result: %d\n", i, getpid(), result1);
                break;
            case 2:
                printf("Child %d (PID: %d) is finding prime numbers up to 20.\n", i, getpid());
                printf("Child %d (PID: %d) completed its task. Result: ", i, getpid());
                print_prime_numbers();
                printf("\n");
                break;
            case 3:
                printf("Child %d (PID: %d) is determining if 121 is a palindrome.\n", i, getpid());
                printf("Child %d completed its task. Result: %s\n", i, is_palindrome(121) ? "Palindrome" : "Not Palindrome");
                break;
            case 4:
                printf("Child %d (PID: %d) is calculating the square root of 30.\n", i, getpid());
                int result4 = square_root(30);
                printf("Child %d completed its task. Result: %d\n", i, getpid(), result4);
                break;
            case 5:
                printf("Child %d (PID: %d) is determining if 100 is a perfect square.\n", i, getpid());
                printf("Child %d completed its task. Result: %s\n", i, is_perfect_square(100) ? "Perfect Square" : "Not Perfect Square");
                break;
            default:
                printf("Invalid entry. Please enter a number between 1 and 5.\n");
                break;
            }
            // Child process exits
            exit(EXIT_SUCCESS);
        }
        else
        {
            // This code will be executed by the parent process
            printf("Parent: Child process created with PID %d\n", child_pid);
            // Wait for the child process to finish
            wait(NULL);
            printf("Parent: Child process finished\n");
        }
    }
    // Execute a new program using execl
    execl("/bin/ls", "ls", "-l", NULL);
    // If execl fails, this code will be reached
    perror("Execl failed");
    exit(EXIT_FAILURE);

    return 0;
}

// Function definitions

// Function to calculate the factorial of a number
int factorial(int sum_factor)
{
    int i, sum = 1;
    for (i = 1; i <= sum_factor; i++)
    {
        if (sum_factor % i == 0)
        {
            sum *= i;
        }
    }
    return sum;
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

// Created a fucntion to print prime numbers up to 20 to clean up the case statement
void print_prime_numbers()
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
bool is_perfect_square(int num)
{
    int i;
    for (i = 1; i <= num; i++)
    {
        if (i * i == num)
        {
            return true; // Perfect square
        }
    }
    return false; // Not a perfect square
}
