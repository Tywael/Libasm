#ifndef LIBASM_H
#define LIBASM_H

#include <stddef.h> // For size_t
#include <sys/types.h> // For ssize_t

// Function to calculate the length of a string
size_t ft_strlen(char const *str);

// Function to compare two strings
int ft_strcmp(char const *s1, char const *s2);

// Function to copy a string
char *ft_strcpy(char *dst, char const *src);

// Function to write data to a file descriptor
ssize_t ft_write(int fd, void const *buf, size_t nbyte);

// Function to read data from a file descriptor
ssize_t ft_read(int fd, void *buf, size_t nbyte);

// Function to duplicate a string
char *ft_strdup(char const *s1);

#endif /* LIBASM_H */
