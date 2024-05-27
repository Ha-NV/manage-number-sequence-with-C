/**
 * @file get_input.c
 * @brief This file contain definition of functions that are declaring in header file get_input.h
 * @author Viet Ha Nguyen
 * @bug No known bugs
 */

/*******************************************************************************
 * INCLUDE
 ******************************************************************************/
#include "get_input.h"

/*******************************************************************************
 * PROTOTYPE
 ******************************************************************************/
static bool isInteger(const char *input);

/*******************************************************************************
 * FUNCTIONS
 ******************************************************************************/

/**
 * @brief This function is designed to get an integer input from the user.
 *        It repeatedly asks the user for input until a whole number is entered.
 *
 * This mean that if user enter an floating-point number, characters or
 * strings are not meaning (such as: 123abc, a23, -0245, 0325, 00123, ...)
 * This function will ask user enter again untill a valid whole number is entered
 *
 * @return whole number
 */
int getIntegerInput()
{
    char input[1000000];        /* This is an array to store the user input. */
    int num;                    /* This variable will hold the converted integer value. */

    /* This loop runs indefinitely until a whole number input is provided. */
    while (1)
    {
        /* Clear the buffer */
        fflush(stdin);
        /* It uses fgets() to read input as a string. This reads a line of input from the user, storing it in the input array. */
        fgets(input, sizeof(input), stdin);

        /* This removes the newline character (\n) from the input by replaces
        the \n with '\0' character */
        input[strcspn(input, "\n")] = '\0';

        /* Calls the isInteger(input) function to check if the input is a valid integer.
         * If isInteger(input) returns true, it means the input is a valid integer.
         * Converts the string input to an integer using atoi() function
         * Returns the num variable that is a whole number.
         * */
        if (isInteger(input))
        {
            num = atoi(input);
            return num;
        }
        /* If isInteger(input) returns false, it means the input is not a valid integer.
         Prints a message asking the user to enter a whole number again. */
        else
        {
            printf("\nYour input is not valid. Please enter a whole number: ");
        }
    }
}

/**
 * @brief This function is designed to get a single character input from the user.
 *        It ensures that the user only enters one character and then returns that character.
 * @return single character
 */
char getSingleCharInput()
{
    char user_input[2]; /* This array is used to store the input character and a null terminator \0.
    It has a size of 2 to store one the character and the null terminator.*/

    /* The function enters a while loop that continues indefinitely until a valid single character
     input is received. */
    while (1)
    {
        /* Clear the buffer */
        fflush(stdin);
        /* Read input from user */
        scanf("%s", user_input);

        /*
         * Checking if user_input[1] is '\0' character or not
         * If more than one character was entered, it prints a message asking the user to enter only a single character and require for input again.
        */
        if (user_input[1] != '\0')
        {
            printf("\nPlease enter only a single character. Try again: ");
        }
        /* If a single character is entered, the function returns the first character of user_input,
         which is user_input[0].*/
        else
        {
            return user_input[0];
        }
    }
}

/**
 * @brief This function is a helper function used by getIntegerInput()
 *        to check whether the provided input is a valid integer.
 *
 * If any character fails these conditions, the function returns false, indicating that the input is
 * not a valid integer.
 * If all characters pass the conditions, the function returns true, indicating that the input is a
 * valid integer.
 *
 * @return True or False
 */
static bool isInteger(const char *input)
{
	int i = 0;              /* Variable of index in for-loop */

    /* By using for-loop, It checks each character of the input string enterd one by one. */
    for (i = 0; i < strlen(input); i++)
    {
        /* Ensures that the input does not start with a zero */
        if (input[0] == '0')
        {
            return false;
        }

        /* Ensures that if the first digit is 0, the second character should not be 0. */
        if (!isdigit(input[0]) && input[1] == '0')
        {
            return false;
        }

        /* Ensure that if the first character is a minus sign - for negative numbers.*/
        if (!isdigit(input[i]) && !(i == 0 && input[i] == '-'))
        {
            return false;
        }
    }
    return true;
} /* EOF */

