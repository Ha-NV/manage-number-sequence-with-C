/**
 * @file get_input.c
 * @brief This file contains declarations and purpose of functions that use for get input from user.
 *        Functions such as get an whole number from user, get a single-character from user.
 * @author Viet Ha Nguyen
 * @bug No known bugs
 */
#ifndef GET_INPUT_H
#define GET_INPUT_H

/*******************************************************************************
 * INCLUDE
 ******************************************************************************/
#include <stdio.h>
#include <stdbool.h>         /* for bool datatype */
#include <string.h>          /* for strcspn() function */
#include <ctype.h>           /* for isdigit () function */


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
int getIntegerInput();

/**
 * @brief This function is designed to get a single character input from the user.
 *        It ensures that the user only enters one character and then returns that character.
 * @return single character
 */
char getSingleCharInput();

#endif /* EOF */

