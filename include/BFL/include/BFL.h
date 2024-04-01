/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BFL.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:46:21 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/31 23:19:14 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#ifndef BFL_H
# define BFL_H

/* <-- Defines Section --> */

# define BUFFER_SIZE 1024

/* <-- Libraries Section --> */

/* ==========================================================================*/

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
/* ==========================================================================*/

/* <-- Typedef Section --> */

/* ==========================================================================*/

typedef enum e_bool			t_bool;
typedef struct s_print		t_print;
typedef struct s_ll			t_ll;
typedef struct s_dll		t_dll;
/* ==========================================================================*/

/* <-- Enum Section --> */

/* ==========================================================================*/

/**
 * @brief Custom bool
 *
 */
enum e_bool
{
	FALSE,	/**< 0 */
	TRUE,	/**< 1 */
};

/**
 * @brief Custom fd
 */
enum e_fd
{
	STDIN,	/**< 0 */
	STDOUT,	/**< 1 */
	STDERR,	/**< 2 */
};

/**
 * @brief Custom exit status
 */
enum e_exit_status
{
	OK,					/**< 0 */
	KO,					/**< 1 */
	RIP_MALLOC,			/**< 2 */
	INVALID_ARGC,		/**< 3 */
	EXIT_STATUS_LIMIT,	/**< Amount of enums */
};
/* ==========================================================================*/

/* <-- Structs Section --> */

/* ==========================================================================*/
/* ft_fprintf */

/**
 * @struct s_print
 * @brief Structure with information needed for printf functions.
 */
struct s_print
{
	int		index; /**< Index for the string being read. */
	int		bytes; /**< Total amount of bytes read. */
	int		success; /**< Amount of bytes read successfully. */
};
/* ==========================================================================*/

/* ==========================================================================*/
/* Linked List */

/**
 * @struct s_ll
 * @brief Structure representing a node in a linked list.
 */
struct s_ll
{
	void	*content; /**< Pointer to the content of the current node. */
	t_ll	*next; /**< Pointer to the next node. */
};
/* ==========================================================================*/

/* ==========================================================================*/
/* Doubly Linked List */

/**
 * @struct s_dll
 * @brief Structure representing * a node in a double linked list.
 */
struct s_dll
{
	void	*content; /**< Pointer to the content of the current node. */
	t_dll	*previous; /**< Pointer to the previous node. */
	t_dll	*next; /**< Pointer to the next node */
};
/* ==========================================================================*/

/* <--Functions Section--> */

/* ========================================================================= */
/* Bool */

/**
 * @brief Checks if a character is valid alphanumeric character.
 *
 * @details This function checks whether the given integer corresponds to a
 * valid alphanumeric character. Alphanumeric characters have integer values
 * between 48 and 57 (inclusive), 65 and 90 (inclusive) or 97 and 122
 * (inclusive).
 *
 * @param character The integer value to be checked for alphanumeric validity.
 *
 * @return - 1 if the character is a valid alphanumeric character.
 * @return - 0 otherwise.
 */
int					ft_isalnum(int character);

/**
 * @brief Checks if a character is valid alphabetic character.
 *
 * @details This function checks whether the given integer corresponds to a
 * valid alphabet character.
 *
 * @param character The integer value to be checked for alphabet validity.
 *
 * @return - 1 if the character is a valid alphabet character.
 * @return - 0 otherwise.
 */
int					ft_isalpha(int character);

/**
 * @brief Checks if a character is valid alpha character.
 *
 * @details This function checks whether the given integer corresponds to a
 * valid alpha character. Alpha characters have integer values between 65 and
 * 90 (inclusive) or 97 and 122.
 *
 * @param character The integer value to be checked for alpha validity.
 *
 * @return - 1 if the character is a valid alpha character.
 * @return - 0 otherwise.
 */
int					ft_isascii(int character);

/**
 * @brief Checks if a character is valid blank character.
 *
 * @details This function checks whether the given integer corresponds to a
 * valid blank character. Blank characters have integer values of 9 and 32.
 *
 * @param character The integer value to be checked for blank validity.
 *
 * @return - 1 if the character is a valid blank character.
 * @return - 0 otherwise.
 */
int					ft_isblank(int character);

/**
 * @brief Checks if a character is valid digit character.
 *
 * @details This function checks whether the given integer corresponds to a
 * valid digit character. Digit characters have integer values between
 * 48 and 57.
 *
 * @param character The integer value to be checked for digit validity.
 *
 * @return - 1 if the character is a valid digit character.
 * @return - 0 otherwise.
 */
int					ft_isdigit(int character);

/**
 * @brief Checks if a character is a valid lowercase alphabetic character.
 *
 * @details This function checks whether the given integer corresponds to a
 * valid lowercase alphabetic character. Lowercase letters have integer
 * values between 97 and 122 (inclusive).
 *
 * @param character The integer value to be checked for lowercase alphabetic
 * validity.
 *
 * @return - 1 if the character is a valid lowercase alphabetic character
 * @return - 0 otherwise.
 */
int					ft_islower(int character);

/**
 * @brief Checks if a character is a printable character.
 *
 * @details This function checks whether the given integer corresponds to a
 * printable character, which includes alphanumeric characters and special
 * symbols having integer values between 32 and 126 (inclusive).
 *
 * @param character The integer value to be checked for printable character
 * validity.
 *
 * @return - 1 if the character is a printable character.
 * @return - 0 otherwise.
 */
int					ft_isprint(int character);

/**
 * @brief Checks if a character is a valid uppercase alphabetic character.
 *
 * @details This function checks whether the given integer corresponds to a
 * valid uppercase alphabetic character. Uppercase letters have integer
 * values between 65 and 90 (inclusive).
 *
 * @param character The integer value to be checked for uppercase alphabetic
 * validity.
 *
 * @return - 1 if the character is a valid uppercase alphabetic character.
 * @return - 0 otherwise.
 */
int					ft_isupper(int character);

/**
 * @brief Checks if a character is a valid hexadecimal digit.
 *
 * @details This function checks whether the given integer corresponds to a
 * valid hexadecimal digit. Hexadecimal digits include 0-9 and A-F (or a-f)
 * and have integer values between 48 and 57, and 65 to 70 (or 97 to 102)
 * inclusive.
 *
 * @param character The integer value to be checked for hexadecimal digit
 * validity.
 *
 * @return - 1 if the character is a valid hexadecimal digit.
 * @return - 0 otherwise.
 */
int					ft_isxdigit(int character);
/* ========================================================================= */

/* ========================================================================= */
/* Char */

/**
 * @brief Converts an uppercase alphabetic character to lowercase.
 *
 * @details This function checks whether the given integer corresponds to an
 * uppercase character, and then converts it to lowercase.
 *
 * @param character The integer value to be checked for uppercase character
 * validity.
 *
 * @return - character lowercased.
 * @return - character unmodified.
 */
int					ft_tolower(int character);

/**
 * @brief Converts an lowercase alphabetic character to uppercase.
 *
 * @details This function checks whether the given integer corresponds to a
 * lowercase character, and then converts it to uppercase.
 *
 * @param character The integer value to be checked for lowercase character
 * validity.
 *
 * @return - character uppercased.
 * @return - character unmodified.
 */
int					ft_toupper(int character);
/* ========================================================================= */

/* ========================================================================= */
/* Data Structures*/

/**
 * @brief Create a new linked list node.
 *
 * @details This function allocates memory for a new linked list node.
 *
 * @return - A pointer to the newly created linked list node.
 * @return - NULL if memory allocation fails.
 *
 * @note The caller is responsible for freeing the memory allocated.
 */
t_ll				*ll_create_node(void);

/**
 * @brief Add a new node to the linked list.
 *
 * @details This function appends a new node to the linked list.
 *
 * @param linked_list Address of the linked list.
 *
 * @note The caller is responsible for freeing the memory allocated.
 */
void				ll_add_node(t_ll **linked_list);

/**
 * @brief Generate a linked list of a specified length.
 *
 * @details This function generates a linked list of the specified length,
 * with each node initialized and linked.
 *
 * @param length The length of the linked list to generate.
 *
 * @return - A pointer to the head of the generated linked list.
 * @return - NULL if memory allocation fails.
 *
 * @note The caller is responsible for freeing the memory allocated.
 */
t_ll				*ll_generator(int length);

/**
 * @brief Destroy the content of a linked list node.
 *
 * @details This function frees the memory allocated for the content
 * of a linked list node.
 *
 * @param linked_list Address of the linked list node.
 */
void				ll_destroy_content(t_ll **linked_list);

/**
 *	@brief Destroy a linked list.
 *
 *	@details This function frees the memory for the entire linked list,
 *	including its nodes and content.
 *
 *	@param linked_list Pointer to the head of the linked list.
 */
void				ll_destroy(t_ll **linked_list);
/* ========================================================================= */

/* ========================================================================= */
/* Fd */

/**
 * @brief Puts a character into a file descriptor.
 *
 * @details This function writes a character in a given file descriptor.
 *
 * @param character The character to be put in the file descriptor.
 * @param fd The file descriptor where the character is going to be put.
 *
 * @return - 1 if it writes the character correctly.
 * @return - -1 if there's an error writing the character.
 */
int					ft_putchar_fd(char character, int fd);

/**
 * @brief Puts a string into a file descriptor.
 *
 * @details This function writes a string in a given file descriptor.
 *
 * @param str The string to be put in the file descriptor.
 * @param fd The file descriptor where the character is going to be put.
 *
 * @return - 1 if it writes the string correctly.
 * @return - -1 if there's an error writing the string.
 *
 * @note If the string is null, it writes (null).
 */
int					ft_putstr_fd(const char *str, int fd);

/**
 * @brief Puts a string with a newline into a file descriptor.
 *
 * @details This function writes a string with a newline at the end
 * of the string in a given file descriptor.
 *
 * @param str The string to be put in the file descriptor.
 * @param fd The file descriptor where the character is going to be put.
 *
 * @return - 1 if it writes the string correctly.
 * @return - -1 if there's an error writing the string.
 */
int					ft_putendl_fd(const char *str, int fd);

/**
 * @brief Write an integer to a file descriptor.
 *
 * @details This function writes an integer in a given file descriptor.
 *
 * @param number The integer to be written.
 * @param fd The file descriptor where the integer will be written.
 *
 * @return - The number of bytes written on success.
 * @return - -1 if the file descriptor is invalid or if there are
 * memory allocation or writing errors.
 */
int					ft_putnbr_fd(int number, int fd);

/**
 * @brief Converts an unsigned integer to a hexadecimal representation
 * (lowercase) and writes it to a file descriptor.
 *
 * @details This function takes an unsigned integer `number` and writes
 * its hexadecimal representation (lowercase) to the specified file
 * descriptor `fd`. It uses the ft_puthex helper function for the conversion.
 * If the given number is zero, it writes '0' to the file descriptor.
 *
 * @param number The unsigned integer to convert.
 * @param fd The file descriptor to write the hexadecimal representation
 * (lowercase) to.
 *
 * @return The total number of bytes written
 * @return -1 in case of an error.
 */
int					ft_puthexl_fd(unsigned long long n, int fd);

/**
 * @brief Converts an unsigned integer to a hexadecimal representation
 * (uppercase) and writes it to a file descriptor.
 *
 * @details This function takes an unsigned integer `number` and writes
 * its hexadecimal representation (uppercase) to the specified file
 * descriptor `fd`. It uses the ft_puthex helper function for the conversion.
 * If the given number is zero, it writes '0' to the file descriptor.
 *
 * @param number The unsigned integer to convert.
 * @param fd The file descriptor to write the hexadecimal representation
 * (uppercase) to.
 *
 * @return The total number of bytes written
 * @return -1 in case of an error.
 */
int					ft_puthexu_fd(unsigned long long n, int fd);

/**
 * @brief Writes the decimal representation of an unsigned integer
 * to a file descriptor.
 *
 * @details This function takes an unsigned integer `number` and
 * writes its decimal representation to the specified file descriptor
 * `fd`. It uses the ft_putunbr helper function for the conversion.
 * If the given number is zero, it writes '0' to the file descriptor.
 *
 * @param number The unsigned integer to convert and write.
 * @param fd The file descriptor to write the decimal representation to.
 *
 * @return The total number of bytes written
 * @return -1 in case of an error.
 */
int					ft_putunbr_fd(unsigned int number, int fd);

/**
 * @brief Prints the hexadecimal representation of a pointer to a file
 * descriptor.
 *
 * @details This function takes a pointer and writes its hexadecimal
 * representation (lowecase) to the specified file descriptor. The pointer
 * is cast to an unsigned long long to ensure proper printing, accommodating
 * both 32-bit and 64-bit systems.
 *
 * @param ptr The pointer to be printed.
 * @param fd The file descriptor to write the hexadecimal representation to.
 *
 * @return The total number of bytes written
 * @return -1 in case of an error.
 */
int					ft_putaddress_fd(unsigned long long ptr, int fd);
/* ==========================================================================*/

/* ==========================================================================*/
/* Ft_printf */

/**
 * @brief Custom printf implementation with limited format specifiers.
 *
 * @details This function emulates the behavior of printf for a subset
 * of format specifiers. It supports the following format
 * specifiers: %c (character), %s (string), %d or %i (decimal/integer),
 * %u (unsigned decimal/integer), %x (hexadecimal lowercase),
 * %X (hexadecimal uppercase), and %p (pointer).
 *
 * @param str The format string containing format specifiers.
 * @param ... Variable arguments corresponding to the format specifiers
 * in the format string.
 *
 * @return The total number of bytes written to the standard output
 * @return -1 in case of an error.
 */
int					ft_printf(const char *str, ...);

/**
 * @brief Custom fprintf implementation with limited format specifiers.
 *
 * @details This function emulates the behavior of fprintf for a subset
 * of format specifiers. It supports the following format
 * specifiers: %c (character), %s (string), %d or %i (decimal/integer),
 * %u (unsigned decimal/integer), %x (hexadecimal lowercase),
 * %X (hexadecimal uppercase), and %p (pointer).
 *
 * @param fd The file descriptor to output the string.
 * @param str The format string containing format specifiers.
 * @param ... Variable arguments corresponding to the format specifiers
 * in the format string.
 *
 * @return The total number of bytes written to the standard output
 * @return -1 in case of an error.
 */
int					ft_fprintf(int fd, const char *str, ...);
/* ==========================================================================*/

/* ==========================================================================*/
/* Get_next_line */

/**
 * @brief Reads a line from a file descriptor.
 *
 * @details This function reads a line from the specified file
 * descriptor and returns it as a dynamically allocated string.
 * It uses a static variable to keep track of the remaining
 * content from previous reads. The function allocates
 * memory as needed, concatenates read content, and handles
 * newline characters.
 *
 * @param fd The file descriptor from which to read the line.
 *
 * @return A pointer to the line read from the file descriptor
 * @return NULL if there is an error or the end of file is reached.
 *
 * @note The caller is responsible for freeing the memory allocated for the
 * returned line. The function uses a static variable to maintain content
 * between calls. If BUFFER_SIZE is set to a value less than 1, or if there
 * is a memory allocation failure, the function returns NULL.
 */
char				*get_next_line(int fd);
/* ==========================================================================*/

/* ==========================================================================*/
/* Math */

/**
 * @brief Calculate the Greatest Common Divisor.
 *
 * @details Calculate the Greatest Common Divisor using the
 * Euclidean algorithm.
 *
 * @param number1 The first number, must be positive.
 * @param number2 The second number, must be positive.
 *
 * @return The Greatest Common Divisor between number1 and number2.
 */
size_t				ft_gcd(size_t number1, size_t number2);

/**
 * @brief Calculate the Least Common Multiple.
 *
 * @details Calculate the Least Common Multiple using the
 * formula lcm(a, b) = a * b / gcd(a, b).
 *
 * @param number1 The first number, must be positive.
 * @param number2 The second number, must be positive.
 *
 * @return - The Least Common Multiple between number1 and number2.
 * @return - 0 If number1 and number2 are 0.
 */
unsigned long		ft_lcm(size_t number1, size_t number2);

/**
 * @brief Calculate the nth power of a number.
 *
 * @details Calculate the nth power of a number.
 *
 * @param number The base number.
 * @param exponent The exponent of the number.
 *
 * @return The result of number^exponent.
 */
double				ft_pow(double number, int exponent);
/* ==========================================================================*/

/* ==========================================================================*/
/* Memory */

/**
 * @brief Sets the pointer with character an n-bytes amount.
 *
 * @details This function sets in the memory of a pointer, a character
 * an n-bytes amount.
 *
 * @param ptr The pointer that will be set by character an n-bytes amount.
 * @param character The character that will be set in ptr.
 * @param bytes The amount of bytes that character will be set in ptr.
 *
 * @note If ptr is NULL doesn't do anything.
 */
void				ft_memset(void *ptr, int character, size_t bytes);

/**
 * @brief Sets the pointer with null character an n-bytes amount.
 *
 * @details This function sets in the memory of a pointer, a null character
 * an n-bytes amount.
 *
 * @param ptr The pointer that will be set by character an n-bytes amount.
 * @param bytes The amount of bytes that character will be set in ptr.
 *
 * @note If ptr is NULL doesn't do anything.
 */
void				ft_bzero(void *ptr, size_t bytes);

/**
 * @brief Allocates memory for a pointer and initializes them with
 * null characters.
 *
 * @details This function allocates n-bytes of memory, each with sizetype
 * size and initializes them with null characters.
 *
 * @param bytes The total number of bytes to allocate memory for.
 * @param size_type The size (in bytes) of each element.
 *
 * @return - A pointer with memory allocated and set with null characters if
 * successful.
 * @return - A NULL pointer if the allocation fails.
 *
 * @note The caller is responsible for freeing the memory allocated.
 */
void				*ft_calloc(size_t bytes, size_t size_type);

/**
 * @brief Locate a byte in a memory block.
 *
 * @details This function searches the first bytes of the memory block
 * pointed to by ptr for the first ocurrence of the byte character.
 *
 * @param ptr Pointer to the memory block to be searched.
 * @param character Value of the byte to be located (as an integer).
 * @param bytes Number of bytes to be searched.
 *
 * @return - A pointer to the first ocurrence of character in the memory block
 * @return - NULL if c is not found or ptr is NULL.
 */
void				*ft_memchr(const void *ptr, int character, size_t bytes);

/**
 * @brief Copy memory from one location to another.
 *
 * @details This function copies bytes of memory from str2 to str. The memory
 * blocks must not overlap.
 *
 * @param str Pointer to the destination memory block.
 * @param str2 Pointer to the source memory block.
 * @param bytes Number of bytes to copy.
 *
 * @return - A pointer to the destination memory block str after copying.
 * @reval - NULL if either str or str2 is NULL.
 *
 */
void				*ft_memcpy(void *str, const void *str2, size_t bytes);

/**
 * @brief Copy memory from one location to another, handling overlapping
 * regions.
 *
 * @details This function copies bytes of memory from str2 to str. Unlike
 * ft_memcpy, this function handles overlapping memory regions correctly.
 *
 * @param str Pointer to the destination memory block.
 * @param str2 Pointer to the source memory block.
 * @param bytes Number of bytes to copy.
 *
 * @return - A pointer to the destination memory block (str) after copying.
 * @return - NULL if either str or str2 is NULL.
 *
 * @note If there is an overlap between the source and destination memory
 * blocks, the function uses a byte-by-byte copy to ensure correct results.
 * @note If bytes is zero, the function does nothing and returns str.
 */
void				*ft_memmove(void *str, const void *str2, size_t bytes);

/**
 * @brief Compare memory blocks up to a specified number of bytes.
 *
 * @details This function compares the first bytes of str and str2.
 * The comparison is case-sensitive, and the result is based on the
 * difference between the unsigned char values at corresponding
 * positions in the memory blocks.
 *
 * @param str Pointer to the first memory block to be compared.
 * @param str2 Pointer to the second memory block to be compared.
 * @param bytes Number of bytes to compare.
 *
 * @return - An integer greater than, equal to, or less than 0
 * if the first bytes of str are greater than, equal to, or
 * less than the first bytes of str2 respectively
 */
int					ft_memcmp(const void *str, const void *str2, size_t bytes);

/**
 * @brief Free a pointer (up to triple pointer) and set to NULL.
 *
 * @details This function frees a pointer (up to a triple pointer)
 * and sets it to NULL. The number of pointers to be freed is
 * determined by the value of ptr_size.
 *
 * @param ptr_address Address of the pointer.
 * @param asterisk_amount Amount of asterisks.
 *
 * @return NULL if ptr_address is NULL or the pointer is freed
 * successfully.
 *
 * @note When asterisk_amount is greater than 1, the every pointer
 * must be NULL terminated.
 */
void				*ft_free(void *ptr_address, size_t asterisk_amount);

/**
 * @brief Reallocate a pointer with a specified size.
 *
 * @details This function reallocates a pointer with a new specified size.
 *
 * @param ptr Pointer to be reallocated.
 * @param current_size Current used size of ptr.
 * @param new_size New size of ptr.
 * @param element_size Size of the elements of ptr.
 *
 * @return - ptr if reallocation is successful.
 * @return - NULL if reallocation fails or either new_size or element_size
 * is 0.
 *
 * @note ptr must be initialised to NULL or with allocated memory.
 * @note The caller is responsible for freeing the memory allocated.
 */
void				*ft_realloc(void *ptr, size_t current_size, size_t new_size,
						size_t element_size);
/* ==========================================================================*/

/* ==========================================================================*/
/* String */

/**
 * @brief Calculates the length of a string.
 *
 * @details This function calculates the length of the string.
 *
 * @param str The string that will be used to calculate the length.
 *
 * @return - The length of the string.
 * @return - 0 if str is empty or NULL.
 */
size_t				ft_strlen(const char *str);

/**
 * @brief Joins two strings in a single one.
 *
 * @details This function creates a new string from joining two strings.
 *
 * @param str The first string that will be used to create the new string.
 * @param str2 The string that will be used to calculate the length.
 *
 * @return - The new string created by joining str and str2.
 * @return - NULL if fails allocating memory for the new string.
 *
 * @note The caller is responsible for freeing the memory allocated for
 * the new string.
 */
char				*ft_strjoin(const char *str, const char *str2);

/**
 * @brief Compare the first 'bytes' characters of two strings.
 *
 * @details This function compares the first bytes characters of the
 * strings str and str2. The comparison is case-sensitive, and the result
 * is based on the difference between the ASCII values of the characters
 * at the corresponding positions in the strings.
 *
 * @param str Pointer to the first string to be compared.
 * @param str2 Pointer to the second string to be compared.
 * @param bytes Number of characters to compare.
 *
 * @return - An integer greater than, equal to, or less than 0 if the
 * first bytes characters of str2, respectively.
 * @return - -1 if either str or str2 is NULL.
 */
int					ft_strncmp(const char *str, const char *str2, size_t bytes);

/**
 * @brief Convert a string to an integer.
 *
 * @details This function converts the initial portion of the string str
 * to its integer representation. The conversion stops when the first
 * non-digit character is encountered. Leading white-space characters
 * are skipped, and the sign of the number is determined by an optional '+'
 * or '-' prefix.
 *
 * @param str Pointer to the string to be converted.
 *
 * @return - The converted integer value.
 *
 * @note If the string is not a valid integer representation, the behavior
 * is undefined.
 */
int					ft_atoi(const char *str);

/**
 * @brief Convert a string to an long integer.
 *
 * @details This function converts the initial portion of the string str
 * to its integer representation. The conversion stops when the first
 * non-digit character is encountered. Leading white-space characters
 * are skipped, and the sign of the number is determined by an optional '+'
 * or '-' prefix.
 *
 * @param str Pointer to the string to be converted
 *
 * @return - The converted long integer value.
 *
 * @note If the string is "-9223372036854775808", the function returns
 * -9223372036854775807LL - 1 to avoid an unsigned integer constant
 * warning.
 * @note If the string is not a valid long integer representation, the
 * behavior is undefined.
 */
long int			ft_atol(const char *str);

/**
 * @brief Duplicate a string.
 *
 * This function allocates memory for a new string and copies the content
 * of the input string str to the newly allocated memory.
 *
 * @param str Pointer to the string to be duplicated.
 *
 * @return - A pointer to the newly allocated string with the same content
 * as str.
 * @return - NULL if str is NULL or if memory allocation fails.
 *
 * @note The duplicated string is dynamically allocated and should be
 * freed by the caller when no longer needed.
 */
char				*ft_strdup(const char *str);

/**
 * @brief Copies up to bytes - 1 characters from the string str2 to str,
 * ensuring null-termination.
 *
 * @details This function copies characters from the string str2 to str,
 * ensuring null-termination. If str is large enough to accomodate bytes
 * characters, it returns the total length of the concatenated strings
 * str and str2. If str is not large enough, it returns the length of
 * str2 + bytes.
 *
 * @param str The destination string.
 * @param str2 The source string to be copied.
 * @param bytes The maximum number of characters to copy, including
 * the null-terminator.
 *
 * @return - The total length of the concatenated strings str and str2
 * if successful.
 * @return - The length of str2 + bytes if str is not large enough.
 * @return - 0 if either str or str2 is NULL.
 */
size_t				ft_strlcpy(char *str, const char *str2, size_t bytes);

/**
 * @brief Concatenates two strings with a specified buffer size.
 *
 * @details This function appends the contents of the null -terminated
 * string str2 to the end of the null-terminated string str, ensuring
 * that the total length does not exceed the given buffer size. The
 * resulting string in str is null-terminated.
 *
 * @param str A pointer to the destination null-terminated string.
 * @param str2 A pointer to the source null-terminated string to
 * be appennded.
 * @param bytes The size of the buffer, indicating the maximum
 * allowed length for the resulting string in str.
 *
 * @return - The total length of the concatenated strings (excluding
 * the null terminator) if the operation is successful.
 * @return - 0 if either str or str is NULL.
 */
size_t				ft_strlcat(char *str, const char *str2, size_t bytes);

/**
 * @brief Locates the first occurrence of a substring within a given
 * number of bytes.
 *
 * @details This function searches for the first occurrence of the
 * substring str2 within the first bytes characters of the string
 * str. The comparison is case-sensitive.
 *
 * @param str The string to be searched.
 * @param str2 The substring to search for.
 * @param bytes The maximum number of bytes to search in the string.
 *
 * @return - A pointer to the first occurrence of str2 in str within
 * the specified number of bytes.
 * @return - NULL if str or str2 is NULL or if the substring is not
 * found.
 *
 * @note If str2 is an empty string, the function returns a pointer
 * to str.
 */
char				*ft_strnstr(const char *str, const char *str2,
						size_t bytes);

/**
 * @brief Locates the first occurrence of a character in a string.
 *
 * @details Locates the first occurrence of the specified character
 * (converted to unsigned char) in the given string. The search
 * includes the null terminating character.
 *
 * @param str The string to be searched.
 * @param character The character to be located.
 *
 * @return - A pointer to the located character in the string.
 * @return - NULL if the character is not found or if the input
 * string is NULL.
 *
 */
char				*ft_strchr(const char *str, int character);

/**
 * @brief Locates the last occurrence of a character in a string.
 *
 * @details This function searches the string pointed to by str for
 * the last occurrence of the specified character (converted to an
 * unsigned char) within the string, including the terminating
 * null character.
 *
 * @param str A pointer to the null-terminated string to be searched.
 * @param character The character to be located (as an integer).
 *
 * @return - A pointer to the last occurrence of the character in
 * the string.
 * @return - NULL if the character is not found or if str is NULL.
 */
char				*ft_strrchr(const char *str, int character);

/**
 * @brief Create a substring from a given string.
 *
 * @details This function creates a substring from the input string,
 * starting at the specified index and with the specified number of
 * bytes. The returned substring is allocated dynamically and should
 * be freed by the caller when no longer needed.
 *
 * @param str The input string.
 * @param start The starting index of the substring.
 * @param bytes The number of bytes in the substring.
 *
 * @return - A dynamically allocated substring.
 * @return - NULL if memory allocation fails or if the input is NULL.
 *
 * @note The substring is dynamically allocated and should be
 * freed by the caller when no longer needed.
 */
char				*ft_substr(const char *str, size_t start, size_t bytes);

/**
 * @brief Trim characters from the beginning and end of a string..
 *
 * @details This function trims characters from the beginning and
 * end of str based on the characters provided in the second string.
 *
 * @param str The input string.
 * @param str2 The characters to trim from the string.
 *
 * @return - A dinamically allocated trimmed string.
 * @return - NULL if memory allocation fails or if either str or
 * str2 is NULL.
 *
 * @note The trimmed string is dynamically allocated and should be
 * freed by the caller when no longer needed.
 */
char				*ft_strtrim(const char *str, const char *str2);

/**
 * @brief Applies a function to each character of a string , creating
 * a new string.
 *
 * @details This function applies the provided function f to each
 * character of the string str along with its index. The result
 * is a new dynamically allocated string that contains the modified
 * characters.
 *
 * @param str The input string.
 * @f A function taking an unsigned integer index and a character
 * as parameters, and returning a modified character.
 *
 * @return - A dynamically allocated string with the modified
 * characters.
 * @return - NULL if memory allocation fails or if the input string
 * or function is NULL.
 *
 * @note The resulting string is dynamically allocated and should
 * be freed by the caller when no longer needed.
 */
char				*ft_strmapi(const char *str, char (*f)(unsigned int, char));

/**
 * @brief Apply a function to each character of a string with its index.
 *
 * @details This function iterates through each character of str along
 * with its index and applies the provided function f. The index and a
 * pointer to the current character are passed as arguments to the function f.
 *
 * @param str The input string.
 * @param f A function taking an unsigned integer index and a pointer to a
 * character, and performing an operation on the character.
 *
 * @note If the input string or function pointer is NULL, the functions does
 * nothing.
 */
void				ft_striteri(char *str, void (*f)(unsigned int, char *));

/**
 * @brief Converts an integer to its string representation.
 *
 * @details This function converts the given integer to its string
 * representation and returns a dynamically allocated string.
 *
 * @param number The integer to convert.
 *
 * @return - A dynamically allocated string representation of the
 * integer.
 * @return - NULL if the memory allocation fails.
 *
 * @note The resulting string is dynamically allocated and should
 * be freed by the caller when no longer needed.
 */
char				*ft_itoa(int number);

/**
 * @brief Splits a string into an array of substrings based on a
 * specified character.
 *
 * @details The function takes a string and a character as input
 * and splits the string into an array of substrings using the
 * specified character as the delimiter.
 *
 * @param str The input string to be split.
 * @param character The character used as the delimiter for splitting
 * the string.
 *
 * @return - A dynamically allocated array of strings representing
 * the substrings.
 * @return - NULL if memory allocation fails or if str is NULL.
 *
 * @note The returned array of strings is terminated by a NULL pointer.
 * It is the caller's responsibility to free the memory allocated for
 * both the array and its elements.
 */
char				**ft_split(const char *str, char character);

/**
 * @brief Calculate the length of a null-terminated array of strings.
 *
 * @details This function takes a null-terminated array of strings,
 * commonly obtained through string splitting, and calculates the
 * total number of strings in the array.
 *
 * @param split Null-terminated array of strings.
 *
 * @return The total number of strings in the array (excluding the null
 * terminator).
 * @return 0 If the input is NULL.
 *
 * @note The function assumes that the input array is null-terminated
 * and ends with a NULL pointer.
 */
size_t				ft_splitlen(char **split);
/* ==========================================================================*/

#endif
