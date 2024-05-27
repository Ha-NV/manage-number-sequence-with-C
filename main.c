/**
 * @file main.c
 * @brief This program performs operations with number-sequence.
 * This program allows the user to create, manipulate, and perform operations on an number-sequence.
 * The user can create an array, print it, insert elements, delete elements, sort it
 * in ascending or descending order, and find a specific number within the array.
 * @author Viet Ha Nguyen
 * @bug No known bugs
 */

/*******************************************************************************
 * INCLUDE
 ******************************************************************************/
#include <stdio.h>

#include "manage_number.h"
#include "get_input.h"

/**
 * @brief Display options on console for user.
 * @return Void.
 */
void showMenu();

/*******************************************************************************
 * CODE
 ******************************************************************************/
/**
 * @brief Entrypoint of program "MANAGE NUMBER-SEQUENCE".
 *
 * First, we will display the menu to the user with the showMenu() function.
 * Next, we will get selection information from the user. This choice value will be saved
 * in the choice variable.
 * After obtaining the choice variable, we will carry out the requests using functions.
 * The program will only end when the user enters "e".
 *
 * @returns 0 if run successfully
 */
int main(void)
{
    char choice;                    /* Variable to get input from user */
    int position = 0;               /* Variable to get position of element which user want to insert to array */
    int value = 0;                  /* Variable to get value which user want to insert previous chosen position */
    char before_after_option;       /* Variable to get option from user in function of insertArray */
    int del_position = 0;           /* Variable to get position of element which user want to delete from array */
    int find_number = 0;            /* Variable to get element that user want to find in array */

    /* do-while loop to run the program continuously. The loop only terminates when the user enters 'e' */
    do
    {
        /* Initially the program will display the menu to the user */
        showMenu();

        /*
         * Get selection from user. The value the user enters must be a single-character value.
         * Base on getSingleCharInput() function. It will force the user to re-enter if they enter
         * a value more than one character
         * For example - Values such as 'ab', 'abc', '1c', ... are not valid
         */
        printf("\nEnter your selection: ");
        choice = getSingleCharInput();
        printf("\n");

        /*
         * Base on 'choice' variable, switch-case statement will go in each case.
         * These cases will correspond to actions in the menu.
         */
        switch (choice)
        {
            /* In this case, it will perform create an number-sequence base on createArray() function. */
            case 'c':
            {
                createArray();

                /* After done, wait for user press any key to clear console and go out switch-case statement*/
                clear_console();
                break;
            }

            /* In this case, it will perform print number-sequence base on printArray() function. */
            case 'p':
            {
                printArray();

                /* After done, wait for user press any key to clean console and go out switch-case statement*/
                clear_console();
                break;
            }

            /*
             * In this case, it will perform insert an element to array base on insertElement() function.
             * At here, program need to know element's positon and element's value that user want to insert to array.
             * User must input them. Base on getIntegerInput() function, it will force user enter only integer number
             * If user input floating-point number (1.5, 2.76,...), character ('a','b',... ) or
             * values are not meaning (0123, -0123, 123abc, 12ab45, 12-76y,...), they will enter again.
             */
            case 'i':
            {
                printf("Input position which you want to insert: ");
                position = getIntegerInput();

                printf("Input value of it: ");
                value = getIntegerInput();

                insertElement(position, value);

                /* After done, wait for user press any key to clean console and go out switch-case statement*/
                clear_console();
                break;
            }

            /*
             * In this case, it will perform delete an element from array base on deleteElement() function.
             * At here, program need to know positon that user want to delete.
             * User must input them. Base on getIntegerInput() function, it will force user enter only integer number
             * If user input floating-point number (1.5, 2.76,...), character ('a','b',... ) or
             * values are not meaning (0123, -0123, 123abc, 12ab45, 12-76y,...), they will enter again.
             */
            case 'd':
            {
                printf("Input position which you want to delete: ");
                del_position = getIntegerInput();

                deleteElement(del_position);

                /* After done, wait for user press any key to clean console and go out switch-case statement*/
                clear_console();
                break;
            }

            /* In this case, array will be sorted ascending base on sortAscending() function */
            case 's':
            {
                sortAscending();

                /* After done, wait for user press any key to clean console and go out switch-case statement*/
                clear_console();
                break;
            }

            /* In this case, array will be sorted descending base on sortDescending() function */
            case 'x':
            {
                sortDescending();

                /* After done, wait for user press any key to clean console and go out switch-case statement*/
                clear_console();
                break;
            }

            /*
             * In this case, it will perform find an element from array base on findNumber() function.
             * At here, program need to know number that user want to find.
             * User must input them. Base on getIntegerInput() function, it will force user enter only integer number
             * If user input floating-point number (1.5, 2.76,...), character ('a','b',... ) or
             * values are not meaning (0123, -0123, 123abc, 12ab45, 12-76y,...), they will enter again.
             */
            case 't':
            {
                printf("\nEnter number you want to find: ");
                find_number = getIntegerInput();

                findNumber(find_number);

                /* After done, wait for user press any key to clean console and go out switch-case statement*/
                clear_console();
                break;
            }

            /* In this case, program will be terminated */
            case 'e':
            {
                printf("Exit program");
                break;
            }

            /*
             * Assuming that user enters characters are different from 'c', 'p', 'i', 'd', 's', 'x', 't',
             * 'e', this case will be performed.
             */
            default:
            {
                printf("Invalid input, please enter again!!!");
                clear_console();
                break;
            }
        }
    } while (choice != 'e'); /*do-while loop will be terminated when user select 'e' option*/

    return 0;
}

/**
 * @brief Display options on console for user.
 * @return Void.
 */
void showMenu()
{
    printf("\n");
    // printf("-------------------------******---------------------------------\n");
    printf("*----------PROGRAM TO MANAGE NUMBER-SEQUENCE USING ARRAY----------*\n");
    printf("|                                                                 |\n");
    printf("|Input 'c' to create whole number-sequence                        |\n");
    printf("|Input 'p' to print number-sequence                               |\n");
    printf("|Input 'i' to add one element to number-sequence                  |\n");
    printf("|Input 'd' to delete one element from number-sequence             |\n");
    printf("|Input 's' to arrange number-sequence in ascending order          |\n");
    printf("|Input 'x' to arrange number-sequence in descending order         |\n");
    printf("|Input 't' to find a number in number-sequence                    |\n");
    printf("|Input 'e' to close program                                       |\n");
    printf("|_________________________________________________________________|\n");
} /* EOF */

