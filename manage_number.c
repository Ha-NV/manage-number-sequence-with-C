/**
 * @file manage_number.c
 * @brief This file contain definition of functions that are declaring in header file manage_number.h
 * @author Viet Ha Nguyen
 * @bug No known bugs
 */
/*******************************************************************************
 * INCLUDE
 ******************************************************************************/
#include "manage_number.h"
#include "get_input.h"

/*******************************************************************************
 * DEFINE MACRO
 ******************************************************************************/
#define MAX_SIZE 1000             /* Define the maximum possible number of array's elements*/

/*******************************************************************************
 * DECLARE GLOBAL VARIABLE
 ******************************************************************************/
int number_sequence[MAX_SIZE];    /* Declares an empty array with the maximum possible number of elements*/
int size_of_array = 0;            /* Global variable that are size of number-sequence, once array is created, array's size will be stored as an integer on this variable.*/

/*******************************************************************************
 * FUNCTIONS
 ******************************************************************************/
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
}


/**
 * @brief Create an new array.
 *
 * This function will create a new array whenever it is called. It base on 'size_of_array' variable to
 * check if array create or not.
 * In case the array empty (size_of_array = 0). It will ask the user to enter the number of elements
 * in the array (size_of_array variable), then will ask the user to enter the value for each element
 * in the array.
 * In case the array has been created before (size_of_array != 0),this function will create
 * a new array based on assigning size_of_array = 0, then take the steps as in the
 * case 'size_of_array = 0' above.
 *
 * @return Void.
 */
void createArray()
{
    int i = 0;                     /* Variable of index in for-loop */
    int length = 0;                /* Variable of declaring the number of array's element */

    /*
     * Check whether the array has been created or not. If it has been created
     * (i.e its size is different from 0), function will delete the old array
     * by assigning size_of_array = 0
     */
    if (size_of_array != 0)
    {
        printf("Deleted your previous number-sequence!!!\n\n");
        printf("Following, you can create a new number-sequence.\n");
        size_of_array = 0;
    }
    else
    {
        /* Do nothing */
    }

    /*
     * Requires the user to enter the number of elements in the array. This value will be stored in 'length' variable
     * Base on getIntegerInput(), it will force user input an whole numer. If user input floating-point number,
     * character or numbers is not meaning (i.e 0534, -0654, 54t5, ... ), they will enter again.
     *
     * Moreover, do-while loop help control input in range (0, MAX_SIZE], it only exit when input value
     * is satified with this condition.
     */
    do
    {
        printf("Enter the number of elements in your number-sequence (0 < n <= %d): ", MAX_SIZE);
        length = getIntegerInput();

        if (length > MAX_SIZE)
        {
            printf("\nYour input is larger than %d, please retype!!!\n", MAX_SIZE);
        }
        else if (length <= 0)
        {
            printf("\nYour input is shorter than 1, please retype!!!\n");
        }
        else
        {
            /* Do nothing */
        }

    } while ((length > MAX_SIZE) || (length <= 0));

    /* Assigning the number of current array's element to global variable 'size_of_array' */
    size_of_array = length;

    /*
     * Using for-loop to assign value of each array's elements.
     * getIntegerInput() function is used to control each entered values must be whole number.
     * If user input values such as floating-point number, characters or
     * numbers is not meaning (i.e 0534, -0654, 54t5, ... ), they will enter again.
     */
    for (i = 0; i < length; i++)
    {
        printf("Enter value of the element %d: ", i+1);
        number_sequence[i] = getIntegerInput();
    }

    /* Print the message that the array was successfully created to the console */
    printf("\nCreated number-sequence with %d elements.\n",length);
    printf("... And now you can choose the next options in the menu.");
}

/**
 * @brief Print an array
 *
 * Based on the value of 'size_of_array', the program will check whether the number-sequence
 * has been created or not.
 * If the array has not been created (size_of_array == 0), a message will be printed and
 * the function will be terminated.
 * On the other hand, the array will be created based on going through the for loop and
 * printing the value of each element in the array to the console.
 *
 * @return Void.
 */
void printArray()
{
    int i = 0;

    if (size_of_array == 0)
    {
        printf("Your number-sequence is empty.\n");
        printf("Please create number-sequence first.\n");
    }
    else
    {
        printf("\nYour number-sequence is: ");
        for (i = 0; i < size_of_array; i++)
        {
            printf("%d ", number_sequence[i]);
        }
    }
}


/**
 * @brief  This function is designed to insert an element into an array at a specified position
 *
 * @param position The position where the element will be inserted.
 *                 Note: This value will be calculated from one (i.e the first element is at position 1,
 *                 second element at position 2, and so on).
 *                 For example: array[23, 55, -76, 89] -> 23 at position of first, 55 at position of second and so on
 * @param value Value of element that user want to insert
 * @return Void.
 */
void insertElement(int position, int value)
{
    int k = 0;                     /* Temporaty variable used in for-loop */
    char before_after_option;      /* This variable will store the user's choice of whether to insert before or after the specified position. */

    /*
     * The function first checks if size_of_array is 0 or not, indicating an empty array. If so, it
     * prints a message indicating that the array is empty.
     */
    if (size_of_array == 0)
    {
        printf("\nYour number-sequence is empty.\n");
        printf("Please create number-sequence first.\n");
    }
    /*
     * Next, it checks if the position provided is within the valid range of the array. If not,
     * it prints a message indicating an invalid insertion position.
     */
    else if ((position <= 0) || (position > size_of_array))
    {
        printf("\nInsertion position is not valid.\n");
    }
    /*
     * If the position is valid, the function enters a do-while loop to ask the user whether they
     * want to insert before or after the specified position.
     */
    else
    {
        /*
         * The loop continues until the user enters a valid option ('b','B for before or 'a', 'A' for after).
         */
        do
        {
            printf("You want to insert before or after position %d?\n", position);
            printf("(Input 'b' for before option - 'a' for after option): ");

            /*
             * getSingleCharInput() help to control input value is only a single-character.
             * If user enter more than one character or numbers, they will enter again.
             * Only when they enter exactly 1 character that value is be accepted. Program
             * will continue
             */
            before_after_option = getSingleCharInput();

            switch(before_after_option)
            {
                /*
                 * If the user selects 'a' or 'A' (to insert after the specified position), the function shifts
                 * elements to the right starting from the end of the array to specified position
                 * for making space for the new value.
                 * It then inserts the value after the specified position and increments the
                 * size_of_array
                 */
                case 'a': case 'A':
                {
                    for (k = size_of_array - 1; k >= position; k--)
                    {
                        number_sequence[k + 1] = number_sequence[k];
                    }
                    number_sequence[position] = value;
                    size_of_array += 1;
                    break;
                }
                /*
                 * If the user selects 'b' or 'B' (to insert before the specified position), the
                 * function shifts
                 * elements to the right starting from the end of the array to specified position
                 * for making space for the new value.
                 * It then inserts the value before the specified position and increments the
                 * size_of_array
                 */
                case 'b': case 'B':
                    for (k = size_of_array - 1; k >= position; k--)
                    {
                        number_sequence[k + 1] = number_sequence[k];
                    }
                    number_sequence[position] = number_sequence[position - 1];
                    number_sequence[position - 1] = value;
                    size_of_array += 1;
                    break;
                /* If the user enters an invalid option, the function prompts the user to re-enter the choice */
                default:
                    printf("\nInvalid input, please retype 'a' or 'b' for your option.\n");
                    printf("\n");
                    break;
                }
        } while ((before_after_option != 'a') && (before_after_option != 'A') && (before_after_option != 'B') && (before_after_option != 'b'));

        /* After successfully inserting the value, the function prints a message indicating that the
         element has been inserted. */
        printf("\nInserted your element to number-sequence.\n");
        printf("\n");

        /* Calls printArray() to display the updated array */
        printArray();
    }
}

/**
 * @brief  This function is designed to delete an element from an array at a specified position
 *
 * The function first checks for edge cases like an empty array or invalid deletion position.
 * It then proceeds with the deletion process by shifting elements to the left starting from the
 * position of the element to be deleted.
 * The size of the array is decremented after the deletion.
 *
 * @param del_position The position where the element will be deleted.
 *                 Note: This value will be calculated from one (i.e the first element is at position 1,
 *                 second element at position 2, and so on).
 *                 For example: array[23, 55, -76, 89] -> 23 at position of first, 55 at position of second and so on
 * @return Void.
 */
void deleteElement(int del_position)
{
    int m = 0;                  /* Temporaty variable used in for-loop */

    /*
     * Check if Array is Empty or not. If size_of_array is 0, it means the array is empty.
     * Prints a message indicating that the number sequence is empty and prompts the user to create a
     * number sequence first.
     */
    if (size_of_array == 0)
    {
        printf("\nYour number-sequence is empty.\n");
        printf("Please create number-sequence first.\n");
    }
    /*
     * Checks if the del_position where the user wants to delete the element is within the bounds of
     * the array or not.
     * If the del_position is less than or equal to 0 or greater than 'size_of_array', it prints a
     * message indicating that the deletion position is not valid.
     */
    else if (del_position <= 0 || del_position > size_of_array)
    {
        printf("Invalid deletion position, please enter again!!!\n");
    }
    /* If the array is not empty and the deletion position is valid, it proceeds with the deletion */
    else
    {
        /* Prints a message indicating the value that is deleted and at which position. */
        printf("\nDeleted value %d at position %d.\n", number_sequence[del_position - 1], del_position);

        /* This loop moves each element in the array one position to the left, starting
        from the position of the element to be deleted. */
        for (m = del_position-1; m < size_of_array; m++)
        {
            /*  Assigning the value of number_sequence[m + 1] to number_sequence[m],effectively shifting elements left by one position. */
            number_sequence[m] = number_sequence[m + 1];
        }
        /* Decreasing the size_of_array variable to reflect the removal of an element */
        size_of_array--;

        /* Calls printArray() function to display the updated array */
        printArray();
    }
}

/**
 * @brief  This function is designed to sort an array of integers in ascending order
 *
 * @return Void.
 */
void sortAscending()
{
    int i = 0;                              /* Temporaty variable used in for-loop */
    int j = 0;                              /* Temporaty variable used in for-loop */

    /*
     * Check if Array is Empty or not. If size_of_array is 0, it means the array is empty.
     * Prints a message indicating that the number sequence is empty and prompts the user to create a
     * number sequence first.
     */
    if (size_of_array == 0)
    {
        printf("\nYour number-sequence is empty.\n");
        printf("Please create number-sequence first.\n");
    }
    /* If the array is not empty, it enters the sorting process. */
    else
    {
        for (i = 0; i < size_of_array - 1; i++)
        {
            for (j = 0; j < size_of_array - i - 1; j++)
            {
                if (number_sequence[j] > number_sequence[j + 1])
                {
                    int temp = number_sequence[j];
                    number_sequence[j] = number_sequence[j + 1];
                    number_sequence[j + 1] = temp;
                }
            }
        }

        /* Once the sorting is complete, it prints a message indicating that the number sequence has
         been sorted in ascending order.*/
        printf("\n\nSorted your number-sequence in ascending order.\n");
        /* Calls printArray() function to display the updated array */
        printArray();
    }
}

/**
 * @brief  This function is designed to sort an array of integers in descending order
 *
 * @return Void.
 */
void sortDescending()
{
    int i = 0;                              /* Temporaty variable used in for-loop */
    int j = 0;                              /* Temporaty variable used in for-loop */

    /*
     * Check if Array is Empty or not. If size_of_array is 0, it means the array is empty.
     * Prints a message indicating that the number sequence is empty and prompts the user to create a
     * number sequence first.
     */
    if (size_of_array == 0)
    {
        printf("\nYour number-sequence is empty.\n");
        printf("Please create number-sequence first.\n");
    }
     /* If the array is not empty, it enters the sorting process. */
    else
    {
        for (i = 0; i < size_of_array - 1; i++)
        {
            for (j = 0; j < size_of_array - i - 1; j++)
            {
                if (number_sequence[j] < number_sequence[j + 1])
                {
                    int temp = number_sequence[j];
                    number_sequence[j] = number_sequence[j + 1];
                    number_sequence[j + 1] = temp;
                }
            }
        }
        /* Once the sorting is complete, it prints a message indicating that the number sequence has
         been sorted in descending order.*/
        printf("\n\nSorted your number-sequence in descending order.\n");
        /* Calls printArray() function to display the updated array */
        printArray();
    }
}

/**
 * @brief  This function is designed to find a given number in the array.
 * @param number The number that user want to find in array.
 * @return Void.
 */
void findNumber(int number)
{
    int found = 0;         /* This variable is used as a flag to indicate whether the number has been found in the array or not. Initialized to 0, meaning "not found". */
    int i = 0;             /* Temporaty variable used in for-loop */

    /*
     * Check if Array is Empty or not. If size_of_array is 0, it means the array is empty.
     * Prints a message indicating that the number sequence is empty and prompts the user to create a
     * number sequence first.
     */
    if (size_of_array == 0)
    {
        printf("\nYour number-sequence is empty.\n");
        printf("Please create number-sequence first.\n");
    }
    /*
     * If the array is not empty, it enters a loop to iterate through each element of the array.
     */
    else
    {
        /* In each iteration, it checks if the current element number_sequence[i] is equal to the
        number that user are want to find or not. */
        for (i = 0; i < size_of_array; i++)
        {
            if (number_sequence[i] == number)
            {
                /* If (number_sequence[i] == number), it sets found to 1 to indicate
                 that the number is found. */
                found = 1;
                /* Prints a message indicating that the number is found in the number-sequence at which
                position*/
                printf("%d in your number-sequence at position %d.\n", number, i + 1);
            }
        }
        /* After for-loop. If found is still 0, it means the number was not found in the entire
         array.*/
        if (!found)
        {
            /* Prints a message indicating that the number is not in the number-sequence */
            printf("%d is not in your number-sequence.\n", number);
        }
    }
}

/**
 * @brief Clears the entire console.
 * @return Void.
 */
void clear_console()
{
    printf("\n-------------------------------------------");
    printf("\nPress ANY key to Continue. . .");
    fflush(stdin);
    getch();
    system("cls");
} /* EOF */

