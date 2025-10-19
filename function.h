#ifndef TINYUTILS_H
#define TINYUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdio.h>
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

/**
 * @brief Create a new array that contains all elements of `nums` except those equal to `val`.
 *
 * This function scans the input array, counts elements not equal to `val`,
 * allocates a new int array of that size, and copies the remaining elements.
 * The original array is not modified.
 *
 * @param nums      Pointer to the first element of the input array.
 * @param numsSize  Number of elements in the input array `nums`.
 * @param val       Value to remove (all occurrences are excluded from the result).
 *
 * @return Pointer to a newly allocated array containing the filtered elements.
 *         The caller owns this memory and must free() it. Returns NULL if
 *         memory allocation fails or if numsSize is negative.
 *
 * @note This signature does NOT report the new length. You must track it yourself
 *       (e.g., by re-counting after the call or by changing the API to include an out-size).
 * @complexity O(numsSize) time, O(k) extra space where k is the number of kept elements.
 */
int *removeElement(int *nums, int numsSize, int val);

/**
 * @brief Merges two integer arrays into a single new array.
 *
 * This function allocates a new block of memory large enough to contain
 * all elements from both input arrays `a` and `b`, and copies the elements
 * of `a` followed by the elements of `b` into that new array.
 * The caller is responsible for freeing the returned pointer using `free()`.
 *
 * @param a Pointer to the first input array.
 * @param size_a The number of elements in the first array.
 * @param b Pointer to the second input array.
 * @param size_b The number of elements in the second array.
 * @return Pointer to the newly allocated merged array containing all elements
 *         from both `a` and `b`. Returns `NULL` if memory allocation fails.
 */
int *merge_arrays(const int *a, int size_a, const int *b, int size_b);

/**
 * @brief Build a newly-allocated string containing only the vowels from the input.
 *
 * Scans the null-terminated input string and copies all ASCII vowels
 * ('a','e','i','o','u' and their uppercase variants) into a new
 * null-terminated buffer. The caller owns the returned buffer and must free it
 * with free(). If @p out_len is not NULL, it will receive the number of
 * vowels written (excluding the terminating '\0').
 *
 * @param string   Null-terminated input string (not modified).
 * @param size     Size of array.
 * @return char*   Pointer to a newly-allocated null-terminated string with
 *                 only vowels, or NULL on allocation failure or if @p string is NULL.
 *
 * @note Time complexity: O(n). Space complexity: O(k), where k is the number
 *       of vowels in @p string (+1 for the terminator).
 * @warning The caller must free the returned pointer with free().
 */
char *vowels_string(const char *string, int size);

/**
 * @brief Remove all occurrences of a substring from a string in place.
 *
 * Scans the null-terminated @p string and removes every (case-sensitive)
 * occurrence of @p word by shifting the remainder of the buffer left.
 * The operation is performed in place; no new memory is allocated.
 *
 * @param string  Mutable, null-terminated input buffer to modify.
 *                 If NULL, the function does nothing and returns NULL.
 * @param word    Null-terminated substring to remove.
 *                 If NULL or empty (""), the function makes no changes.
 *
 * @return char*  The same pointer as @p string (for chaining), or NULL if @p string is NULL.
 *
 * @note Overlapping cases are handled by continuing the search from the
 *       removal point (e.g., "aaaa" with "aa" becomes "").
 * @note This function is case-sensitive and does not enforce word boundaries.
 * @warning The caller must ensure @p string points to a writable buffer.
 *
 * @complexity Time: O(n * k) in the worst case (due to repeated strstr),
 *             Space: O(1) extra.
 */
char *word_remover(char *string, char *word);

/**
 * @brief Bubble-sort an array of fixed-size strings by length (ascending).
 *
 * @param strings [in,out] strings[size][100]; each element must be null-terminated.
 * @param size    Number of strings.
 * @return Number of swaps performed; 0 if size < 2.
 *
 * @details Stable with respect to equal lengths.
 * @complexity O(n^2 * L), where L is max string length (uses strlen).
 */
int bubble_sort_strings(char strings[][100], size_t size);

/**
 * @brief Return the index of the string with the fewest vowels in [start, size).
 *
 * @param strings Input array: strings[size][100]; elements are null-terminated.
 * @param start   Start index (inclusive).
 * @param size    Total number of strings.
 * @return Index of the leftmost string with minimal vowel count in the range.
 *
 * @pre  start < size.
 * @complexity O((size - start) * L).
 */
size_t find_string_with_fewest_vowels(const char strings[][100], size_t start, size_t size);

/**
 * @brief Selection-sort strings by vowel count (ascending).
 *
 * @param strings [in,out] strings[size][100]; each element null-terminated.
 * @param size    Number of strings.
 * @return Number of swap operations performed by the implementation.
 *
 * @note Your current code swaps on every outer pass, so the return value equals size.
 *       If you want to count only real swaps, increment the counter only when min_index != i.
 * @complexity O(n^2 * L). Not stable.
 */
int selection_sort_strings(char strings[][100], size_t size);

/**
 * @brief Print an integer array as comma-separated values, preceded by a newline.
 *
 * @param array Read-only pointer to the first element to print.
 * @param size  Number of elements in @p array to print.
 *
 * @details Outputs a leading '\n', then prints elements as "a,b,c" (no trailing comma).
 *          Does not append a newline at the end of the list.
 *          Example output for {1,2,3}: "\n1,2,3"
 *
 * @pre array != NULL; size >= 0.
 * @complexity O(size).
 */
void print_numbers(const int array[], int size);

/**
 * @brief Returns the minimum and maximum values found in an integer array.
 *
 * Scans the array once (O(n)) and allocates a 2-element int buffer on the heap
 * containing {min, max} in that order.
 *
 * @param numbers  Pointer to the first element of the input array.
 *                 Must not be NULL when @p size > 0.
 * @param size     Number of elements in the array.
 *
 * @return Pointer to a newly allocated array of two ints: result[0] = min,
 *         result[1] = max. Returns NULL if @p numbers is NULL or @p size == 0.
 *
 * @note  The caller owns the returned memory and must release it with free().
 * @note  Works with any int values (including negatives and zero).
 */
int *minmax(const int numbers[], size_t size);

/**
 * @brief In-place reversal of each word in a C string.
 *
 * Reverses every maximal sequence of non-whitespace characters in-place,
 * preserving the original whitespace characters and their positions.
 * Whitespace is determined via isspace(3). The input string must be
 * NUL-terminated and mutable.
 *
 * @param string  Pointer to a writable, NUL-terminated char buffer.
 * @param size    (Unused) Reserved for future use; can be 0. The function
 *                relies on the terminating '\0' rather than this value.
 *
 * @return void
 *
 * @note Behavior is undefined if @p string is NULL or points to read-only memory.
 * @note Uses isspace((unsigned char)ch); make sure to include <ctype.h>.
 *
 * @example
 *   char s[] = "hello  world\tC";
 *   reverse_words(s, 0);
 *   // s becomes: "olleh  dlrow\tC"
 */
void reverse_words(char string[], int size);


/**
 * @brief Check for an equal pair among mirrored elements of an array.
 *
 * @details The function compares elements symmetrically from both ends:
 *          a[0] with a[n-1], a[1] with a[n-2], and so on, moving inward.
 *          It does NOT test all pairs, so it may return false even if
 *          duplicates exist elsewhere in the array.
 *
 * @param array Pointer to the first element of the integer array (must not be NULL).
 * @param size  Number of elements in the array (>= 0).
 *
 * @return true if any checked mirrored pair is equal; false otherwise.
 *
 * @pre If size < 2, the function always returns false.
 * @complexity O(n) time, O(1) extra space.
 * @warning For detecting any duplicate anywhere, use a different method
 *          (e.g., sort + linear scan or a hash set).
 */
bool duplicate(int array[], int size);

/**
 * @brief Extract the middle character(s) of a C string.
 *
 * For an odd-length string returns a newly allocated string of length 1
 * containing the single middle character. For an even-length string returns
 * a newly allocated string of length 2 containing the two middle characters.
 *
 * @param[in] inp  Non-NULL pointer to a NUL-terminated string.
 * @return char*   On success, heap-allocated NUL-terminated string that the caller must free.
 *                 If @p inp has length 0, returns NULL (per current implementation).
 *                 If memory allocation fails, returns NULL.
 *
 * @pre  @p inp must not be NULL.
 * @note The caller owns the returned buffer and must call free() on it.
 * @complexity O(n) time, O(1) extra space (excluding the returned buffer),
 *             where n = strlen(inp).
 */
char *get_middle(const char *inp);

/**
 * @brief Remove all whitespace characters from a string in-place.
 *
 * Copies only non-whitespace characters (as defined by isspace) forward,
 * preserving their order. The result is NUL-terminated.
 *
 * @param[in,out] string  Non-NULL pointer to a modifiable NUL-terminated buffer.
 *                        The buffer is modified in-place.
 *
 * @return void
 *
 * @pre  @p string must not be NULL and must be writable.
 * @post The string contains no spaces, tabs, newlines, etc.
 * @complexity O(n) time, O(1) extra space, where n = original strlen(string).
 */
void space_remover(char string[]);

/**
 * @brief Decodes a NUL-terminated string in-place using the Atbash cipher.
 *
 * For each alphabetic character, maps it to its mirror within the alphabet
 * (a<->z, b<->y, ... and A<->Z). Whitespace characters are left unchanged.
 * All other non-alphabetic characters are also left unchanged.
 *
 * @param string Pointer to a mutable NUL-terminated character buffer.
 *               Must not be NULL.
 */
void decode(char *string);

/**
 * @brief Computes the sum of all decimal digits present in a string.
 *
 * Scans the NUL-terminated string and adds the numeric value of each digit
 * ('0'..'9') to the running total. Non-digit characters are ignored.
 *
 * @param string Pointer to a NUL-terminated character buffer. Not modified.
 *               Must not be NULL.
 * @return The sum of all digits found in the string (0..9 per digit).
 */
int sumstr(const char *string);

/**
 * @brief Remove the first and last character from a string in place.
 *
 * Copies characters from index 1..(size-2) to the front and writes a
 * terminating NUL byte at the end.
 *
 * @param string Mutable character buffer to edit (must have at least @p size bytes).
 * @param size   Logical length of the input (number of characters to consider).
 *               If @p size < 2, the result becomes an empty string.
 */
void first_and_last_character_remover(char string[], size_t size);

/**
 * @brief Round an integer up to the nearest multiple of 5.
 *
 * For positive numbers behaves like ceil(n/5.0)*5; for negatives still rounds
 * toward +infinity (e.g., -1 -> 0, -6 -> -5).
 *
 * @param number Input integer.
 * @return Rounded value that is a multiple of 5 and >= number.
 */
int round_up_5(int number);

/**
 * @brief Count decimal digits in a non-negative integer.
 *
 * @param number Non-negative integer to inspect.
 * @return Number of decimal digits. Note: returns 0 for input 0 in this
 *         implementation; many APIs return 1 for 0. Define the behavior you want.
 */
int size_array(int number);

/**
 * @brief Split a non-negative integer into its decimal digits.
 *
 * Resulting array contains digits in reading order (most significant first).
 * Caller owns the returned memory and must free it.
 *
 * @param number Non-negative integer to split.
 * @return Pointer to a heap-allocated array of digits (int 0..9), or NULL on allocation failure.
 *         The length of the array is size_array(number).
 */
int *numbers_divider(int number);

/**
 * @brief qsort-compatible comparator for ascending order of ints.
 *
 * @param a Pointer to first int element.
 * @param b Pointer to second int element.
 * @return <0 if *a < *b, 0 if equal, >0 if *a > *b.
 */
int comp(const void *a, const void *b);

/**
 * @brief Assemble an integer from an array of decimal digits.
 *
 * Interprets @p numbers as digits in reading order (most significant first).
 * Behavior is undefined if digits are outside 0..9 or if overflow occurs.
 *
 * @param numbers Array of digits (each 0..9).
 * @param size    Number of elements in @p numbers.
 * @return The assembled integer value.
 */
int array_to_integer(int *numbers, int size);

/**
 * @brief Compute the next greater number using the same digits as @p n.
 *
 * If no greater permutation exists (digits are in non-increasing order),
 * returns -1. Uses 64-bit range for the result.
 *
 * @param n Input number (non-negative expected).
 * @return Next greater permutation of digits, or -1 if impossible.
 */
long long next_bigger_number(long long n);

#ifdef __cplusplus
}
#endif

#endif /* TINYUTILS_H */
