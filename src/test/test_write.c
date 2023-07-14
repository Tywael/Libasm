#include "test.h"
#include <fcntl.h>

static int test_write(int fd, char *buf, size_t nbyte) {
    clock_t start;
    clock_t end;
    ssize_t ret;
    ssize_t ret2;
    double time_spent;
    double time_spent2;

    start = clock();
    ret = ft_write(fd, buf, nbyte);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    ret2 = write(fd, buf, nbyte);
    end = clock();
    time_spent2 = (double)(end - start) / CLOCKS_PER_SEC;

    if (g_verbose) {
        printf("Test ft_write with arg: %i, %s, %li\n", fd, buf, nbyte);
        printf("ft_write(\"%i, %s, %li\") =\t%li\n", fd, buf, nbyte, ret);
        printf("write(\"%i, %s, %li\") =\t%li\n", fd, buf, nbyte, ret2);
        printf("Time ft_write:\t%f\n", time_spent);
        printf("Time write:\t%f\n\n", time_spent2);
    }
    return (ret == ret2) ? 0 : 1;
}

int write_normal() {
    int ret = 0;
    int fd = open("test_folder/test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    ret = test_write(fd, "Hello world", 11);
    close(fd);
    return (ret);
}

int write_stdout() {
    int ret = 0;
    int fd = 1;

    ret = test_write(fd, "Test stdout", 11);
    return (ret);
}

int write_bad_fd() {
    int ret = 0;
    int fd = -1;

    ret = test_write(fd, "Hello world", 11);
    return (ret);
}

int all_write() {
    int ret = 0;
    if (g_verbose)
        printf("Test ft_write:\n------------------------\n\n");
    ret += result_test(write_normal, "write normal");
    ret += result_test(write_stdout, "write stdout");
    ret += result_test(write_bad_fd, "write bad fd");

    return (ret);
}