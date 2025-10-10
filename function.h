#ifndef TINYUTILS_H
#define TINYUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

/**
 * @brief Checks if a string contains only whitespace characters.
 * @param s Null-terminated string to check.
 * @return true if the string contains only whitespace; false otherwise.
 */
bool contains_only_whitespace(const char s[]);

/**
 * @brief Counts the number of words (alphanumeric sequences) in a string.
 * @param s Null-terminated string.
 * @return The number of words found in the string.
 */
int count_words(const char s[]);

/**
 * @brief Counts the number of alphabetic characters.
 * @param s Null-terminated string.
 * @return The number of letters in the string.
 */
int count_letters(const char s[]);

/**
 * @brief Counts the number of digits.
 * @param s Null-terminated string.
 * @return The number of digit characters in the string.
 */
int count_digits(const char s[]);

/**
 * @brief Counts the number of uppercase letters.
 * @param s Null-terminated string.
 * @return The number of uppercase characters in the string.
 */
int count_uppercase(const char s[]);

/**
 * @brief Counts the number of lowercase letters.
 * @param s Null-terminated string.
 * @return The number of lowercase characters in the string.
 */
int count_lowercase(const char s[]);

/**
 * @brief Safely reads a string from stdin into a buffer of fixed size.
 *        Removes the trailing newline character if present.
 * @param s Character buffer to store the input string.
 * @param size Size of the buffer in bytes.
 */
void read_string(char s[], const int size);

/**
 * @brief Calculates the sum of all elements in an integer array.
 * @param numbers Pointer to the first element of the array.
 * @param size Number of elements in the array.
 * @return The total sum of the array elements.
 */
int sum_array(int numbers[], int size);

/**
 * @brief Finds the minimum element in an integer array.
 * @param arr Pointer to the first element of the array.
 * @param size Number of elements in the array (must be > 0).
 * @return The smallest value found in the array.
 */
int min_number(int *arr, int size);

/**
 * @brief Finds the maximum element in an integer array.
 * @param arr Pointer to the first element of the array.
 * @param size Number of elements in the array (must be > 0).
 * @return The largest value found in the array.
 */
int max_number(int *arr, int size);

/**
 * @brief Reverses the order of elements in an integer array in place.
 * @param arr Pointer to the first element of the array.
 * @param size Number of elements in the array.
 */
void reverse_array(int *arr, int size);

/**
 * @brief Removes negative numbers from a dynamically allocated array in place.
 *        Memory is reallocated to fit the new size.
 *
 * @param arr [in,out] Address of the array pointer (int**). May be reallocated.
 * @param size [in,out] Address of the size variable. Updated with the new size.
 */
void remove_negatives(int **arr, int *size);

/**
 * @brief Print an 8-bit unsigned value in binary.
 * @param value  Byte (0..255) to print.
 * @param group4 If non-zero, insert spaces every 4 bits (e.g., "0101 1010").
 */
void print_u8_binary(unsigned char value, int group4);

/**
 * @brief Convert a null-terminated byte string to a newly allocated flat array of bits (MSB → LSB).
 *
 * Each input byte yields 8 integers (0/1), most-significant-bit first.
 * Example: "A" (0x41) → {0,1,0,0,0,0,0,1}.
 *
 * @param s  Null-terminated input string (must not be NULL).
 * @return   Pointer to an int array of length 8 * strlen(s) on success,
 *           or NULL if allocation fails or s is NULL.
 *
 * @warning  Caller must compute output length as 8 * strlen(s) and free() the result.
 * @note     Bits are taken per byte; UTF-8 is treated as raw bytes. Use (unsigned char) for shifts.
 */
int *str_to_bits(const char *s);
#ifdef __cplusplus
}
#endif

#endif /* TINYUTILS_H */
