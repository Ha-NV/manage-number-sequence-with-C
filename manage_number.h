#ifndef MANAGE_NUMBER_H
#define MANAGE_NUMBER_H

/* libc includes. */
#include <stdlib.h>         /* for system("cls") */

/**
 * @brief Display options on console for user.
 * @return Void.
 */
void showMenu();

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
void createArray();

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
void printArray();

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
void insertElement(int position, int value);

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
void deleteElement(int del_position);

/**
 * @brief  This function is designed to sort an array of integers in ascending order
 *
 * @return Void.
 */
void sortAscending();

/**
 * @brief  This function is designed to sort an array of integers in descending order
 *
 * @return Void.
 */
void sortDescending();

/**
 * @brief  This function is designed to find a given number in the array.
 * @param number The number that user want to find in array.
 * @return Void.
 */
void findNumber(int number);

/**
 * @brief Clears the entire console.
 * @return Void.
 */
void clear_console();

#endif /* EOF */

